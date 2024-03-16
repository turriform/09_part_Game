#include "event/event_data.hpp"

namespace event
{
    SDL_Keycode fromEventKeyToCode(EventKey key)
    {
        switch (key)
        {
        case EventKey::_0:
            return SDLK_0;
        case EventKey::_1:
            return SDLK_1;
        case EventKey::_2:
            return SDLK_2;
        case EventKey::_3:
            return SDLK_3;
        case EventKey::_4:
            return SDLK_4;
        case EventKey::_5:
            return SDLK_5;
        case EventKey::_6:
            return SDLK_6;
        case EventKey::_7:
            return SDLK_7;
        case EventKey::_8:
            return SDLK_8;
        case EventKey::_9:
            return SDLK_9;

        case EventKey::W:
            return SDLK_w;
        case EventKey::A:
            return SDLK_a;
        case EventKey::S:
            return SDLK_s;
        case EventKey::D:
            return SDLK_d;
        case EventKey::P:
            return SDLK_p;
        case EventKey::Q:
            return SDLK_q;
        case EventKey::ESC:
            return SDLK_ESCAPE;
        case EventKey::SPACE:
            return SDLK_SPACE;

        case EventKey::UP:
            return SDLK_UP;
        case EventKey::DOWN:
            return SDLK_DOWN;
        case EventKey::LEFT:
            return SDLK_LEFT;
        case EventKey::RIGHT:
            return SDLK_RIGHT;

        case EventKey::BUTTON_LEFT:
            return SDL_BUTTON_LEFT;
        case EventKey::BUTTON_RIGHT:
            return SDL_BUTTON_RIGHT;

        default:
            return SDLK_ESCAPE;
        }
        return SDLK_ESCAPE;
    }

    const std::string fromEventKeyToString(EventKey key)
    {
        switch (key)
        {
        case EventKey::_0:
            return "0";
        case EventKey::_1:
            return "1";
        case EventKey::_2:
            return "2";
        case EventKey::_3:
            return "3";
        case EventKey::_4:
            return "4";
        case EventKey::_5:
            return "5";
        case EventKey::_6:
            return "6";
        case EventKey::_7:
            return "7";
        case EventKey::_8:
            return "8";
        case EventKey::_9:
            return "9";
        case EventKey::W:
            return "W";
        case EventKey::A:
            return "A";
        case EventKey::S:
            return "S";
        case EventKey::D:
            return "D";
        case EventKey::P:
            return "P";
        case EventKey::Q:
            return "Q";
        case EventKey::ESC:
            return "ESC";

        case EventKey::SPACE:
            return "SPACE";
        case EventKey::UP:
            return "UP";
        case EventKey::DOWN:
            return "DOWN";
        case EventKey::LEFT:
            return "LEFT";
        case EventKey::RIGHT:
            return "RIGHT";

        case EventKey::BUTTON_LEFT:
            return "MOUSE_LEFT";
        case EventKey::BUTTON_RIGHT:
            return "MOUSE_RIGHT";

        default:
            return "";
        }
        return "";
    }
    EventKey fromStrToEventKey(const std::string &keyIn)
    {
        std::string key = keyIn;
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);

        if (key == "0")
        {
            return EventKey::_0;
        }
        if (key == "1")
        {
            return EventKey::_1;
        }
        if (key == "2")
        {
            return EventKey::_2;
        }
        if (key == "3")
        {
            return EventKey::_3;
        }
        if (key == "4")
        {
            return EventKey::_4;
        }
        if (key == "5")
        {
            return EventKey::_5;
        }
        if (key == "6")
        {
            return EventKey::_6;
        }
        if (key == "7")
        {
            return EventKey::_7;
        }
        if (key == "8")
        {
            return EventKey::_8;
        }
        if (key == "9")
        {
            return EventKey::_9;
        }

        if (key == "W")
        {
            return EventKey::W;
        }
        else if (key == "A")
        {
            return EventKey::A;
        }
        else if (key == "S")
        {
            return EventKey::S;
        }
        else if (key == "D")
        {
            return EventKey::D;
        }
        else if (key == "P")
        {
            return EventKey::P;
        }
        else if (key == "Q")
        {
            return EventKey::Q;
        }
        else if (key == "ESC")
        {
            return EventKey::ESC;
        }
        else if (key == "SPACE")
        {
            return EventKey::SPACE;
        }

        else if (key == "UP")
        {
            return EventKey::UP;
        }

        else if (key == "DOWN")
        {
            return EventKey::DOWN;
        }

        else if (key == "LEFT")
        {
            return EventKey::LEFT;
        }

        else if (key == "RIGHT")
        {
            return EventKey::RIGHT;
        }

        else if (key == "MOUSE_LEFT")
        {
            return EventKey::BUTTON_LEFT;
        }

        else if (key == "MOUSE_RIGHT")
        {
            return EventKey::BUTTON_RIGHT;
        }
        return EventKey::BUTTON_RIGHT;
    }

    // EVENT TYPE

    SDL_EventType fromEventTypeToCode(EventType type)
    {
        switch (type)
        {
        case EventType::KEY_DOWN:
            return SDL_KEYDOWN;
        case EventType::KEY_UP:
            return SDL_KEYUP;
        case EventType::MOUSE_DOWN:
            return SDL_MOUSEBUTTONDOWN;
        case EventType::MOUSE_UP:
            return SDL_MOUSEBUTTONUP;
        case EventType::MOUSE_MOVE:
            return SDL_MOUSEMOTION;
        };
        return SDL_MOUSEMOTION;
    };

    const std::string fromEventTypeToString(EventType type)
    {
        switch (type)
        {
        case EventType::KEY_DOWN:
            return "KEY_DOWN";
        case EventType::KEY_UP:
            return "KEY_UP";
        case EventType::MOUSE_DOWN:
            return "MOUSE_DOWN";
        case EventType::MOUSE_UP:
            return "MOUSE_UP";
        case EventType::MOUSE_MOVE:
            return "MOUSE_MOVE";
        };

        return "";
    }
    EventType fromStrToEventType(const std::string &eventIn)
    {
        std::string event = eventIn;
        std::transform(event.begin(), event.end(), event.begin(), ::toupper);
        if (event == "KEY_DOWN")
        {
            return EventType::KEY_DOWN;
        }
        else if (event == "KEY_UP")
        {
            return EventType::KEY_UP;
        }

        else if (event == "MOUSE_DOWN")
        {
            return EventType::MOUSE_DOWN;
        }
        else if (event == "MOUSE_UP")
        {
            return EventType::MOUSE_UP;
        }
        else if (event == "MOUSE_MOVE")
        {
            return EventType::MOUSE_MOVE;
        }
        return EventType::MOUSE_MOVE;
    }

    /// ENDEVENTTYPE

    const std::string fromInputDeviceToStr(EventInputDevice device)
    {
        switch (device)
        {
        case EventInputDevice::KEY:
            return "KEY";
        case EventInputDevice::MOUSE:
            return "MOUSE";
        default:
            return "NONE";
        }
        return "";
    }

    EventInputDevice fromStringToInputDevice(const std::string &deviceIn)
    {
        std::string device = deviceIn;
        std::transform(device.begin(), device.end(), device.begin(), ::toupper);
        if (device == "KEY")
        {
            return EventInputDevice::KEY;
        }
        else if (device == "MOUSE")
        {
            return EventInputDevice::MOUSE;
        }
        return EventInputDevice::NONE;
    }
}
