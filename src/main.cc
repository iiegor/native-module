#include "common.h"

namespace {

void Init(Handle<Object> exports) {
  CommonInit();
  PlatformInit();

  Nan::SetMethod(exports, "setCallback", SetCallback);
  Nan::SetMethod(exports, "setPosition", SetPosition);
}

}  // namespace

NODE_MODULE(mouse, Init)
