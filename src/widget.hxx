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
    void          handle(sf::Event& event);
    virtual void  move(float x, float y);
    virtual void  move(sf::Vector2f coords);
    virtual sf::Drawable* getDrawable();
    virtual sf::Vector2u  getSize();
    const int&    getZOrder();

  protected:
    sf::Sprite*         m_sprite;
    int                 m_zorder;
    bool                m_focused;
  };
}

#endif // WIDGET_HXX
