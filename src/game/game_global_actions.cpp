#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "game/game_global_actions.hpp"
#include "action/action_data.hpp"
GameGlobalActions::GameGlobalActions(/* args */)
{
}

GameGlobalActions::~GameGlobalActions()
{
    for (auto &v : m_globalActions)
    {
        delete v;
    }
}

void GameGlobalActions::loadActions(const std::string &filename)
{
    using json = nlohmann::json;
    std::fstream file(filename);
    std::stringstream stream;
    stream << file.rdbuf();
    json parsed = nlohmann::json::parse(stream);
    std::string type, state;

    for (const auto &el : parsed["Actions"])
    {
        action ::ActionType tmpAT = action::getActionTypeFromString(el["type"]);
        action::ActionState tmpAS = action::getActionStateFromString(el["state"]);

        m_globalActions.push_back(new Action(tmpAT, tmpAS));
        std::cout << "Action" << el["type"] << " " << el["state"] << "\n";
    }
}

Action *GameGlobalActions::getActionByFullString(const std::string &actionName)
{
    for (auto &i : m_globalActions)
    {
        if (i->getActionName() == actionName)
        {
            return i;
        }
    }
    return nullptr;
}
