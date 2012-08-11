#ifndef CONTROLLER_HXX
#define CONTROLLER_HXX
#include "model.hxx"
#include "view.hxx"
#include "Core/observer.hxx"
#include "Core/event.hxx"

namespace Game
{
  namespace Conversation
  {
    class Controller : public Core::Observer<Core::Event>
    {
    public:
      Controller(Model* model, View* view);
      ~Controller();
      void notify(Core::Event& event);
      std::string toString();

    protected:
      Model*  m_model;
      View*   m_view;
    };
  }
}

#endif // CONTROLLER_HXX
