#ifndef EVENT_HXX
#define EVENT_HXX

namespace Core
{
  class Event
  {
  public:
    struct ButtonEvent
    {
      unsigned int identifier;
    };

    enum EventType
    {
      ButtonClicked
    };

    EventType type;

    union
    {
      ButtonEvent button;
    };
  };
}

#endif // EVENT_HXX
