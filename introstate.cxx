#include "introstate.hxx"
#include "log.hxx"

namespace Game
{
  IntroState::IntroState()
  {
    m_active = false;

    log::write(log::message, "Initialized Game::IntroState");
  }

  IntroState::~IntroState()
  {
    log::write(log::message, "Destroyed Game::IntroState");
  }

  // State
  void IntroState::execute()
  {
    log::write(log::hint, "Hello Intro");
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

      }
  }

  std::string IntroState::toString()
  {
    return ("Game::IntroState");
  }
}
