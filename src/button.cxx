#include "button.hxx"
#include "log.hxx"

namespace UI
{
  Button::Button()
  {
    m_pushed = false;
  }



  void Button::handle(sf::Event& event)
  {
    Widget::handle(event);

    if (event.type == sf::Event::MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left)
      {
        if (m_mouseOver)
          {
            m_pushed = true;
            this->onPush();
          }
        else
          {
            m_pushed = false;
            this->onRelease();
          }
      }
    else if (event.type == sf::Event::MouseButtonReleased
             && event.mouseButton.button == sf::Mouse::Left
             && m_pushed)
      {
        if (m_mouseOver)
          {
            this->onClick();
            this->onRelease();
          }
        else
          {
            this->onResign();
          }
      }
  }



  void Button::onPush()
  {
  }



  void Button::onRelease()
  {
  }


  void Button::onFocusGained()
  {
  }



  void Button::onFocusLost()
  {
  }
}
