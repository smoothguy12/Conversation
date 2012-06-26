#ifndef STATE_HXX
#define STATE_HXX
#include "observer.hxx"

namespace Game
{
  class State : public Core::Observer
  {
  public:
    virtual void execute() = 0;
    virtual void activate(bool activate) = 0;

  protected:
    State() {}
    bool    m_active;
  };
}

#endif // STATE_HXX
