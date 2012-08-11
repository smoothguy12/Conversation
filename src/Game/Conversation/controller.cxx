#include "controller.hxx"
#include "model.hxx"
#include "view.hxx"
#include "Core/window.hxx"
#include "Core/event.hxx"
#include "log.hxx"

namespace Game
{
  namespace Conversation
  {
    Controller::Controller(Model* model, View* view)
    {
      m_model = model;
      m_view  = view;

      Core::Window::getInstance()->attach(this, Core::Event::ButtonClicked);

      log::putln(log::message, "Initialized Game::Conversation::Controller.");
    }



    Controller::~Controller()
    {
      Core::Window::getInstance()->detach(this, Core::Event::ButtonClicked);

      log::putln(log::message, "Destroyed Game::Conversation::Controller.");
    }



    void Controller::notify(Core::Event &event)
    {
    }



    std::string Controller::toString()
    {
      return "Game::Conversation::Controller";
    }
  }
}
