#include "common.h"

namespace {

void Init(Handle<Object> exports) {
  CommonInit();

  Nan::SetMethod(exports, "mouse", Mouse);
}

}  // namespace

NODE_MODULE(mouse, Init)
