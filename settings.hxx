#ifndef SETTINGS_HXX
#define SETTINGS_HXX
#include <jsoncpp/value.h>
#include "singleton.hxx"
#include "reader.hxx"

namespace Core
{
  class Settings : public Singleton<Settings>
  {
  public:
    friend class Singleton<Settings>;
    template<typename T>
    T           get(std::string key);

  private:
    Settings();
    ~Settings();

    Reader*     m_reader;
    Json::Value m_content;
  };

  template<>
  int Settings::get<int>(std::string key);

  template<>
  std::string Settings::get<std::string>(std::string key);
}

#endif // SETTINGS_HXX
