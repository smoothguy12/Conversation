#ifndef CONTEXT_HXX
#define CONTEXT_HXX
#include <list>
#include "state.hxx"
#include <vector>
#include "Entities/character.hxx"

namespace Game
{
  class State;
  class Context
  {
  public:
    Context();
    ~Context();
    void start();
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

    // Entities
    std::vector<Entities::Entity*> m_characters;
  };
}

#endif // CONTEXT_HXX
