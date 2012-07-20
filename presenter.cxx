#include "presenter.hxx"
#include <iostream>

namespace UI
{
  Presenter::~Presenter()
  {
    std::list<Widget*>::iterator it;

    for (it = m_widgets.begin(); it != m_widgets.end(); )
      {
        delete *it;
        it = m_widgets.erase(it);
      }
  }
}
