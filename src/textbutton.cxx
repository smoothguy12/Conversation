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

    this->updateTexture();
  }



  void TextButton::updateTexture()
  {
    Text::updateTexture();

    m_widget->setTexture(m_rt->getTexture(), true);
  }



  void TextButton::onPush()
  {
    m_text->setColor(sf::Color::Black);

    this->updateTexture();

    m_focused = true;
    this->onFocusGained();
  }



  void TextButton::onRelease()
  {
    m_text->setColor(sf::Color::White);

    this->updateTexture();
  }



  void TextButton::onClick()
  {
    log::putln(log::trivial, "Text Click !");
  }



  void TextButton::onResign()
  {
    log::putln(log::trivial, "Text Resign !");
  }



  void TextButton::onFocusGained()
  {
    m_text->setColor(sf::Color::Blue);

    this->updateTexture();
  }



  void TextButton::onFocusLost()
  {
    m_text->setColor(sf::Color::White);

    this->updateTexture();
  }
}
