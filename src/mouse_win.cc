#include "common.h"

#include <windows.h>

void PlatformInit() { }

NAN_METHOD(SetPosition) {
  Nan::HandleScope scope;

  /**
   * Check arguments type
   */
  /*if (!info[0]->IsInteger() || !info[1]->IsInteger())
    return Nan::ThrowTypeError("Integer requried");*/

  SetCursorPos(12, 12);

  return;
}