#include "widget.hxx"
#include "container.hxx"
#include <iostream>

namespace UI
{
  Widget::Widget()
  {
    m_sprite = new sf::Sprite();
    m_zorder = -1;
    m_focused = false;
  }



  Widget::~Widget()
  {
    delete m_sprite;
  }



  void Widget::setZOrder(int zorder)
  {
    m_zorder = zorder;
  }



  void Widget::increaseZOrder()
  {
    m_zorder++;
  }



  void Widget::decreaseZOrder()
  {
    m_zorder--;
  }



  void Widget::gainFocus()
  {
    m_focused = true;
  }



  void Widget::loseFocus()
  {
    m_focused = false;
  }



  void Widget::handle(sf::Event& event)
  {
    std::cout << "Handling " << event.type << "\n";
  }



  void Widget::move(float x, float y)
  {
    m_sprite->move(x, y);
  }



  void Widget::move(sf::Vector2f coords)
  {
    m_sprite->move(coords);
  }



  sf::Drawable* Widget::getDrawable()
  {
    return static_cast<sf::Drawable*>(m_sprite);
  }



  sf::Vector2u Widget::getSize()
  {
    sf::FloatRect rect;
    sf::Vector2u  size;

    rect    = m_sprite->getGlobalBounds();
    size.x  = (rect.left + rect.width);
    size.y  = (rect.top + rect.height);

    return size;
  }



  const int& Widget::getZOrder()
  {
    return m_zorder;
  }
}
