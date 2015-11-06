#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#include "nan.h"
using namespace v8;

#ifdef _WIN32
void PlatformSetPosition(const int x, const int y);
POINT PlatformGetPosition();
#endif

void CommonInit();
void PlatformInit();
NAN_METHOD(SetCallback);
NAN_METHOD(SetPosition);
NAN_METHOD(GetPosition);

#endif  // SRC_COMMON_H_