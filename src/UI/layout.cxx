#include "layout.hxx"
#include "log.hxx"
#include "Core/reader.hxx"
#include <jsoncpp/value.h>

namespace UI
{
  Layout::Layout()
  {
    m_hasColors = false;
    m_initialized = false;

    log::putln(log::message, "Initialized UI::Layout");
  }



  Layout::~Layout()
  {
    log::putln(log::message, "Destroyed UI::Layout");
  }



  void Layout::loadColors(std::string fileName)
  {
    Core::Reader  reader = Core::Reader(fileName);
    Json::Value   content;
    unsigned int  index;
    bool          loaded;

    content = reader.get();
    loaded  = false;

    if (!reader.isValid())
      {
        log::putln(log::fatal, "Invalid colors file.");
        return ;
      }

    if (content.isArray())
      {
        log::put(log::trivial, "Loading (Colors)... ");

        for (index = 0; index < content.size(); index++)
          {
            if (content[index]["name"].isString()
                && content[index]["r"].isInt()
                && content[index]["g"].isInt()
                && content[index]["b"].isInt()
                && content[index]["a"].isInt())
              {
                sf::Color color = sf::Color(content[index]["r"].asInt(),
                                            content[index]["g"].asInt(),
                                            content[index]["b"].asInt(),
                                            content[index]["a"].asInt());

                m_colors[ content[index]["name"].asString() ] = color;
              }
            else
              {
                log::putln(log::trivial, "Fail!");
                return ;
              }
          }
      }

    log::putln(log::trivial, "Ok!");

    if (loaded)
      m_hasColors = true;
    else
      m_hasColors = false;
  }



  const sf::Color& Layout::getColor(std::string name)
  {
    if (m_hasColors)
      {
        std::map<std::string, sf::Color>::iterator itr;

        itr = m_colors.find(name);

        if (itr == m_colors.end())
          {
            log::putln(log::warning, "Color " + name + " not found!");

            return sf::Color::Magenta;
          }
        else
          return itr->second;
      }
    else
      {
        log::putln(log::warning, "Colors are not initialized!");

        return sf::Color::Magenta;
      }
  }
}
