#if !defined(BASE_ACTION_HPP)
#define BASE_ACTION_HPP
#include "action_data.hpp"
class Action
{

private:
    action::ActionType m_actionType = action::ActionType::NONE;
    action::ActionState m_actionState = action::ActionState::NONE;
    std::string m_actionStrName;

public:
    Action();
    Action(action::ActionType actionType, action::ActionState actionState);
    ~Action();
    inline bool operator==(const Action &rhs) const { return m_actionStrName == rhs.m_actionStrName; }
    inline const std::string &getActionName() const { return m_actionStrName; }
    inline action::ActionType getActionType() { return m_actionType; }
    inline action::ActionState getActionState() { return m_actionState; }
};

#endif // BASE_ACTION_HPP
