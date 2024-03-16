#if !defined(ACTION_DATA_HPP)
#define ACTION_DATA_HPP

#include <string>
namespace action
{

    enum class ActionType
    {
        NONE,
        PLAY_LEFT,
        PLAY_RIGHT,
        PLAY_FORWARD,
        PLAY_BACKWARDS,
        PLAY_MENU,
        PLAY_EXIT,
        MENU_START,
        MENU_PLAY,
        MENU_RESUME,
        MENU_EXIT,
        MENU_SWITCH_TO_LEVEL_ID

    };
    enum class ActionState
    {
        NONE,
        START,
        END
    };

    std::string getStringFromActionType(ActionType actionType);

    ActionType getActionTypeFromString(const std::string &type);

    std::string getStringFromActionState(ActionState actionState);

    ActionState getActionStateFromString(const std::string &state);

}



#endif // ACTION_DATA_HPP
