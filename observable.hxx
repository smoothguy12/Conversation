#ifndef OBSERVABLE_HXX
#define OBSERVABLE_HXX
#include <SFML/Window/Event.hpp>
#include "observer.hxx"

namespace Core
{
  class Observable
  {
  public:
    virtual void addObserver(Observer* observer, sf::Event::EventType eventType) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer, sf::Event::EventType eventType) = 0;
  };
}

#endif // OBSERVABLE_HXX
