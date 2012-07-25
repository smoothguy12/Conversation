#include "widget.hxx"
#include "container.hxx"

namespace UI
{
  Widget::Widget()
  {
    m_widget = new sf::Sprite();
    m_zorder = -1;
    m_focused = false;
    m_mouseOver = false;

    m_widget->move(0, 0);
  }



  Widget::~Widget()
  {
    delete m_widget;
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



  void Widget::move(float x, float y)
  {
    m_widget->move(x, y);
  }



  void Widget::move(sf::Vector2f coords)
  {
    m_widget->move(coords);
  }



  sf::Drawable* Widget::getDrawable()
  {
    return static_cast<sf::Drawable*>(m_widget);
  }



  sf::Vector2u Widget::getSize()
  {
    sf::FloatRect rect;
    sf::Vector2u  size;

    rect    = m_widget->getGlobalBounds();
    size.x  = (rect.left + rect.width);
    size.y  = (rect.top + rect.height);

    return size;
  }



  const int& Widget::getZOrder()
  {
    return m_zorder;
  }
}
