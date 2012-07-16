#include "mainmenustate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "window.hxx"

namespace Game
{
  MainMenuState::MainMenuState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    Core::Window::getInstance()->attach(this, sf::Event::KeyPressed);
    Core::Window::getInstance()->attach(this, sf::Event::MouseMoved);
    Core::Window::getInstance()->attach(this, sf::Event::MouseEntered);
    Core::Window::getInstance()->attach(this, sf::Event::MouseLeft);
    Core::Window::getInstance()->attach(this, sf::Event::MouseButtonPressed);
    Core::Window::getInstance()->attach(this, sf::Event::MouseButtonReleased);
    Core::Window::getInstance()->attach(this, sf::Event::MouseWheelMoved);

    log::putln(log::message, "Initialized Game::MainMenuState");
  }



  MainMenuState::~MainMenuState()
  {
    Core::Window::getInstance()->detach(this);

    log::putln(log::message, "Destroyed Game::MainMenuState");
  }



  // State
  void MainMenuState::execute()
  {
    log::putln(log::flood, "Menu");
  }



  void MainMenuState::activate(bool active)
  {
    if (active)
      {
      }
    else
      {
      }

    m_active = active;
  }



  // Observer
  void MainMenuState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::putln(log::hint, this->toString() + " caught an event.");

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
