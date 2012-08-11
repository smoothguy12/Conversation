#include "view.hxx"
#include "model.hxx"
#include "Core/window.hxx"

namespace Game
{
  namespace Conversation
  {
    View::View(Model* model)
    {
      m_model = model;
      m_text = new UI::Label(model->getNode()->getText(), UI::Text::Standard);
    }



    View::~View()
    {
      std::vector<UI::TextButton*>::iterator itr;

      for (itr = m_choices.begin(); itr != m_choices.end(); )
        {
          delete *itr;
          itr = m_choices.erase(itr);
        }

      delete m_text;

      log::putln(log::message, "Destroyed Game::Conversation::View");
    }



    void View::update()
    {
      std::vector<Node*>::const_iterator itr;

      m_text->setText( m_model->getNode()->getText() );
      m_choices.clear();

      for (itr = m_model->getNode()->getTargets().begin();
           itr != m_model->getNode()->getTargets().end();
           itr++)
        {
          m_choices.push_back( new UI::TextButton( (*itr)->getText()) );
        }
    }



    void View::show()
    {
      Core::Window::getInstance()->push(m_text);
    }



    void View::hide()
    {
      Core::Window::getInstance()->pull(m_text);
    }
  }
}
