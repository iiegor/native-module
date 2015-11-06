#include "common.h"

#include <windows.h>

void PlatformInit() { }

void PlatformSetPosition(const int x, const int y) {
  SetCursorPos(x, y);
}

POINT PlatformGetPosition() {
  POINT pt;
  GetCursorPos(&pt);

  return pt;
}