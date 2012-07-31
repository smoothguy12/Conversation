#ifndef OBSERVER_HXX
#define OBSERVER_HXX
#include <string>
#include <SFML/Window/Event.hpp>

namespace Core
{
  template<typename Thing>
  class Observer
  {
  public:
    virtual void notify(Thing& event) = 0;
    virtual std::string toString() = 0;
  };
}

#endif // OBSERVER_HXX
