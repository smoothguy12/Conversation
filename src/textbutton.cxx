#include "textbutton.hxx"
#include "log.hxx"

namespace UI
{
  TextButton::TextButton(std::string text) : Text(text, Text::Standard)
  {
    this->updateTexture();
  }



  void TextButton::handle(sf::Event &event)
  {
    Button::handle(event);

    if (event.type == sf::Event::MouseMoved)
      {
        if (m_widget->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          {
            m_text->setColor(sf::Color::Blue);
          }
        else
          {
            m_text->setColor(sf::Color::White);
          }

        this->updateTexture();
      }
  }



  void TextButton::updateTexture()
  {
    Text::updateTexture();

    m_widget->setTexture(m_rt->getTexture(), true);
  }



  void TextButton::onClick()
  {
    m_text->setColor(sf::Color::Black);

    log::putln(log::trivial, "Click !");

    this->updateTexture();
  }



  void TextButton::onRelease()
  {
    m_text->setColor(sf::Color::White);

    log::putln(log::trivial, "Release !");

    this->updateTexture();
  }
}
