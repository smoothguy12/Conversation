#include "label.hxx"
#include <SFML/Graphics/Font.hpp>
#include "log.hxx"

namespace UI
{
  Label::Label(std::string text, Text::Type type) : Text(text, type)
  {
    this->updateTexture();
  }



  Label::~Label()
  {
  }



  void Label::handle(sf::Event& event)
  {
    Widget::handle(event);
  }



  void Label::updateTexture()
  {
    Text::updateTexture();

    m_widget->setTexture(m_rt->getTexture(), true);
  }
}
