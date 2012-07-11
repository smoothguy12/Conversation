#ifndef WINDOW_HXX
#define WINDOW_HXX
#include "singleton.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "observable.hxx"
#include "observer.hxx"
#include <list>
#include <map>

namespace Core
{
  class Window : public Singleton<Window>, public Observable
  {
  public:
    friend class Singleton<Window>;
    bool isShown();
    void draw();
    void update();

    // Observable
    void attach(Observer* observer, sf::Event::EventType eventType);
    void detach(Observer* observer);
    void detach(Observer* observer, sf::Event::EventType eventType);

  private:
    Window();
    ~Window();

    sf::RenderWindow  m_window;
    sf::Event         m_event;
    std::map<sf::Event::EventType, std::list<Observer*> > m_observers;
  };
}

#endif // WINDOW_HXX
