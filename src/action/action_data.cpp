#include <string>
#include "action/action_data.hpp"
namespace action
{
    std::string getStringFromActionType(ActionType actionType)
    {

        switch (actionType)
        {
        case ActionType::PLAY_BACKWARDS:
            return "PLAY_BACKWARDS";
        case ActionType::PLAY_LEFT:
            return "PLAY_LEFT";
        case ActionType::PLAY_RIGHT:
            return "PLAY_RIGHT";
        case ActionType::PLAY_FORWARD:
            return "PLAY_FORWARD";
        case ActionType::PLAY_MENU:
            return "PLAY_MENU";
        case ActionType::PLAY_EXIT:
            return "PLAY_EXIT";
        case ActionType::MENU_START:
            return "MENU_START";
        case ActionType::MENU_RESUME:
            return "MENU_RESUME";
        case ActionType::MENU_EXIT:
            return "MENU_EXIT";
        case ActionType::MENU_PLAY:
            return "MENU_PLAY";
        case ActionType::MENU_SWITCH_TO_LEVEL_ID:
            return "MENU_SWITCH_TO_LEVEL_ID";
        default:
            return "NONE";
        }
        return "NONE";
    }

    ActionType getActionTypeFromString(const std::string &type)
    {
        if (type == "PLAY_BACKWARDS")
        {
            return ActionType::PLAY_BACKWARDS;
        }
        else if (type == "PLAY_LEFT")
        {
            return ActionType::PLAY_LEFT;
        }
        else if (type == "PLAY_RIGHT")
        {
            return ActionType::PLAY_RIGHT;
        }
        else if (type == "PLAY_FORWARD")
        {
            return ActionType::PLAY_FORWARD;
        }
        else if (type == "PLAY_MENU")
        {
            return ActionType::PLAY_MENU;
        }
        else if (type == "PLAY_EXIT")
        {
            return ActionType::PLAY_EXIT;
        }

        else if (type == "MENU_START")
        {
            return ActionType::MENU_START;
        }
        else if (type == "MENU_RESUME")
        {
            return ActionType::MENU_RESUME;
        }
        else if (type == "MENU_EXIT")
        {
            return ActionType::MENU_EXIT;
        }
        else if (type == "MENU_PLAY")
        {
            return ActionType::MENU_PLAY;
        }
        else if (type == "MENU_SWITCH_TO_LEVEL_ID")
        {
            return ActionType::MENU_SWITCH_TO_LEVEL_ID;
        }
        return ActionType::NONE;
    }

    std::string getStringFromActionState(ActionState actionState)
    {

        switch (actionState)
        {
        case ActionState::START:
            return "START";
        case ActionState::END:
            return "END";

        default:
            return "NONE";
        }
        return "NONE";
    }

    ActionState getActionStateFromString(const std::string &state)
    {
        if (state == "START")
        {
            return ActionState::START;
        }
        else if (state == "END")
        {
            return ActionState::END;
        }
        return ActionState::NONE;
    }

}