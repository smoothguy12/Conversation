#include "settings.hxx"
#include "log.hxx"
#include "reader.hxx"

namespace Core
{
  Settings::Settings()
  {
    m_reader = new Reader("data/settings.json");
    m_content = m_reader->get();
    log::write(log::message, "Initialized Core::Settings");
  }

  Settings::~Settings()
  {
    delete(m_reader);
    log::write(log::message, "Destroyed Core::Settings");
  }

  template<>
  int Settings::get<int>(std::string key)
  {
    if (!m_content.isMember(key))
      {
        log::write(log::error, "Core::Settings: Couldn't find key (" + key + ")");
        return (-1);
      }
    else
      {
        return (m_content.get(key, -1).asInt());
      }
  }

  template<>
  std::string Settings::get<std::string>(std::string key)
  {
    if (!m_content.isMember(key))
      {
        log::write(log::error, "Core::Settings: Couldn't find key (" + key + ")");
        return ("STR NOT FOUND");
      }
    else
      {
        return (m_content.get(key, "STR NOT FOUND").asString());
      }
  }

  template<>
  bool Settings::get<bool>(std::string key)
  {
    if (!m_content.isMember(key))
      {
        log::write(log::error, "Core::Settings: Couldn't find key (" + key + ")");
        return (false);
      }
    else
      {
        return (m_content.get(key, false).asBool());
      }
  }
}
