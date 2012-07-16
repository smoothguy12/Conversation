#include "vectorreader.hxx"
#include "log.hxx"

namespace Core
{
  VectorReader::VectorReader(std::string filename) : Reader(filename)
  {
    Reader        reader(filename);
    Json::Value   content;
    unsigned int  index;

    content = reader.get();

    if (content.isArray() and !content.empty())
      {
        for (index = 0; index < content.size(); index++)
          {
            m_vector.push_back(content[index].asString());
          }
      }
    else
      {
        log::write(log::error, "Invalid structure for file " + filename);
      }

    log::write(log::message, "Initialized Core::Reader");
  }



  VectorReader::~VectorReader()
  {
    m_vector.clear();
    log::write(log::message, "Destroyed Core::ListReader");
  }



  std::vector<std::string>& VectorReader::get()
  {
    return m_vector;
  }
}
