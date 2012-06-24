#ifndef WINDOW_HXX
#define WINDOW_HXX
#include "singleton.hxx"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Core
{
  class Window : public Singleton<Window>
  {
  public:
    friend class Singleton<Window>;
    bool isShown();
    void draw();
    void update();

  private:
    Window();
    ~Window();

    sf::RenderWindow  m_window;
    sf::Event         m_event;
  };
}

#endif // WINDOW_HXX
