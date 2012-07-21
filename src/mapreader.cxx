#include "mapreader.hxx"
#include "reader.hxx"
#include <string>
#include <vector>
#include "log.hxx"

namespace Core
{
  MapReader::MapReader(std::string filename) : Reader(filename)
  {
    std::vector<std::string>            keys;
    std::vector<std::string>::iterator  itk;

    if (m_content.isObject() and !m_content.empty())
      {
        keys    = m_content.getMemberNames();
        m_valid = true;

        for (itk = keys.begin(); itk != keys.end(); itk++)
          {
            if (m_content[*itk].isString())
              {
                m_map[*itk] = m_content[*itk].asString();
              }
          }
      }
    else
      {
        log::putln(log::error, "Invalid structure for file " + filename);
      }

    keys.clear();

    log::putln(log::message, "Initialized Core::MapReader");
  }

  MapReader::~MapReader()
  {
    m_map.clear();

    log::putln(log::message, "Destroyed Core::MapReader");
  }

  std::map<std::string, std::string>& MapReader::get()
  {
    return m_map;
  }
}
