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
    while (m_window.pollEvent(m_event))
      {
        if (m_event.type == sf::Event::Closed)
          {
            m_window.close();
          }
      }
  }

  void Window::addObserver(Observer* observer, sf::Event::EventType eventType)
  {
  }

  void Window::removeObserver(Observer* observer)
  {
  }

  void Window::removeObserver(Observer* observer, sf::Event::EventType eventType)
  {
  }
}
