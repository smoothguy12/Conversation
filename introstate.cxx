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

  void IntroState::execute()
  {
    log::write(log::timmy, "Hello Intro");
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

  void IntroState::notify(sf::Event& event)
  {
  }

  std::string IntroState::toString()
  {
  }
}
