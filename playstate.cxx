#include "playstate.hxx"
#include "log.hxx"

namespace Game
{
  PlayState::PlayState()
  {
    m_active = false;

    log::write(log::message, "Initialized Game::PlayState");
  }

  PlayState::~PlayState()
  {
    log::write(log::message, "Destroyed Game::PlayState");
  }

  void PlayState::execute()
  {
    log::write(log::timmy, "Hello Play");
  }

  void PlayState::activate(bool active)
  {
    if (active)
      {
      }
    else
      {
      }

    m_active = active;
  }
}
