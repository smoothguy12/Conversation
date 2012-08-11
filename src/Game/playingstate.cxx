#include "playingstate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "Core/window.hxx"
#include "Conversation/model.hxx"
#include "Conversation/view.hxx"
#include "Game/Conversation/controller.hxx"

namespace Game
{
  PlayingState::PlayingState(Context* context)
  {
    m_active  = false;
    m_context = context;
    m_context->enlist(this);
    m_cmodel  = new Conversation::Model();
    m_cview   = new Conversation::View(m_cmodel);
    m_ccontroller = new Conversation::Controller(m_cmodel, m_cview);

    Core::Window::getInstance()->attach(this, sf::Event::KeyPressed);

    log::putln(log::message, "Initialized Game::PlayingState");
  }



  PlayingState::~PlayingState()
  {
    Core::Window::getInstance()->detach(this, sf::Event::KeyPressed);

    delete m_ccontroller;
    delete m_cmodel;
    delete m_cview;

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



  // Observer<sf::Event>
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



  // Observer
  std::string PlayingState::toString()
  {
    return "Game::PlayingState";
  }
}
