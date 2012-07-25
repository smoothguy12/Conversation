#ifndef BUTTON_HXX
#define BUTTON_HXX
#include "widget.hxx"

namespace UI
{
  class Button : public Widget
  {
  public:
    void handle(sf::Event& event);
    virtual void onClick() = 0;
    virtual void onRelease() = 0;
  };
}

#endif // BUTTON_HXX
