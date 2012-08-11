#ifndef TEXT_HXX
#define TEXT_HXX
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace UI
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

    ~Text();

  protected:
    Text(std::string text, Text::Type type = Text::Standard);
    void buildStandard();
    void buildSection();
    void buildTitle();
    void buildLegend();
    void updateTexture();

    sf::Text*           m_text;
    sf::RenderTexture*  m_rt;
  };
}

#endif // TEXT_HXX
