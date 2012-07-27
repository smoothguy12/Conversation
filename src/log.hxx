#ifndef LOG_HXX
#define LOG_HXX
#include <iostream>
#include <string>
#define ERRLVL 6

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

  template<typename T>
  void put(unsigned int err_lvl, T value);

  template<typename T>
  void putln(unsigned int err_lvl, T value);



  template<typename T>
  void put(unsigned int err_lvl, T value)
  {
    std::string prefix;

    if (err_lvl <= ERRLVL and err_lvl > 0)
      {
        switch (err_lvl)
          {
          case log::fatal:    prefix = "!!! FATAL";   break;
          case log::error:    prefix = "/!\\ ERROR";  break;
          case log::warning:  prefix = "--- WARNING"; break;
          default:            prefix = "";
          }

        if (!prefix.empty())
          std::cout << prefix + ": ";

        std::cout << value;
      }
  }



  template<typename T>
  void putln(unsigned int err_lvl, T value)
  {
    if (err_lvl <= ERRLVL and ERRLVL > 0)
      {
        put(err_lvl, value);
        std::cout << std::endl;
      }
  }
}

#endif // LOG_HXX
