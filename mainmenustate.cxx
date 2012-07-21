#include "mainmenustate.hxx"
#include <SFML/Window/Event.hpp>
#include "log.hxx"
#include "context.hxx"
#include "window.hxx"
#include "settings.hxx"
#include "introstate.hxx"
#include "mixer.hxx"

namespace Game
{
  MainMenuState::MainMenuState(Context* context)
  {
    Core::Window*   w;
    Core::Settings* s;
    float x;
    float y;

    m_active  = false;
    m_context = context;
    m_context->enlist(this);
    w = Core::Window::getInstance();
    s = Core::Settings::getInstance();

    w->attach(this, sf::Event::KeyPressed);
    w->attach(this, sf::Event::MouseMoved);
    w->attach(this, sf::Event::MouseEntered);
    w->attach(this, sf::Event::MouseLeft);
    w->attach(this, sf::Event::MouseButtonPressed);
    w->attach(this, sf::Event::MouseButtonReleased);
    w->attach(this, sf::Event::MouseWheelMoved);

    /*
     * I've placed m_title on default coordinates then moved it because my
     * current design does not allow me to call getSize() on Text
     * initialization (we can't get the size of something which has not
     * been drawn yet).
     * Percents values may be more suitable for resolution independent
     * positioning.
     */
    m_title = new UI::Text(s->get<std::string>("window.title"),
                           UI::Text::Title,
                           sf::Vector2f(0, 0) );

    x = (w->getSize().x /2) - (m_title->getSize().x /2);
    y = (w->getSize().y /8) - (m_title->getSize().y /2);
    m_title->move(x, y);

    log::putln(log::message, "Initialized Game::MainMenuState");
  }



  MainMenuState::~MainMenuState()
  {
    Core::Window* w;

    w = Core::Window::getInstance();
    w->detach(this);
    w->pull(m_title->getDrawable());

    delete(m_title);

    log::putln(log::message, "Destroyed Game::MainMenuState");
  }



  // State
  void MainMenuState::execute()
  {
    log::putln(log::flood, "Menu");
  }



  void MainMenuState::activate(bool active)
  {
    Core::Window* w;

    w = Core::Window::getInstance();

    if (active)
      {
        Core::Mixer::getInstance()->pick(0);
        Core::Mixer::getInstance()->play();

        w->push(m_title->getDrawable());
      }
    else
      {
        Core::Mixer::getInstance()->pause();
        w->pull(m_title->getDrawable());
      }

    m_active = active;
  }



  // Observer
  void MainMenuState::notify(sf::Event& event)
  {
    if (m_active)
      {
        log::putln(log::flood, this->toString() + " caught an event.");

        if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::Num1
                || event.key.code == sf::Keyboard::Numpad1)
              {
                m_context->setState(new IntroState(m_context));
              }
          }
      }
  }



  std::string MainMenuState::toString()
  {
    return "Game::MainMenuState";
  }
}
