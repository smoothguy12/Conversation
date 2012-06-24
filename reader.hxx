#ifndef READER_HXX
#define READER_HXX
#include <string>
#include <jsoncpp/json.h>

namespace Core
{
  class Reader
  {
  public:
    Reader(std::string filename);
    ~Reader();
    Json::Value&  get();

  private:
    std::string   m_filename;
    Json::Value   m_content;
  };
}

#endif // READER_HXX
