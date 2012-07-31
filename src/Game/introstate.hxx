#ifndef INTROSTATE_HXX
#define INTROSTATE_HXX
#include "state.hxx"
#include <string>
#include <SFML/Window/Event.hpp>
#include "context.hxx"

namespace Game
{
  class IntroState : public State
  {
  public:
    IntroState(Context* context);
    ~IntroState();

    // State
    void execute();
    void activate(bool active);

    // Observer<sf::Event>
    void notify(sf::Event& event);

    // Observer
    std::string toString();
  };
}

#endif // INTROSTATE_HXX
