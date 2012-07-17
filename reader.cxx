#include "reader.hxx"
#include <fstream>
#include "log.hxx"


namespace Core
{
  Reader::Reader(std::string filename)
  {
    Json::Reader  reader;
    std::ifstream fin(filename.c_str());
    bool          parsed;

    m_filename  = filename;
    m_valid     = false;
    parsed      = reader.parse(fin, m_content);

    if (!parsed)
      {
        log::putln(log::error, "Failed to parse " + filename + " " + reader.getFormattedErrorMessages());
      }

    if (!m_content.empty())
      {
        m_valid = true;
      }

    log::putln(log::message, "Initialized Core::Reader");
  }



  Reader::~Reader()
  {
    log::putln(log::message, "Destroyed Core::Reader");
  }



  const Json::Value& Reader::get()
  {
    return m_content;
  }

  bool Reader::isValid()
  {
    return m_valid;
  }
}
