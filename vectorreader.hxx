#ifndef VECTORREADER_HXX
#define VECTORREADER_HXX
#include "reader.hxx"
#include <vector>

namespace Core
{
  class VectorReader : public Reader
  {
  public:
    VectorReader(std::string filename);
    ~VectorReader();
    std::vector<std::string>& get();

  private:
    std::string               m_filename;
    std::vector<std::string>  m_vector;
  };
}

#endif // LISTREADER_HXX
