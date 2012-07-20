#ifndef PRESENTER_HXX
#define PRESENTER_HXX
#include "widget.hxx"
#include <SFML/Window/Event.hpp>
#include <list>

namespace UI
{
  class Presenter
  {
  public:
    virtual ~Presenter();
    virtual void dispatch(sf::Event& event) = 0;

  private:
    std::list<Widget*>  m_widgets;
  };
}

#endif // DISPATCHER_HXX
