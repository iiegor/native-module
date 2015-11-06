#include "common.h"

void CommonInit() { }

NAN_METHOD(SetCallback) {
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
  if (!info[0]->IsUint32() || !info[1]->IsUint32())
    return Nan::ThrowTypeError("Arguments must be numbers");

  /**
   * Set cursor position using given coords
   */
  PlatformSetPosition(info[0]->Uint32Value(), info[1]->Uint32Value());

  return;
}

NAN_METHOD(GetPosition) {
  Nan::HandleScope scope;

  /**
   * Get current cursor position
   */
  POINT pt = PlatformGetPosition();

  /**
   * Create an object containing x and y values
   */
  Local<Object> result = Nan::New<Object>();
  result->Set(
    Nan::New<String>("x").ToLocalChecked(),
    Nan::New<Uint32>(pt.x));
  result->Set(
    Nan::New<String>("y").ToLocalChecked(),
    Nan::New<Uint32>(pt.y));

  /**
   * Return the object
   */
  info.GetReturnValue().Set(result);
}
