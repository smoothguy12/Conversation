#ifndef OBSERVABLE_HXX
#define OBSERVABLE_HXX
#include <SFML/Window/Event.hpp>
#include "observer.hxx"

namespace Core
{
  class Observable
  {
  public:
    virtual void attach(Observer* observer, sf::Event::EventType eventType) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void detach(Observer* observer, sf::Event::EventType eventType) = 0;
  };
}

#endif // OBSERVABLE_HXX
