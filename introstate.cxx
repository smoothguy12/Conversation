#include "introstate.hxx"
#include <SFML/Window/Event.hpp>
#include "window.hxx"
#include "log.hxx"

namespace Game
{
  IntroState::IntroState()
  {
    Core::Window::getInstance()->addObserver(this, sf::Event::KeyPressed);

    m_active = false;

    log::write(log::message, "Initialized Game::IntroState");
  }

  IntroState::~IntroState()
  {
    Core::Window::getInstance()->removeObserver(this, sf::Event::KeyPressed);
    log::write(log::message, "Destroyed Game::IntroState");
  }

  // State
  void IntroState::execute()
  {
    //    log::write(log::hint, "Hello Intro");
  }

  void IntroState::activate(bool active)
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
  void IntroState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::write(log::hint, this->toString() + " caught an event.");
      }
  }

  std::string IntroState::toString()
  {
    return ("Game::IntroState");
  }
}
