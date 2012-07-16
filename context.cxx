#include "context.hxx"
#include "window.hxx"
#include "log.hxx"
#include "settings.hxx"
#include "preloadingstate.hxx"
#include "mixer.hxx"
#include "fontmanager.hxx"

// TEMP
#include "entityfactory.hxx"

namespace Game
{
  Context::Context()
  {
    m_running = true;
    m_state   = new PreloadingState(this);

    // We should wait a little before entering IntroState (may'be LoadingState ?)
    m_state->activate(true);

    // Factory initialization
    Core::EntityFactory::getInstance()->learn<Entities::Character>("character");

    // Temporary Character initialization
    Entities::Entity* character = Core::EntityFactory::getInstance()->give("character");
    character->initialize();

    m_characters.push_back(character);

    // FIXME
    Core::FontManager* fm = Core::FontManager::getInstance();

    log::putln(log::message, "Initialized Game::Context");
  }



  Context::~Context()
  {
    std::list<State*>::iterator its;
    std::vector<Entities::Entity*>::iterator itc;

    for (its = m_states.begin(); its != m_states.end(); )
      {
        delete *its;
        its = m_states.erase(its);
      }

    for (itc = m_characters.begin(); itc != m_characters.end(); )
      {
        delete *itc;
        itc = m_characters.erase(itc);
      }

    Core::Mixer::destroyInstance();
    Core::Settings::destroyInstance();
    Core::EntityFactory::destroyInstance();
    Core::Window::destroyInstance();

    log::putln(log::message, "Destroyed Game::Context");
  }



  void Context::start()
  {
    Core::Window* window;

    window = Core::Window::getInstance();

    while (m_running and window->isShown())
      {
        this->update();
      }
  }



  void Context::update()
  {
    Core::Window* window;

    window = Core::Window::getInstance();
    window->update();
    window->draw();

    m_state->execute();
  }



  void Context::stop()
  {
    m_running = false;
  }



  // State
  void Context::enlist(State* state)
  {
    std::list<State*>::iterator itl;
    bool found;

    found = false;

    for (itl = m_states.begin(); itl != m_states.end(); itl++)
      {
        if ( (*itl) == state)
          {
            found = true;
          }
      }

    if (found)
      log::putln(log::warning, "Called Context::enlist() more than one time.");
    else
      m_states.push_back(state);
  }



  void Context::setState(State* state)
  {
    log::putln(log::trivial, "Switching from " + m_state->toString() + " to " + state->toString());

    m_state->activate(false);
    m_state = state;
    m_state->activate(true);
  }
}
