#include "common.h"

namespace {

void Init(Handle<Object> exports) {
  CommonInit();

  Nan::SetMethod(exports, "app", App);
}

}  // namespace

NODE_MODULE(app, Init)
