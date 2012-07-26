#ifndef WIDGET_HXX
#define WIDGET_HXX
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

namespace UI
{
  class Widget
  {
  public:
    Widget();
    virtual ~Widget();
    void          setZOrder(int zorder);
    void          increaseZOrder();
    void          decreaseZOrder();
    void          gainFocus();
    void          loseFocus();
    virtual void  handle(sf::Event& event);
    virtual void  onMouseOver();
    virtual void  onMouseExit();
    virtual void  onFocusGained();
    virtual void  onFocusLost();
    void          move(float x, float y);
    void          move(sf::Vector2f coords);
    sf::Drawable* getDrawable();
    sf::Vector2u  getSize();
    const int&    getZOrder();

  protected:
    sf::Sprite*   m_widget;
    int           m_zorder;
    bool          m_focused;
    bool          m_mouseOver;
  };
}

#endif // WIDGET_HXX
