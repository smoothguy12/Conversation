#ifndef BUTTON_HXX
#define BUTTON_HXX
#include "widget.hxx"

namespace UI
{
  class Button : public Widget
  {
  public:
    Button();
    void handle(sf::Event& event);
    virtual void onPush();
    virtual void onRelease();
    virtual void onClick() = 0;
    virtual void onResign() = 0;
    void onFocusGained();
    void onFocusLost();

  protected:
    bool m_pushed;
  };
}

#endif // BUTTON_HXX
