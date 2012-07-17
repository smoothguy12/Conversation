#ifndef TEXT_HXX
#define TEXT_HXX
#include <SFML/Graphics/Text.hpp>

namespace GUI
{
  class Text
  {
  public:
    enum Type {
      Standard,
      Section,
      Title,
      Legend
    };

    Text(std::string text, Text::Type type, sf::Vector2f pos);
    ~Text();
    sf::Text*     get();
    sf::Drawable* getDrawable();

  private:
    void          buildStandard();
    void          buildSection();
    void          buildTitle();
    void          buildLegend();
    sf::Text*     m_text;
  };
}

#endif // TEXT_HXX
