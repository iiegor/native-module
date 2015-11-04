#include "common.h"

// Move to mouse_win.cc
#include <windows.h>

void CommonInit() { }

NAN_METHOD(Watch) {
  Nan::HandleScope scope;

  /**
   * Arguments
   * @desc Check if the first argument is a string.
   */
  if (!info[0]->IsString())
    return Nan::ThrowTypeError("String required");

  /**
   * Convert first argument to string
   */
  std::string command(*String::Utf8Value(info[0]));
  int exit_code = -1;

  /**
   * Create an object and set the code value
   */
  Local<Object> result = Nan::New<Object>();
  result->Set(
    Nan::New<String>("command").ToLocalChecked(),
    Nan::New<String>(command).ToLocalChecked());
  result->Set(
    Nan::New<String>("exitCode").ToLocalChecked(),
    Nan::New<Integer>(exit_code)); 

  /**
   * Return the previously created object
   */
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SetPosition) {
  Nan::HandleScope scope;

  /**
   * Check arguments type
   */
  /*if (!info[0]->IsInteger() || !info[1]->IsInteger())
    return Nan::ThrowTypeError("Integer requried");*/

  SetCursorPos(12, 12);

  return;
}
