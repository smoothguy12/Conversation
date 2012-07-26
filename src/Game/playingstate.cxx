#include "playingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "Core/window.hxx"

namespace Game
{
  PlayingState::PlayingState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    Core::Window::getInstance()->attach(this, sf::Event::KeyPressed);

    log::putln(log::message, "Initialized Game::PlayingState");
  }



  PlayingState::~PlayingState()
  {
    Core::Window::getInstance()->detach(this);

    log::putln(log::message, "Destroyed Game::PlayingState");
  }



  // State
  void PlayingState::execute()
  {
    log::putln(log::flood, "Playing");
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
        log::putln(log::flood, this->toString() + " caught an event.");

        if (event.type == sf::Event::KeyPressed)
          {
          }
      }
  }



  std::string PlayingState::toString()
  {
    return "Game::PlayingState";
  }
}
