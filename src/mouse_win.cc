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

void PlatformClick(int type)
{  
  INPUT Input = {0};

  switch (type) {
    case 1:
      // left down 
      Input.type = INPUT_MOUSE;
      Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
      ::SendInput(1, &Input, sizeof(INPUT));

      // left up
      ::ZeroMemory(&Input, sizeof(INPUT));
      Input.type = INPUT_MOUSE;
      Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
      ::SendInput(1, &Input, sizeof(INPUT));
      break;
    case 2:
      // right down 
      Input.type = INPUT_MOUSE;
      Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
      ::SendInput(1, &Input, sizeof(INPUT));

      // right up
      ::ZeroMemory(&Input, sizeof(INPUT));
      Input.type = INPUT_MOUSE;
      Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
      ::SendInput(1, &Input, sizeof(INPUT));
      break;
  }
}

void PlatformWatch(uint32_t sleep_time) {
  POINT lastPt, pt;

  /**
   * Watch for idle
   */
  while (true) {
    Sleep(sleep_time);

    pt = PlatformGetPosition();

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