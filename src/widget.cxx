#include "widget.hxx"

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



  const int& Widget::getZOrder()
  {
    return m_zorder;
  }



  sf::Sprite* Widget::get()
  {
    return m_sprite;
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
}
