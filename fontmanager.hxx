#ifndef FONTMANAGER_HXX
#define FONTMANAGER_HXX
#include "singleton.hxx"
#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>

namespace Core
{
  class FontManager : public Singleton<FontManager>
  {
  public:
    friend class Singleton<FontManager>;
    sf::Font& get(std::string& type);

  private:
    FontManager();
    ~FontManager();

    std::map<std::string, sf::Font> m_fonts;
  };
}

#endif // FONTMANAGER_HXX
