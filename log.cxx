#include "log.hxx"
#include <iostream>
#include <string>
#define ERRLVL 6


namespace log
{
  void put(unsigned int err_lvl, std::string str)
  {
    std::string prefix;

    if (err_lvl <= ERRLVL and err_lvl > 0)
      {
        switch (err_lvl)
          {
          case log::fatal: prefix = "!!! FATAL"; break;
          case log::error: prefix = "/!\\ ERROR"; break;
          case log::warning: prefix = "--- WARNING"; break;
          default: prefix = "";
          }

        if (!prefix.empty())
          std::cout << prefix + ": ";

        std::cout << str;
      }
  }



  void putln(unsigned int err_lvl, std::string str)
  {
    if (err_lvl <= ERRLVL and ERRLVL > 0)
      {
        put(err_lvl, str + "\n");
      }
  }
}
