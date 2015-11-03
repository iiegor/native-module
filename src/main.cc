#include "nan.h"
using namespace v8;

#include "app.h"

namespace {

inline

void App(const Nan::FunctionCallbackInfo<Value>& info) {
  /**
   * Create an object
   * {exitCode: 1}
   */
  Local<Object> result = Nan::New<Object>();
  Nan::Set(
    result,
    Nan::New<String>("exitCode").ToLocalChecked(),
    Nan::New<Integer>(1)
  );

  /**
   * Return the previously created object
   */
  info.GetReturnValue().Set(result);
}

void Init(Handle<Object> exports) {
  Nan::SetMethod(exports, "app", App);
}

} // namespace

NODE_MODULE(app, Init)