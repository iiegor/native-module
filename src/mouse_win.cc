#include "common.h"

#include <windows.h>

void PlatformInit() { }

void PlatformSetPosition(const int x, const int y) {
  SetCursorPos(x, y);
}