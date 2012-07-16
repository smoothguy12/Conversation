#include "log.hxx"
#include <iostream>
#define ERRLVL 6


namespace log
{
  void write(unsigned int err_lvl, std::string str)
  {
    if (err_lvl <= ERRLVL and ERRLVL > 0)
      {
        std::cout << str << std::endl;
      }
  }

  void insert(unsigned int err_lvl, std::string str)
  {
    if (err_lvl <= ERRLVL and err_lvl > 0)
      {
        std::cout << str;
      }
  }
}
