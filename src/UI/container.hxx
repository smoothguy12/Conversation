#ifndef CONTAINER_HXX
#define CONTAINER_HXX
#include "widget.hxx"
#include <SFML/Window/Event.hpp>
#include <list>

namespace UI
{
  class Container
  {
  public:
    virtual ~Container();

  protected:
    Container() {}
    void push(Widget* widget);
    void pull(Widget* widget);
    void dispatch(sf::Event& event);

    std::list<Widget*>  m_widgets;
  };
}

#endif // DISPATCHER_HXX
