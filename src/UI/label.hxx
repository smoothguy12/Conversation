#ifndef LABEL_HXX
#define LABEL_HXX
#include "widget.hxx"
#include <string>
#include "text.hxx"

namespace UI
{
  class Label : public Widget, public Text
  {
  public:
    Label(std::string text, Text::Type type = Text::Standard);
    ~Label();
    void handle(sf::Event& event);
    void updateTexture();
  };
}

#endif // LABEL_HXX
