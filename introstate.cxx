#include "introstate.hxx"
#include <SFML/Window/Event.hpp>
#include "window.hxx"
#include "log.hxx"
#include "context.hxx"
#include "playingstate.hxx"

namespace Game
{
  IntroState::IntroState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    Core::Window::getInstance()->addObserver(this, sf::Event::KeyPressed);

    log::write(log::message, "Initialized Game::IntroState");
  }

  IntroState::~IntroState()
  {
    Core::Window::getInstance()->removeObserver(this);
    log::write(log::message, "Destroyed Game::IntroState");
  }

  // State
  void IntroState::execute()
  {
    log::write(log::flood, "Hello Intro");
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

        if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::Return)
              {
                m_context->setState(new PlayingState(m_context));
              }
          }
      }
  }

  std::string IntroState::toString()
  {
    return ("Game::IntroState");
  }
}
