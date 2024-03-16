#if !defined(BASE_SCENE_HPP)
#define BASE_SCENE_HPP
#include <string>
#include "scene_action_manager.hpp"
#include "game_state/scene_data.hpp"
class SDL_Renderer;
class GameState;
class Scene
{
protected:
    GameState *m_gameState;
    SceneActionManager m_sceneActionManager;
    scene::SceneType m_sceneType = scene::SceneType::NONE;
    SDL_Renderer * m_renderer;
    virtual void event() = 0;
    virtual void render() = 0;
    virtual void update() = 0;

public:
    Scene(GameState *gameState);
    virtual ~Scene();
    virtual void run() = 0;

    inline SceneActionManager &getSceneActionManager() { return m_sceneActionManager; }

    void loadActionsForScene(const std::string &filepath);
};

#endif // BASE_SCENE_HPP
