#ifndef PRELOADINGSTATE_HXX
#define PRELOADINGSTATE_HXX
#include "state.hxx"
#include "context.hxx"

namespace Game
{
  class PreloadingState : public State
  {
  public:
    PreloadingState(Context* context);
    ~PreloadingState();

    // State
    void execute();
    void activate(bool active);

    // Observer
    void notify(sf::Event &event);
    std::string toString();
  };
}

#endif // PRELOADINGSTATE_HXX
