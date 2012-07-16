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
    const Json::Value&  get();
    bool isValid();

  protected:
    std::string   m_filename;
    Json::Value   m_content;
    bool          m_valid;
  };
}

#endif // READER_HXX
