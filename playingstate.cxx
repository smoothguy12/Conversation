#include "playingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "window.hxx"

namespace Game
{
  PlayingState::PlayingState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    Core::Window::getInstance()->addObserver(this, sf::Event::KeyPressed);

    log::write(log::message, "Initialized Game::PlayState");
  }

  PlayingState::~PlayingState()
  {
    Core::Window::getInstance()->removeObserver(this);
    log::write(log::message, "Destroyed Game::PlayState");
  }

  // State
  void PlayingState::execute()
  {
    log::write(log::flood, "Playing");
  }

  void PlayingState::activate(bool active)
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
  void PlayingState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::write(log::hint, this->toString() + " caught an event.");

        if (event.type == sf::Event::KeyPressed)
          {
          }
      }
  }

  std::string PlayingState::toString()
  {
    return ("Game::PlayingState");
  }
}
