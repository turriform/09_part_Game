#include "action/action.hpp"
#include "action/action_data.hpp"

Action::Action(/* args */)
{
}

Action::Action(action::ActionType actionType, action::ActionState actionState)
    : m_actionType(actionType), m_actionState(actionState)
{
    m_actionStrName = action::getStringFromActionType(actionType) + "_" +
                      action::getStringFromActionState(actionState);
}

Action::~Action()
{
}
