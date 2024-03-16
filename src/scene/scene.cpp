#include "scene/scene.hpp"
#include "game_state/game_state.hpp"
Scene::Scene(GameState *gameState)
{
    m_gameState = gameState;
    m_renderer = gameState->getRenderer();
}
Scene::~Scene()
{
}

void Scene::loadActionsForScene(const std::string &filepath)
{

    m_sceneActionManager.loadActionInputMap(
        filepath, m_gameState->getGame()->getGameGlobalActions(), m_sceneType);
}
