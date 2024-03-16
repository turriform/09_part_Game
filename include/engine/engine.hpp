#if !defined(LOCAL_ENGINE_HPP)
#define LOCAL_ENGINE_HPP
#include "sdl_window.hpp"
#include "../game_state/game_state.hpp"

class Engine
{
private:
    SDLWindow * m_SDLWindow;
    GameState * m_gameState;
public:
    Engine(/* args */);
    ~Engine();
    void start();
};




#endif // LOCAL_ENGINE_HPP
