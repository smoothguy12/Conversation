#include "container.hxx"
#include <iostream>
#include <SFML/Window/Event.hpp>

namespace UI
{
  Container::~Container()
  {
    std::list<Widget*>::iterator it;

    for (it = m_widgets.begin(); it != m_widgets.end(); )
      {
        delete *it;
        it = m_widgets.erase(it);
      }
  }



  void Container::push(UI::Widget* widget)
  {
    m_widgets.push_back(widget);
  }



  void Container::pull(UI::Widget* widget)
  {
    std::list<UI::Widget*>::iterator it;

    for (it = m_widgets.begin(); it != m_widgets.end(); )
      {
        if (*it == widget)
          {
            it = m_widgets.erase(it);
          }
        else
          it++;
      }
  }



  void Container::dispatch(sf::Event& event)
  {
    /*
     * Dispatch all events to widgets. They'll then handle them depending
     * on their m_focus value.
     * Exception: MouseButtonPressed/Releader events are processed
     * depending on widgets' m_zorder (highest z ordered widget actually
     * handle it).
     */
    std::list<UI::Widget*>::iterator it;

    for (it = m_widgets.begin(); it != m_widgets.end(); it++)
      {
        (*it)->handle(event);
      }
  }
}
