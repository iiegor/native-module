#include "app.h"
#include <windows.h>

namespace app {

bool App(const std::string& command, int* code) {
  *code = 2;

  return true;
}

} // namespace