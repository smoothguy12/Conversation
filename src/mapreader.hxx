#ifndef MAPREADER_HXX
#define MAPREADER_HXX
#include "reader.hxx"
#include <string>

namespace Core
{
  class MapReader : public Reader
  {
  public:
    MapReader(std::string filename);
    ~MapReader();
    std::map<std::string, std::string>& get();

  private:
    std::string                         m_filename;
    std::map<std::string, std::string>  m_map;
  };
}

#endif // MAPREADER_HXX
