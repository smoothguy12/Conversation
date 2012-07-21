#include "introstate.hxx"
#include <SFML/Window/Event.hpp>
#include "window.hxx"
#include "log.hxx"
#include "context.hxx"
#include "playingstate.hxx"
#include "mixer.hxx"


namespace Game
{
  IntroState::IntroState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    Core::Window::getInstance()->attach(this, sf::Event::KeyPressed);

    log::putln(log::message, "Initialized Game::IntroState");
  }



  IntroState::~IntroState()
  {
    Core::Window::getInstance()->detach(this);

    log::putln(log::message, "Destroyed Game::IntroState");
  }



  // State
  void IntroState::execute()
  {
    log::putln(log::flood, "Hello Intro");
  }



  void IntroState::activate(bool active)
  {
    if (active)
      {
        Core::Mixer::getInstance()->pick(1);
        Core::Mixer::getInstance()->play();
      }
    else
      {
        Core::Mixer::getInstance()->pause();
      }

    m_active = active;
  }



  // Observer
  void IntroState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::putln(log::flood, this->toString() + " caught an event.");

        if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::Escape)
              {
                m_context->setState(new PlayingState(m_context));
              }
          }
      }
  }



  std::string IntroState::toString()
  {
    return "Game::IntroState";
  }
}
