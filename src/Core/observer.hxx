#ifndef OBSERVER_HXX
#define OBSERVER_HXX
#include <string>
#include <SFML/Window/Event.hpp>
#include "log.hxx"

namespace Core
{
  template<typename Thing>
  class Observer
  {
  public:
    virtual void notify(Thing& event)
    {
      log::putln( log::flood, std::string("Notified of " + event.type) );
    }
    virtual std::string toString() = 0;
  };
}

#endif // OBSERVER_HXX
