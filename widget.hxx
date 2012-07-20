#ifndef WIDGET_HXX
#define WIDGET_HXX
#include <SFML/Graphics/Sprite.hpp>

namespace UI
{
  class Widget
  {
  public:
    Widget();
    ~Widget();
    void          setZOrder(int zorder);
    void          increaseZOrder();
    void          decreaseZOrder();
    void          gainFocus();
    void          loseFocus();
    const int&    getZOrder();
    sf::Sprite*   get();
    sf::Drawable* getDrawable();
    sf::Vector2u  getSize();

  protected:
    sf::Sprite*   m_sprite;
    int           m_zorder;
    bool          m_focused;
  };
}

#endif // WIDGET_HXX
