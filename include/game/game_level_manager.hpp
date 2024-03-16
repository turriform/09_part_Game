#if !defined(GAME_LEVEL_MANAGER)
#define GAME_LEVEL_MANAGER
#include <vector>
#include <cstdint>
#include <unordered_map>
#include "game_state/scene_data.hpp"
class Level;
class GameLevelManager
{
private:
    std::unordered_map<uint16_t, Level *> m_levelMap;
    std::unordered_map<scene::SceneType, std::vector<Level*>> m_bySceneLevelMap;
    
    Level *m_currentLevel = nullptr;

public:
    GameLevelManager();
    ~GameLevelManager();
    Level *getCurrentLevel();
    
    std::vector<Level *>& getLevelsByScene(scene::SceneType sceneType);
    void switchLevel(uint16_t levelId);
    void loadLevels(const std::string &path);
};

#endif // GAME_LEVEL_MANAGER
