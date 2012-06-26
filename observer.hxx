#ifndef OBSERVER_HXX
#define OBSERVER_HXX
#include <string>
#include <SFML/Window/Event.hpp>

namespace Core
{
  class Observer
  {
  public:
    virtual ~Observer() {}
    virtual void notify(sf::Event& event) = 0;
    virtual std::string toString() = 0;
  };
}

#endif // OBSERVER_HXX
