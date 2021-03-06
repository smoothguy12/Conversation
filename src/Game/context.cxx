#include "context.hxx"
#include "Core/window.hxx"
#include "log.hxx"
#include "Core/settings.hxx"
#include "preloadingstate.hxx"
#include "Core/mixer.hxx"
#include "Core/fontmanager.hxx"
#include "UI/layout.hxx"

// TEMP
#include "Core/entityfactory.hxx"

namespace Game
{
  Context::Context()
  {
    m_running = true;
    m_state   = new PreloadingState(this);
    m_state->activate(true);

    // FIXME: Move this to a Spawner class
    // Factory initialization
    Core::EntityFactory::getInstance()->learn<Entities::Character>("character");

    // Temporary Character initialization
    Entities::Entity* character = Core::EntityFactory::getInstance()->give("character");
    character->initialize();

    m_characters.push_back(character);

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

    // FIXME: Delegate this to another class.
    Core::FontManager::destroyInstance();
    Core::Mixer::destroyInstance();
    Core::Settings::destroyInstance();
    Core::EntityFactory::destroyInstance();
    Core::Window::destroyInstance();
    UI::Layout::destroyInstance();

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
