#if !defined(GAME_GLOBAL_ACTIONS_HPP)
#define GAME_GLOBAL_ACTIONS_HPP
#include <string>
#include <vector>
#include "action/action.hpp"

class GameGlobalActions
{
private:
    std::vector<Action *> m_globalActions;

public:
    GameGlobalActions(/* args */);
    ~GameGlobalActions();
    void loadActions(const std::string &filename);
    Action * getActionByFullString(const std::string&actionName);
};

#endif // GAME_GLOBAL_ACTIONS_HPP
