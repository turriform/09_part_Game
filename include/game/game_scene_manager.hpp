#if !defined(GAME_SCENE_MANAGER_HPP)
#define GAME_SCENE_MANAGER_HPP
#include <memory>
#include <unordered_map>
#include "game_state/scene_data.hpp"

class Game;
class Scene;
class GameState;

class GameSceneManager
{
public:
    GameSceneManager();
    ~GameSceneManager();
    void loadScenes(const std::string &path, GameState *gameState);

    Scene* getSceneByType(scene::SceneType sceneType);
    Scene* getCurrentScene();
    void switchScene(scene::SceneType sceneType);

private:
    std::unordered_map<scene::SceneType, Scene*> m_sceneMap;
    Scene* m_currentScene;
};


#endif // GAME_SCENE_MANAGER_HPP



