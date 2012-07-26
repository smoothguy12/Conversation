#ifndef TEXTBUTTON_HXX
#define TEXTBUTTON_HXX
#include "text.hxx"
#include "button.hxx"
#include <SFML/Graphics/RenderTexture.hpp>
#include <string>

namespace UI
{
  class TextButton : public Button, public Text
  {
  public:
    TextButton(std::string text);
    void handle(sf::Event& event);
    void updateTexture();
    void onPush();
    void onRelease();
    void onClick();
    void onResign();
    void onFocusGained();
    void onFocusLost();
  };
}

#endif // TEXTBUTTON_HXX
