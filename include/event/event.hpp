#if !defined(FULL_EVENT_TYPE)
#define FULL_EVENT_TYPE
#include "event_data.hpp"
class Event
{
private:
    event::EventInputDevice m_inputDevice;
    SDL_EventType m_eventType;
    SDL_Keycode m_eventKeyCode;

public:
    Event();
    Event(event::EventInputDevice inputDevice,
          event::EventType eventType,
          event::EventKey eventKey);
    ~Event();

    inline SDL_EventType getEventType() const { return m_eventType; }
    inline SDL_Keycode getEventCode() const { return m_eventKeyCode; }
};

#endif // FULL_EVENT_TYPE
