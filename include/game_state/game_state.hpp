#if !defined(GAME_STATE_HPP)
#define GAME_STATE_HPP
#include <cstdint>
#include "engine/sdl_window.hpp"
#include "game/game.hpp"
#include "scene/scene.hpp"
#include "level/level.hpp"
class SDL_Renderer;
class GameState
{
private:
    SDLWindow *m_SDLWindow;
    Game *m_game;
    Scene *m_scene;
    Level *m_level;

public:
    GameState(SDLWindow *SDLWindow);
    ~GameState();

    inline SDLWindow *getWindow() { return m_SDLWindow; }
    inline  SDL_Renderer *getRenderer() { return m_SDLWindow->getRenderer(); }
    Game * getGame() const;
    Scene * getScene() const;
    Level * getLevel() const;

    void run();

    void initialLoad();

    void switchLevel(uint16_t levelId);

    void clean();

};

#endif // GAME_STATE_HPP
