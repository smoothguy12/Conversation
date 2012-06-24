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
    parsed      = reader.parse(fin, m_content);

    if (!parsed)
      {
        log::write(log::error, "Failed to parse " + filename + " " + reader.getFormattedErrorMessages());
      }

    log::write(log::message, "Initialized Core::Reader");
  }

  Reader::~Reader()
  {
    log::write(log::message, "Destroyed Core::Reader");
  }

  Json::Value& Reader::get()
  {
    if (m_content.empty())
      {
        log::write(log::warning, m_filename + " is empty");
      }
    return (m_content);
  }
}
