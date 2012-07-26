#include "label.hxx"
#include <SFML/Graphics/Font.hpp>
#include "log.hxx"

namespace UI
{
  Label::Label(std::string text, Text::Type type) : Text(text, type)
  {
    this->updateTexture();
    //    std::cout << "Text height : " << m_text->getLocalBounds().height << std::endl;
    //    std::cout << "Texture height : " << m_rt->getTexture().getSize().y << std::endl;
    //    std::cout << "Widget height : " << m_widget->getLocalBounds().height << std::endl;
  }



  Label::~Label()
  {
  }



  void Label::handle(sf::Event& event)
  {

  }



  void Label::updateTexture()
  {
    Text::updateTexture();

    m_widget->setTexture(m_rt->getTexture(), true);
  }


  /*
  void Label::move(float x, float y)
  {
    m_text->move(x, y);
  }



  void Label::move(sf::Vector2f coords)
  {
    m_text->move(coords);
  }



  sf::Drawable* Label::getDrawable()
  {
    return static_cast<sf::Drawable*>(m_text);
  }



  sf::Vector2u Label::getSize()
  {
    sf::FloatRect rect;
    sf::Vector2u  size;

    rect    = m_text->getGlobalBounds();
    size.x  = (rect.left + rect.width);
    size.y  = (rect.top + rect.height);

    return size;
  }
*/
}
