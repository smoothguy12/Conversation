#ifndef FONTMANAGER_HXX
#define FONTMANAGER_HXX
#include "singleton.hxx"
#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>

namespace GUI
{
  namespace Font
  {
    enum Style {
      Standard,
      Title
    };
  }
}



namespace Core
{
  class FontManager : public Singleton<FontManager>
  {
  public:
    friend class Singleton<FontManager>;
    sf::Font& get(GUI::Font::Style type);

  private:
    FontManager();
    ~FontManager();

    std::map<std::string, sf::Font> m_fonts;
  };
}

#endif // FONTMANAGER_HXX
