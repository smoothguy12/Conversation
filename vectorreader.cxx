#include "vectorreader.hxx"
#include "log.hxx"

namespace Core
{
  VectorReader::VectorReader(std::string filename) : Reader(filename)
  {
    unsigned int  index;

    if (m_content.isArray() and !m_content.empty())
      {
        for (index = 0; index < m_content.size(); index++)
          {
            m_vector.push_back(m_content[index].asString());
          }
      }
    else
      {
        log::putln(log::error, "Invalid structure for file " + filename);
      }

    log::putln(log::message, "Initialized Core::VectorReader");
  }



  VectorReader::~VectorReader()
  {
    m_vector.clear();

    log::putln(log::message, "Destroyed Core::VectorReader");
  }



  std::vector<std::string>& VectorReader::get()
  {
    return m_vector;
  }
}
