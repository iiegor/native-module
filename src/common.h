#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#include "nan.h"
using namespace v8;

void CommonInit();
void PlatformInit();
NAN_METHOD(Watch);
NAN_METHOD(SetPosition);

#endif  // SRC_COMMON_H_