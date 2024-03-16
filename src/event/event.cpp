#include "event/event.hpp"
#include "event/event_data.hpp"

Event::Event(/* args */)
{
}

Event::Event(event::EventInputDevice inputDevice,
                   event::EventType eventType,
                   event::EventKey eventKey)
{
    inputDevice = inputDevice;
    m_eventKeyCode = event::fromEventKeyToCode(eventKey);
    m_eventType = event::fromEventTypeToCode(eventType);
}

Event::~Event()
{
}


