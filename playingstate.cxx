#include "playingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"

namespace Game
{
  PlayingState::PlayingState()
  {
    m_active = false;

    log::write(log::message, "Initialized Game::PlayState");
  }

  PlayingState::~PlayingState()
  {
    log::write(log::message, "Destroyed Game::PlayState");
  }

  // State
  void PlayingState::execute()
  {
    log::write(log::hint, "Playing");
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
      }
    else
      {
      }
  }

  std::string PlayingState::toString()
  {
    return ("Game::PlayingState");
  }
}
