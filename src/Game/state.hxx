#ifndef STATE_HXX
#define STATE_HXX
#include "Core/observer.hxx"
#include "context.hxx"
#include <SFML/Window/Event.hpp>
#include "Core/event.hxx"

namespace Game
{
  class Context;
  class State : public Core::Observer<sf::Event>, public Core::Observer<Core::Event>
  {
  public:
    using Core::Observer<sf::Event>::toString;
    using Core::Observer<Core::Event>::toString;

    virtual ~State() {}
    virtual void execute() = 0;
    virtual void activate(bool activate) = 0;

  protected:
    bool      m_active;
    Context*  m_context;
  };
}

#endif // STATE_HXX
