#include "engine/engine.hpp"
#include "engine/sdl_window.hpp"
#include "game_state/game_state.hpp"

Engine::Engine(/* args */):m_SDLWindow(nullptr), m_gameState(nullptr)
{   
    m_SDLWindow = new SDLWindow;
    m_gameState = new GameState(m_SDLWindow);
}

Engine::~Engine()
{
    delete m_SDLWindow;
    delete m_gameState;
}

void Engine::start(){

    m_gameState->run();
}

