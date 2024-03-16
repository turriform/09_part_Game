#include <cstdint>
#include "level/level.hpp"
#include "game_state/scene_data.hpp"

Level::Level(uint16_t levelId, scene::SceneType sceneType) : m_levelId(levelId), m_sceneType(sceneType)
{
}

Level::~Level()
{
}




void Level::load()
{
    std::cout << "LEVEL " << m_levelId << " LOADING..." << std::endl;
    _loadLevelEntities();
}

void Level::flush()
{
    std::cout << "LEVEL " << m_levelId << " FLUSHING..." << std::endl;
    _flushLevelEntities();
}

void Level::_loadLevelEntities()
{
    std::string sceneT;
    switch (m_sceneType)
    {
    case scene::SceneType::MENU:
        sceneT = "menu";
        break;

    default:
        sceneT = "levels";
        break;
    }

    const std::string entitiesFilepath = "input/" + sceneT + "/" + std::to_string(m_levelId) + "/entities.json";
    std::fstream file(entitiesFilepath);
    std::stringstream stream;

    stream << file.rdbuf();
    using json = nlohmann::json;
    entity::EntityInitialData initalData;

    json parsed = nlohmann::json::parse(stream);
    for (const auto &e : parsed)
    {
        initalData.parseJsonOject(e);

        m_entityManager.addEntity(initalData);
        initalData.print();
    }

    // for (auto vec : m_levelMap.getEntityMap())
    // {
    //     for (auto e : vec)
    //     {
    //         m_entityManager.addEntity(e);
    //         e.print();
    //     }
    // }

    file.close();
}

void Level::_flushLevelEntities()
{
}


