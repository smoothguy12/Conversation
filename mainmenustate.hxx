#ifndef MAINMENUSTATE_HXX
#define MAINMENUSTATE_HXX
#include "state.hxx"
#include "context.hxx"

namespace Game
{
  class MainMenuState : public State
  {
  public:
    MainMenuState(Context* context);
    ~MainMenuState();

    // State
    void execute();
    void activate(bool active);

    // Observer
    void notify(sf::Event &event);
    std::string toString();
  };
}

#endif // MAINMENUSTATE_HXX
