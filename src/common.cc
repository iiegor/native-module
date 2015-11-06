#include "common.h"

static Nan::Persistent<Function> g_callback;

void CommonInit() { }

NAN_METHOD(SetCallback) {
  Nan::HandleScope scope;

  if (!info[0]->IsFunction())
    return Nan::ThrowTypeError("Function required");

  g_callback.Reset(Local<Function>::Cast(info[0]));
  return;
}

NAN_METHOD(SetPosition) {
  Nan::HandleScope scope;

  /**
   * Check arguments type
   */
  if (!info[0]->IsUint32() || !info[1]->IsUint32())
    return Nan::ThrowTypeError("Arguments must be numbers");

  /**
   * Set cursor position using given coords
   */
  PlatformSetPosition(info[0]->Uint32Value(), info[1]->Uint32Value());

  return;
}

NAN_METHOD(GetPosition) {
  Nan::HandleScope scope;

  /**
   * Get current cursor position
   */
  POINT pt = PlatformGetPosition();

  /**
   * Create an object containing x and y values
   */
  Local<Object> result = Nan::New<Object>();
  result->Set(
    Nan::New<String>("x").ToLocalChecked(),
    Nan::New<Uint32>(pt.x));
  result->Set(
    Nan::New<String>("y").ToLocalChecked(),
    Nan::New<Uint32>(pt.y));

  /**
   * Return the object
   */
  info.GetReturnValue().Set(result);
}
