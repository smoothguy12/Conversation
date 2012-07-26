#ifndef MAINMENUSTATE_HXX
#define MAINMENUSTATE_HXX
#include "state.hxx"
#include "context.hxx"
#include "UI/widget.hxx"

namespace Game
{
  class MainMenuState : public State
  {
  public:
    MainMenuState(Context* context);
    ~MainMenuState();

    // State
    void           execute();
    void           activate(bool active);

    // Observer
    void          notify(sf::Event &event);
    std::string   toString();

    UI::Widget*   m_title;
    UI::Widget*   m_play;
  };
}

#endif // MAINMENUSTATE_HXX
