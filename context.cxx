#include "context.hxx"
#include "window.hxx"
#include "log.hxx"
#include "settings.hxx"
#include "introstate.hxx"
#include "playingstate.hxx"

namespace Game
{
  Context::Context()
  {
    m_running = true;
    m_state = new IntroState();

    // We should wait a little before entering IntroState (may'be LoadingState ?)
    m_state->activate(true);

    log::write(log::message, "Initialized Game::Context");
  }

  Context::~Context()
  {
    Core::Settings::destroyInstance();
    Core::Window::destroyInstance();
    log::write(log::message, "Destroyed Game::Context");
  }

  void Context::run()
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
    // FIXME: Error checks
    m_states.push_back(state);
  }

  void Context::setState(State* state)
  {
    m_state->activate(false);
    m_state = state;
    m_state->activate(true);
  }
}
