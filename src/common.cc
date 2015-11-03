#include "common.h"

void CommonInit() { }

NAN_METHOD(App) {
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

  /**
   * Create an object and set the code value
   */
  Local<Object> result = Nan::New<v8::Object>();
  result->Set(
    Nan::New<v8::String>("command").ToLocalChecked(),
    Nan::New<v8::String>(command).ToLocalChecked());
  result->Set(
    Nan::New<v8::String>("code").ToLocalChecked(),
    Nan::New<v8::Integer>(1));

  /**
   * Return the previously created object
   */
  info.GetReturnValue().Set(result);
}