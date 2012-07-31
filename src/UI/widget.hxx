#ifndef WIDGET_HXX
#define WIDGET_HXX
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

namespace UI
{
  class Widget
  {
  public:
    static unsigned int giveIdentifier();
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
    unsigned int  getIdentifier();

    static unsigned int s_free_id;

  protected:
    sf::Sprite*   m_widget;
    int           m_zorder;
    int           m_tab_index;
    bool          m_focused;
    bool          m_mouse_over;
    unsigned int  m_identifier;
  };
}

#endif // WIDGET_HXX
