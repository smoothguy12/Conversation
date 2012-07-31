#include "eventpump.hxx"

namespace Core
{
  EventPump::~EventPump()
  {
    // TODO: Clear m_events.
  }



  void EventPump::inject(Event event)
  {
    m_events.push_back(event);
  }



  void EventPump::pump(Event& event)
  {
    std::vector<Event>::iterator itr;

    for (itr = m_events.begin(); itr != m_events.end(); )
      {
        event = *itr;
        itr   = m_events.erase(itr);
      }
  }
}
