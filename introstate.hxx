#ifndef INTROSTATE_HXX
#define INTROSTATE_HXX
#include "state.hxx"
#include <string>
#include <SFML/Window/Event.hpp>

namespace Game
{
  class IntroState : public State
  {
  public:
    IntroState();
    ~IntroState();

    // State
    void execute();
    void activate(bool active);

    // Observer
    void notify(sf::Event& event);
    std::string toString();
  };
}

#endif // INTROSTATE_HXX
