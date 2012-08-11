#ifndef VIEW_HXX
#define VIEW_HXX
#include "UI/label.hxx"
#include "UI/textbutton.hxx"
#include "model.hxx"

namespace Game
{
  namespace Conversation
  {
    class View
    {
    public:
      View(Model* model);
      ~View();
      void update();
      void show();
      void hide();

    protected:
      Model*                        m_model;
      UI::Label*                    m_text;
      std::vector<UI::TextButton*>  m_choices;
    };
  }
}

#endif // VIEW_HXX
