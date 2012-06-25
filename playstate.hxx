#ifndef PLAYSTATE_HXX
#define PLAYSTATE_HXX
#include "state.hxx"

namespace Game
{
  class PlayState : public State
  {
  public:
    PlayState();
    ~PlayState();
    void execute();
    void activate(bool active);
  };
}

#endif // PLAYSTATE_HXX
