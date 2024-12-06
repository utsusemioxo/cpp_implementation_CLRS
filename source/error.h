#pragma once
#include <string>

namespace clrs {

constexpr int RET_OK = 0;
constexpr int RET_ERROR = 0;

struct Error {
  int code;
  std::string messange;
};
} // namespace clrs