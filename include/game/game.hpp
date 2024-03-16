#if !defined(GAME_BASE_HPP)
#define GAME_BASE_HPP
#include "game_scene_manager.hpp"
#include "game_level_manager.hpp"
#include "game_global_actions.hpp"
#include "asset/asset_manager.hpp"
class Game
{

public:
    Game(GameState *gameState);
    virtual ~Game();
    virtual void run() = 0;
    inline bool setIsRunning() { return m_isRunning = !m_isRunning; }

    inline GameSceneManager &getGameSceneManager() { return m_gameSceneManager; }
    inline GameLevelManager &getGameLevelManager() { return m_gameLevelManager; }
    inline GameGlobalActions &getGameGlobalActions() { return m_gameGlobalActions; }
    inline AssetManager &getGameAssetManager() { return m_gameAssetManager; }
    inline bool isGameRunning() { return m_isRunning; }

protected:
    bool m_isRunning = true;
    GameState *m_gameState;
    GameSceneManager m_gameSceneManager;
    GameLevelManager m_gameLevelManager;
    GameGlobalActions m_gameGlobalActions;
    AssetManager m_gameAssetManager;
};

#endif // GAME_BASE_HPP
