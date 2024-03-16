#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "level/level.hpp"
#include "game/game_level_manager.hpp"
#include "game_state/scene_data.hpp"
GameLevelManager::GameLevelManager(/* args */)
{
}

GameLevelManager::~GameLevelManager()
{
    for (auto &[k, v] : m_levelMap)
    {
        delete v;
    }
}

Level *GameLevelManager::getCurrentLevel() { return m_currentLevel; }



void GameLevelManager::switchLevel(uint16_t levelId) { m_currentLevel = m_levelMap[levelId]; }
void GameLevelManager::loadLevels(const std::string &path)
{
    std::fstream file(path);
    std::stringstream stream;
    if (file.is_open())
    {
        stream << file.rdbuf();
    }
    using json = nlohmann::json;
    json parsedStream = nlohmann::json::parse(stream);

    for (const auto &el : parsedStream["Levels"])
    {
        uint16_t idTmp = el["id"];
        std::string sceneTmp = el["scene"];
        scene::SceneType sceneType = scene::fromStringToSceneType(sceneTmp);
        m_levelMap.insert({idTmp, new Level(idTmp, sceneType)});
        std::cout << "Level with id " << idTmp << " has been loaded  " << (int)sceneType << std::endl;
    }
    file.close();
    m_currentLevel = m_levelMap[1];
}