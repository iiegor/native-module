#include "common.h"

#include <windows.h>

void PlatformSetPosition(const int x, const int y) {
  SetCursorPos(x, y);
}

POINT PlatformGetPosition() {
  POINT pt;
  GetCursorPos(&pt);

  return pt;
}

void PlatformWatch(uint32_t sleep_time) {
  POINT lastPt = PlatformGetPosition();

  /**
   * Watch for idle
   */
  while (true) {
    Sleep(sleep_time);

    POINT pt = PlatformGetPosition();

    if (pt.x == lastPt.x && pt.y == lastPt.y) {
      EVENT_TYPE event = EVENT_IDLE;

      PostEvent(event);
    }
    else
    {
      lastPt = pt;
    }
  }
}