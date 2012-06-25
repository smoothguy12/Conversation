#ifndef WINDOW_HXX
#define WINDOW_HXX
#include "singleton.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "observable.hxx"
#include <list>

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
    void addObserver(Observer* observer, sf::Event::EventType eventType);
    void removeObserver(Observer* observer);
    void removeObserver(Observer* observer, sf::Event::EventType eventType);

  private:
    Window();
    ~Window();

    sf::RenderWindow  m_window;
    sf::Event         m_event;
    std::list<Observer*> m_observers;
  };
}

#endif // WINDOW_HXX
