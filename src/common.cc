#include "common.h"

void CommonInit() { }

NAN_METHOD(Mouse) {
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
  Local<Object> result = Nan::New<v8::Object>();
  result->Set(
    Nan::New<v8::String>("command").ToLocalChecked(),
    Nan::New<v8::String>(command).ToLocalChecked());
  result->Set(
    Nan::New<v8::String>("exitCode").ToLocalChecked(),
    Nan::New<v8::Integer>(exit_code));

  /**
   * Return the previously created object
   */
  info.GetReturnValue().Set(result);
}
