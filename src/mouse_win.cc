#include "common.h"

#include <windows.h>

void PlatformInit() { }

NAN_METHOD(SetPosition) {
  Nan::HandleScope scope;

  /**
   * Check arguments type
   */
  if (!info[0]->IsUint32() || !info[1]->IsUint32())
    return Nan::ThrowTypeError("A number is required");

  /**
   * Set cursor position using given coords
   */
  SetCursorPos(info[0]->Uint32Value(), info[1]->Uint32Value());

  return;
}