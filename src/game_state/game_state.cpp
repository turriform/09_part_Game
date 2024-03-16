#include "game_state/game_state.hpp"
#include "engine/sdl_window.hpp"
#include "game/game_2d.hpp"
#include "scene/scene_menu.hpp"
GameState::GameState(SDLWindow *sdlWindow) : m_SDLWindow(sdlWindow)
{
    // Initial state defined as
    // SceneMenu with level 1
    m_game = new Game2d(this);
    initialLoad();
}

GameState::~GameState()
{
    delete m_game;
}

void GameState::run()
{
    m_game->run();
}
Game *GameState::getGame() const
{
    return m_game;
}
Scene *GameState::getScene() const
{
    return m_scene;
}
Level *GameState::getLevel() const
{
    return m_level;
}

void GameState::initialLoad()
{
    m_game->getGameGlobalActions().loadActions("input/g_actions.json");
    m_game->getGameSceneManager().loadScenes("input/g_scenes.json", this);
    m_game->getGameAssetManager().loadAssets();
    m_scene = m_game->getGameSceneManager().getCurrentScene();
    m_scene->loadActionsForScene("input/g_defaultMappings.json");
    m_game->getGameLevelManager().loadLevels("input/g_levels.json");
    m_level = m_game->getGameLevelManager().getCurrentLevel();
    m_level->load();
}

void GameState::switchLevel(uint16_t levelId)
{
    

    m_game->getGameLevelManager().switchLevel(levelId);
    m_level = m_game->getGameLevelManager().getCurrentLevel();
    m_game->getGameSceneManager().switchScene(m_level->getSceneType());
    m_scene = m_game->getGameSceneManager().getCurrentScene();
    m_scene->loadActionsForScene("input/g_defaultMappings.json");
    m_level->load();

}

void GameState::clean(){
}