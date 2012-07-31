#include "eventpump.hxx"

namespace Core
{
  EventPump::~EventPump()
  {
    // TODO: Clear m_core_events.
  }



  void EventPump::inject(Event event)
  {
    m_core_events.push_back(event);
  }



  bool EventPump::pump(Event& event)
  {
    std::vector<Event>::iterator itr;
    unsigned int size;

    size = m_core_events.size();

    for (itr = m_core_events.begin(); itr != m_core_events.end(); )
      {
        event = *itr;
        m_core_events.erase(itr);
        break;
      }

    if (size != 0)
      return true;
    else
      return false;
  }
}
