#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <nlohmann/json.hpp>
#include "game/game_scene_manager.hpp"
#include "game_state/scene_data.hpp"
#include "scene/scene.hpp"
#include "scene/scene_play.hpp"
#include "scene/scene_menu.hpp"

class GameState;

GameSceneManager::GameSceneManager(/* args */)
{
}

GameSceneManager::~GameSceneManager()
{
    for (auto &[k,v]:m_sceneMap){
        delete v;
    }
}

void GameSceneManager::loadScenes(const std::string &path, GameState *gameState)
{
    using json = nlohmann::json;

    std::fstream file(path);
    std::stringstream stream;
    stream << file.rdbuf();
    json jsonParsed = nlohmann::json::parse(stream);
    for (const auto &elem : jsonParsed["Scenes"])
    {
        scene::SceneType typeTmp = scene::fromStringToSceneType(elem["type"]);
        switch (typeTmp)
        {
        case scene::SceneType::MENU:
        {
            std::cout << "Menu found  " << std::endl;
            m_sceneMap.insert({typeTmp, new SceneMenu(gameState)});
            break;
        }
        case scene::SceneType::PLAY:
        {
            std::cout << "Play found  " << std::endl;
            m_sceneMap.insert({typeTmp, new ScenePlay(gameState)});
            break;
        }

        default:
            break;
        }
        file.close();

        // Setting current scene from initial load
        m_currentScene = m_sceneMap[scene::SceneType::MENU];
    }
}

Scene *GameSceneManager::getCurrentScene()
{
    return m_currentScene;
}
void GameSceneManager::switchScene(scene::SceneType sceneType)
{
    m_currentScene = m_sceneMap[sceneType];
}