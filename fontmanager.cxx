#include "fontmanager.hxx"
#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>
#include "mapreader.hxx"
#include "log.hxx"

namespace Core
{
  FontManager::FontManager()
  {
    std::map<std::string, std::string> map;
    std::map<std::string, std::string>::iterator it;
    MapReader map_reader("data/System/fonts.json");

    map = map_reader.get();

    if (!map_reader.isValid())
      {
        log::putln(log::fatal, "Invalid fonts file.");
        return ;
      }

    for (it = map.begin(); it != map.end(); it++)
      {
        log::put(log::trivial, "Loading (Font) : " + it->second + "... ");

        m_fonts[it->first] = sf::Font();

        if (!m_fonts[it->first].loadFromFile("data/Fonts/" + it->second))
          {
            log::putln(log::trivial, "Fail!");
          }
        else
          {
            log::putln(log::trivial, "Ok.");
          }
      }

    log::putln(log::message, "Initialized Core::FontManager.");
  }

  FontManager::~FontManager()
  {
    m_fonts.clear();

    log::putln(log::message, "Destroyed Core::FontManager.");
  }

  sf::Font& FontManager::get(std::string& type)
  {
    std::map<std::string, sf::Font>::iterator it;

    it = m_fonts.find(type);

    if (it != m_fonts.end())
      {
        return m_fonts[type];
      }
    else
      {
        log::putln(log::fatal, "Tried to get an unknown font!");

        throw new std::string("Tried to get an unknown font!");
      }
  }
}
