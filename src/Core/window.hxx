#ifndef WINDOW_HXX
#define WINDOW_HXX
#include "Core/singleton.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Core/observable.hxx"
#include "Core/observer.hxx"
#include "UI/widget.hxx"
#include "UI/container.hxx"
#include "Core/eventpump.hxx"
#include <list>
#include <map>

namespace Core
{
  class Window :
      public Singleton<Window>,
      public Observable<sf::Event, sf::Event::EventType>,
      public Observable<Core::Event, Core::Event::EventType>,
      public EventPump,
      public UI::Container
  {
  public:
    friend class Singleton<Window>;
    using Observable<sf::Event, sf::Event::EventType>::internal_attach;
    using Observable<sf::Event, sf::Event::EventType>::internal_detach;
    using Observable<Core::Event, Core::Event::EventType>::internal_attach;
    using Observable<Core::Event, Core::Event::EventType>::internal_detach;

    void          draw();
    void          update();
    bool          isShown();
    sf::Vector2u  getSize();

    // Observable<sf::Event, sf::Event::EventType>
    void attach(Observer<sf::Event>* observer, sf::Event::EventType eventType);
    void detach(Observer<sf::Event>* observer);
    void detach(Observer<sf::Event>* observer, sf::Event::EventType eventType);

    // Observable<Core::Event, Core::Event::EventType>
    void attach(Observer<Core::Event>* observer, Core::Event::EventType eventType);
    void detach(Observer<Core::Event>* observer);
    void detach(Observer<Core::Event>* observer, Core::Event::EventType eventType);

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
    Core::Event       m_core_event;

    // Observable
    std::map<sf::Event::EventType, std::list<Observer<sf::Event>*> > m_sf_observers;
    std::map<Core::Event::EventType, std::list<Observer<Core::Event>*> > m_core_observers;

    // Rendering
    std::list<sf::Drawable*>  m_rendering;
  };
}

#endif // WINDOW_HXX
