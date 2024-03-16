#if !defined(EVENT_DATA_HPP)
#define EVENT_DATA_HPP
#include <algorithm>
#include <string>

#include <string>
#include <SDL2/SDL.h>

namespace event
{
    enum class EventKey
    {
        NONE,
        _0,
        _1,
        _2,
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,
        W,
        A,
        S,
        D,
        P,
        Q,
        ESC,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SPACE,
        BUTTON_LEFT,
        BUTTON_RIGHT
    };
    enum class EventInputDevice
    {
        NONE,
        KEY,
        MOUSE
    };
    enum class EventType
    {
        NONE,
        KEY_DOWN,
        KEY_UP,
        MOUSE_MOVE,
        MOUSE_DOWN,
        MOUSE_UP

    };

    SDL_Keycode fromEventKeyToCode(EventKey key);

    const std::string fromEventKeyToString(EventKey key);

    EventKey fromStrToEventKey(const std::string &eventIn);

    SDL_EventType fromEventTypeToCode(EventType key);

    const std::string fromEventTypeToString(EventType key);

    EventType fromStrToEventType(const std::string &eventIn);

    const std::string fromInputDeviceToStr(EventInputDevice device);

    EventInputDevice fromStringToInputDevice(const std::string &deviceIn);

}

#endif // EVENT_DATA_HPP
