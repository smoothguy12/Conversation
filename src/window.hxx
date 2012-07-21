#ifndef WINDOW_HXX
#define WINDOW_HXX
#include "singleton.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "observable.hxx"
#include "observer.hxx"
#include "widget.hxx"
#include "container.hxx"
#include <list>
#include <map>

namespace Core
{
  class Window : public Singleton<Window>, public Observable, public UI::Container
  {
  public:
    friend class Singleton<Window>;
    void          draw();
    void          update();
    bool          isShown();
    sf::Vector2u  getSize();

    // Observable
    void attach(Observer* observer, sf::Event::EventType eventType);
    void detach(Observer* observer);
    void detach(Observer* observer, sf::Event::EventType eventType);

    // Rendering
    void push(sf::Drawable* drawable);
    void pull(sf::Drawable* drawable);

    // UI:Container override
    void push(UI::Widget* widget);
    void pull(UI::Widget* widget);

  private:
    Window();
    ~Window();

    sf::RenderWindow  m_window;
    sf::Event         m_event;

    // Observable
    std::map<sf::Event::EventType, std::list<Observer*> > m_observers;

    // Rendering
    std::list<sf::Drawable*>  m_rendering;
  };
}

#endif // WINDOW_HXX
