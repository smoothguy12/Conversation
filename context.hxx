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

  private:
    void update();

    bool                    m_running;
    std::list<Game::State*> m_states;
  };
}

#endif // CONTEXT_HXX
