#ifndef EVENTPUMP_HXX
#define EVENTPUMP_HXX
#include "event.hxx"
#include <vector>

namespace Core
{
  class EventPump
  {
  public:
    virtual ~EventPump();
    virtual void inject(Event event);
    virtual bool pump(Event& event);

  protected:
    EventPump() {}

    std::vector<Event> m_core_events;
  };
}

#endif // EVENTPUMP_HXX
