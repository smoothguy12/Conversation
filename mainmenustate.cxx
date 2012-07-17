#include "mainmenustate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "window.hxx"
#include "settings.hxx"

namespace Game
{
  MainMenuState::MainMenuState(Context* context)
  {
    Core::Window*   w;
    Core::Settings* s;

    m_active  = false;
    m_context = context;
    m_context->enlist(this);
    w = Core::Window::getInstance();
    s = Core::Settings::getInstance();

    w->attach(this, sf::Event::KeyPressed);
    w->attach(this, sf::Event::MouseMoved);
    w->attach(this, sf::Event::MouseEntered);
    w->attach(this, sf::Event::MouseLeft);
    w->attach(this, sf::Event::MouseButtonPressed);
    w->attach(this, sf::Event::MouseButtonReleased);
    w->attach(this, sf::Event::MouseWheelMoved);

    m_title = new GUI::Text(s->get<std::string>("window.title"),
                            GUI::Text::Title,
                            sf::Vector2f(0, 0) );

    log::putln(log::message, "Initialized Game::MainMenuState");
  }



  MainMenuState::~MainMenuState()
  {
    Core::Window* w;

    w = Core::Window::getInstance();
    w->detach(this);
    w->pullDrawable(m_title->getDrawable());

    delete(m_title);

    log::putln(log::message, "Destroyed Game::MainMenuState");
  }



  // State
  void MainMenuState::execute()
  {
    log::putln(log::flood, "Menu");
  }



  void MainMenuState::activate(bool active)
  {
    Core::Window* w;

    w = Core::Window::getInstance();

    if (active)
      {
        w->pushDrawable(m_title->getDrawable());
      }
    else
      {
        w->pullDrawable(m_title->getDrawable());
      }

    m_active = active;
  }



  // Observer
  void MainMenuState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::putln(log::flood, this->toString() + " caught an event.");

        if (event.type == sf::Event::KeyPressed)
          {
          }
      }
  }



  std::string MainMenuState::toString()
  {
    return "Game::MainMenuState";
  }
}
