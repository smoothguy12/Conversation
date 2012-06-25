#ifndef CONTEXT_HXX
#define CONTEXT_HXX
#include <list>
#include "state.hxx"

namespace Game
{
  class Context
  {
  public:
    Context();
    ~Context();
    void run();
    void stop();
    void enlist(State* state);
    void setState(State* state);

  private:
    void update();

    bool                    m_running;
    std::list<State*>       m_states;
    State*                  m_state;
  };
}

#endif // CONTEXT_HXX
