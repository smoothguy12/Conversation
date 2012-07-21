#ifndef PLAYSTATE_HXX
#define PLAYSTATE_HXX
#include "state.hxx"
#include "context.hxx"

namespace Game
{
  class PlayingState : public State
  {
  public:
    PlayingState(Context* context);
    ~PlayingState();

    // State
    void execute();
    void activate(bool active);

    // Observer
    void notify(sf::Event &event);
    std::string toString();
  };
}

#endif // PLAYSTATE_HXX