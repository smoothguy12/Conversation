#ifndef LOG_HXX
#define LOG_HXX
#include <string>

namespace log
{
  enum {
    off = 0,
    fatal = 1,
    error = 2,
    warning = 3,
    message = 4,
    hint = 5,
    trivial = 6,
    flood = 7,
    all = 9
  };

  void write(int err_lvl, std::string str);
}

#endif // LOG_HXX
