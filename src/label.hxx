#ifndef LABEL_HXX
#define LABEL_HXX
#include "widget.hxx"
#include <string>
#include "text.hxx"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace UI
{
  class Label : public Widget
  {
  public:
    Label(std::string text, Text::Type type = Text::Standard);
    ~Label();
    void move(float x, float y);
    void move(sf::Vector2f coords);
    sf::Drawable* getDrawable();
    sf::Vector2u getSize();

  private:
    void buildStandard();
    void buildSection();
    void buildTitle();
    void buildLegend();

    sf::Text* m_text;
  };
}

#endif // LABEL_HXX
