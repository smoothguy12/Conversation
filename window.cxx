#include "window.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "settings.hxx"
#include "log.hxx"

namespace Core
{
  Window::Window()
  {
    Core::Settings* s = Core::Settings::getInstance();

    m_window.create(sf::VideoMode(s->get<int>("window.width"),
                                  s->get<int>("window.height")),
                    s->get<std::string>("window.title"));
    m_window.setFramerateLimit(s->get<int>("window.fps_limit"));
    m_window.setKeyRepeatEnabled(s->get<bool>("input.key_repeat"));

    log::write(log::message, "Initialized Core::Window");
  }

  Window::~Window()
  {
    log::write(log::message, "Destroyed Core::Window");
  }

  bool Window::isShown()
  {
    return (m_window.isOpen());
  }

  void Window::draw()
  {
    m_window.clear();
    m_window.display();
  }

  void Window::update()
  {
    std::map<sf::Event::EventType, std::list<Observer*> >::iterator itm;
    std::list<Observer*>::iterator itl;

    while (m_window.pollEvent(m_event))
      {
        for (itm = m_observers.begin(); itm != m_observers.end(); itm++)
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
      }
  }

  void Window::attach(Observer* observer, sf::Event::EventType eventType)
  {
    std::map<sf::Event::EventType, std::list<Observer*> >::iterator itm;
    std::list<Observer*>::iterator itl;
    bool found;

    found = false;

    for (itm = m_observers.begin(); itm != m_observers.end(); itm++)
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); itl++)
          {
            if ( (*itl) == observer)
              {
                found = true;
              }
          }
      }

    if (found)
      log::write(log::warning, "Called Window::addObserver() more than one time.");
    else
      m_observers[eventType].push_back(observer);
  }

  void Window::detach(Observer* observer)
  {
    std::map<sf::Event::EventType, std::list<Observer*> >::iterator itm;
    std::list<Observer*>::iterator itl;

    for (itm = m_observers.begin(); itm != m_observers.end(); itm++)
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); )
          {
            if ( (*itl) == observer)
              {
                itl = itm->second.erase(itl);
              }
            else
              {
                itl++;
              }
          }
      }
  }

  void Window::detach(Observer* observer, sf::Event::EventType eventType)
  {
    std::map<sf::Event::EventType, std::list<Observer*> >::iterator itm;
    std::list<Observer*>::iterator itl;

    for (itm = m_observers.begin(); itm != m_observers.end(); itm++)
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); )
          {
            if ( (*itl) == observer)
              {
                if ( itm->first == eventType)
                  {
                    itl = itm->second.erase(itl);
                  }
                else
                  itl++;
              }
            else
              {
                itl++;
              }
          }
      }
  }
}
