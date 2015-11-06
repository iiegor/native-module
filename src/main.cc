#include "common.h"

namespace {

void Init(Handle<Object> exports) {
  Nan::SetMethod(exports, "setCallback", SetCallback);
  Nan::SetMethod(exports, "setPosition", SetPosition);
  Nan::SetMethod(exports, "getPosition", GetPosition);
  Nan::SetMethod(exports, "watch", Watch);
}

}  // namespace

NODE_MODULE(mouse, Init)
