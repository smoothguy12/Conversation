#ifndef PLAYSTATE_HXX
#define PLAYSTATE_HXX
#include "state.hxx"
#include "context.hxx"
#include "Conversation/model.hxx"
#include "Conversation/view.hxx"
#include "Conversation/controller.hxx"

namespace Game
{
  class PlayingState : public State
  {
  public:
    PlayingState(Context* context);
    ~PlayingState();

    // State
    void execute();
    void activate(bool active);

    // Observer<sf::Event>
    void notify(sf::Event &event);

    // Observer
    std::string toString();

  private:
    Conversation::Model* m_cmodel;
    Conversation::View* m_cview;
    Conversation::Controller* m_ccontroller;
  };
}

#endif // PLAYSTATE_HXX
