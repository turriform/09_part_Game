#if !defined(GAME_LEVEL_HPP)
#define GAME_LEVEL_HPP
#include <cstdint>

#include "entity_manager.hpp"

#include "game_state/scene_data.hpp"
class Level
{
private:
    uint16_t m_levelId;
    scene::SceneType m_sceneType = scene::SceneType::NONE;
    EntityManager m_entityManager;

    void _loadLevelEntities();
    void _flushLevelEntities();

public:
    Level(uint16_t levelId, scene::SceneType sceneType);
    ~Level();

    inline scene::SceneType getSceneType() { return m_sceneType; }
    inline EntityManager &getEntityManager() { return m_entityManager; }

    void init();
    void load();
    void flush();
};

#endif // GAME_LEVEL_HPP
