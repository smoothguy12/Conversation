#include "button.hxx"
#include "log.hxx"

namespace UI
{
  void Button::handle(sf::Event& event)
  {
    if (event.type == sf::Event::MouseMoved)
      {
        if (m_widget->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
            m_mouseOver = true;
          }
        else
          {
            m_mouseOver = false;
          }
      }

    if (event.type == sf::Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == sf::Mouse::Left && m_mouseOver)
          {
            m_focused = true;

            this->onClick();
          }
      }
    else if (event.type == sf::Event::MouseButtonReleased
             && event.mouseButton.button == sf::Mouse::Left
             && m_focused)
      {
        m_focused = false;

        this->onRelease();
      }
  }
}
