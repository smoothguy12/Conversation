#include "preloadingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "window.hxx"
#include "mixer.hxx"
#include "introstate.hxx"

namespace Game
{
  PreloadingState::PreloadingState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    log::write(log::message, "Initialized Game::PreloadingState");
  }



  PreloadingState::~PreloadingState()
  {
    log::write(log::message, "Destroyed Game::PreloadingState");
  }



  // State
  void PreloadingState::execute()
  {
    log::write(log::flood, "Preloading");
  }



  void PreloadingState::activate(bool active)
  {
    if (active)
      {
        Core::Mixer::getInstance();
        m_context->setState(new IntroState(m_context));

      }
    else
      {
      }

    m_active = active;
  }



  // Observer
  void PreloadingState::notify(sf::Event& event)
  {
    if (m_active)
      {
      }
  }



  std::string PreloadingState::toString()
  {
    return ("Game::PreloadingState");
  }
}
