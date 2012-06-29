#ifndef CONTEXT_HXX
#define CONTEXT_HXX
#include <list>
#include "state.hxx"

namespace Game
{
  class State;
  class Context
  {
  public:
    Context();
    ~Context();
    void run();
    void stop();

    // State
    void enlist(State* state);
    void setState(State* state);

  private:
    void update();

    bool                    m_running;

    // State
    std::list<State*>       m_states;
    State*                  m_state;
  };
}

#endif // CONTEXT_HXX
