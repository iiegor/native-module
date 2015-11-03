#include "nan.h"
using namespace v8;

#include "app.h"

namespace {

void App(const Nan::FunctionCallbackInfo<Value>& info) {
  /**
   * Define args
   */
  std::string command(*String::Utf8Value(info[0]));

  /**
   * Define exit code value
   * Call the platform specific handler to exec given command
   * Pass code with & to make it modificable from outside.
   */
  int code = -1;
  app::App(command, &code);

  /**
   * Create an object and set the code value
   */
  Local<Object> result = Nan::New<Object>();
  Nan::Set(
    result,
    Nan::New<String>("exitCode").ToLocalChecked(),
    Nan::New<Integer>(code));

  /**
   * Return the previously created object
   */
  info.GetReturnValue().Set(result);
}

void Init(Handle<Object> exports) {
  Nan::SetMethod(exports, "app", App);
}

}  // namespace

NODE_MODULE(app, Init)
