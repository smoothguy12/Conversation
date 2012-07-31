#include "Core/window.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Core/settings.hxx"
#include "log.hxx"
#include "UI/widget.hxx"

namespace Core
{
  Window::Window()
  {
    Core::Settings* s;

    s = Core::Settings::getInstance();

    m_window.create(sf::VideoMode(s->get<int>("window.width"),
                                  s->get<int>("window.height")),
                    s->get<std::string>("window.title"));

    m_window.setFramerateLimit(s->get<int>("window.fps_limit"));
    m_window.setKeyRepeatEnabled(s->get<bool>("input.key_repeat"));

    log::putln(log::message, "Initialized Core::Window");
  }



  Window::~Window()
  {
    log::putln(log::message, "Destroyed Core::Window");
  }



  void Window::draw()
  {
    std::list<sf::Drawable*>::iterator it;

    m_window.clear();

    for (it = m_rendering.begin(); it != m_rendering.end(); it++)
      {
        m_window.draw(**it);
      }

    m_window.display();
  }



  void Window::update()
  {
    std::map<sf::Event::EventType, std::list<Observer<sf::Event>*> >::iterator itm;
    std::list<Observer<sf::Event>*>::iterator itl;
    std::map<Core::Event::EventType, std::list<Observer<Core::Event>*> >::iterator itmc;
    std::list<Observer<Core::Event>*>::iterator itlc;

    while (m_window.pollEvent(m_event))
      {
        for (itm = m_sf_observers.begin(); itm != m_sf_observers.end(); itm++)
          {
            if (itm->first == m_event.type)
              {
                for (itl = itm->second.begin(); itl != itm->second.end(); itl++)
                  {
                    (*itl)->notify(m_event);
                  }
              }
          }

        if (m_event.type == sf::Event::Closed)
          {
            m_window.close();
          }

        this->dispatch(m_event);
      }

    if (this->pump(m_core_event))
      {
        for (itmc = m_core_observers.begin(); itmc != m_core_observers.end(); itmc++)
          {
            if (itmc->first == m_core_event.type)
              {
                for (itlc = itmc->second.begin(); itlc != itmc->second.end(); itlc++)
                  {
                    (*itlc)->notify(m_core_event);
                  }
              }
          }
      }
  }



  bool Window::isShown()
  {
    return m_window.isOpen();
  }



  sf::Vector2u Window::getSize()
  {
    return m_window.getSize();
  }



  // Observable<sf::Event, sf::Event::EventType>
  void Window::attach(Observer<sf::Event>* observer, sf::Event::EventType eventType)
  {
    this->internal_attach(m_sf_observers, observer, eventType);
  }



  void Window::detach(Observer<sf::Event>* observer)
  {
    this->internal_detach(m_sf_observers, observer);
  }



  void Window::detach(Observer<sf::Event>* observer, sf::Event::EventType eventType)
  {
    this->internal_detach(m_sf_observers, observer, eventType);
  }



  // Observable<Core::Event, Core::Event::EventType>
  void Window::attach(Observer<Core::Event>* observer, Core::Event::EventType eventType)
  {
    this->internal_attach(m_core_observers, observer, eventType);
  }



  void Window::detach(Observer<Core::Event>* observer)
  {
    this->internal_detach(m_core_observers, observer);
  }



  void Window::detach(Observer<Core::Event>* observer, Core::Event::EventType eventType)
  {
    this->internal_detach(m_core_observers, observer, eventType);
  }



  // Rendering
  void Window::push(sf::Drawable* drawable)
  {
    std::list<sf::Drawable*>::iterator it;
    bool found;

    found = false;

    for (it = m_rendering.begin(); it != m_rendering.end(); it++)
      {
        if (*it == drawable)
          found = true;
      }

    if (!found)
      m_rendering.push_back(drawable);
    else
      log::putln(log::error, "Tried to pushDrawable twice.");
  }



  void Window::pull(sf::Drawable* drawable)
  {
    std::list<sf::Drawable*>::iterator it;

    for (it = m_rendering.begin(); it != m_rendering.end(); it++)
      {
        if (*it == drawable)
          it = m_rendering.erase(it);
      }
  }



  // UI::Container override
  void Window::push(UI::Widget* widget)
  {
    this->push(widget->getDrawable());
    UI::Container::push(widget);
  }



  void Window::pull(UI::Widget* widget)
  {
    std::list<sf::Drawable*>::iterator it;

    for (it = m_rendering.begin(); it != m_rendering.end(); it++)
      {
        if (*it == widget->getDrawable())
          it = m_rendering.erase(it);
      }

    UI::Container::pull(widget);
  }
}
