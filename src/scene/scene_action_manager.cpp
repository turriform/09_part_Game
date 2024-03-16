#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>
#include "scene/scene_action_manager.hpp"
#include "game_state/scene_data.hpp"
#include "event/event.hpp"
#include "action/action.hpp"
#include "event/event_data.hpp"
#include "action/action_data.hpp"
#include "game_state/scene_data.hpp"

SceneActionManager::SceneActionManager(/* args */)
{
}

SceneActionManager::~SceneActionManager()
{
    for (auto &[action, event] : m_actionEventMap)
    {
        delete event;
    }
}
void SceneActionManager::loadActionInputMap(const std::string &filepath,
                                            GameGlobalActions &gameActions,
                                            scene::SceneType sceneType)
{

    std::fstream file(filepath);
    std::stringstream stream;

    stream << file.rdbuf();
    using json = nlohmann::json;
    json parsedStream = nlohmann::json::parse(stream);

    std::string actionName, actionState, inputDevice, eventType, eventKey;

    for (const auto &el : parsedStream[scene::fromSceneTypeToString(sceneType)])
    {
        actionName = el["type"];
        actionState = el["state"];
        Action *actionExists = gameActions.getActionByFullString(
            actionName + "_" + actionState);

        if (actionExists != nullptr)
        {

            std::cout << "Action found and registered"
                      << "\n";
            inputDevice = el["inputDevice"];
            eventType = el["eventType"];
            eventKey = el["key"];

            event::EventInputDevice tmpInputD = event::fromStringToInputDevice(inputDevice);
            event::EventType tmpEvT = event::fromStrToEventType(eventType);
            event::EventKey tmpEvK = event::fromStrToEventKey(eventKey);

            m_actionEventMap.insert({actionExists, new Event(tmpInputD, tmpEvT, tmpEvK)});
        }
        else

        {
            std::cout << "Action for scene is not found"
                      << "\n";
        }
    }
}
