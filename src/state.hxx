#ifndef STATE_HXX
#define STATE_HXX
#include "observer.hxx"
#include "context.hxx"

namespace Game
{
  class Context;
  class State : public Core::Observer
  {
  public:
    virtual ~State() {}
    virtual void execute() = 0;
    virtual void activate(bool activate) = 0;

  protected:
    bool      m_active;
    Context*  m_context;
  };
}

#endif // STATE_HXX
