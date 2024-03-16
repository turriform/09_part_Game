#include "game/game_scene_manager.hpp"
#include "game_state/game_state.hpp"
#include "scene/scene.hpp"
#include "game/game.hpp"
#include "game/game_2d.hpp"

Game2d::Game2d(GameState* gameState):Game(gameState)
{
}

Game2d::~Game2d()
{
}

void Game2d::run()
{

    while (m_isRunning)
    {
       m_gameState->getScene()->run();
    }

    m_gameState->clean();


}