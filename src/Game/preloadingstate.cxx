#include "preloadingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "mainmenustate.hxx"
#include "Core/mixer.hxx"
#include "Core/fontmanager.hxx"


namespace Game
{
  PreloadingState::PreloadingState(Context* context)
  {
    m_active = false;
    m_context = context;
    m_context->enlist(this);

    log::putln(log::message, "Initialized Game::PreloadingState");
  }



  PreloadingState::~PreloadingState()
  {
    log::putln(log::message, "Destroyed Game::PreloadingState");
  }



  // State
  void PreloadingState::execute()
  {
    log::putln(log::flood, "Preloading");
  }



  void PreloadingState::activate(bool active)
  {
    if (active)
      {
        Core::Mixer::getInstance();
        Core::FontManager::getInstance();
        m_context->setState(new MainMenuState(m_context));

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
        // Avoid unused parameter warning...
        if (event.type == sf::Event::Closed)
          {
          }
      }
  }



  std::string PreloadingState::toString()
  {
    return "Game::PreloadingState";
  }
}
