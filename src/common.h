#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#include "nan.h"
using namespace v8;

enum EVENT_TYPE {
  EVENT_NONE,
  EVENT_IDLE,
};

// Platform methods
void PlatformSetPosition(const int x, const int y);
POINT PlatformGetPosition();
void PlatformWatch(uint32_t sleep_time);
void PlatformClick(int type);

// Common methods
void PostEvent(EVENT_TYPE type);

// Nan methods
NAN_METHOD(SetCallback);
NAN_METHOD(SetPosition);
NAN_METHOD(GetPosition);
NAN_METHOD(Watch);
NAN_METHOD(Click);

#endif  // SRC_COMMON_H_