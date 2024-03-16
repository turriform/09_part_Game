#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "engine/sdl_window.hpp"

SDLWindow::SDLWindow(/* args */)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL: Failed " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL: OK" << std::endl;
    }

    if (TTF_Init() < 0)
    {
        std::cout << "TTF: Failed " << SDL_GetError();
    }
    else
    {
        std::cout << "TTF: OK" << std::endl;
    }

    m_window = SDL_CreateWindow("SDL",
                                0,
                                0,
                                640,
                                480,
                                SDL_WINDOW_OPENGL);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;


    // TTF_Quit();
    SDL_Quit();
    std::cout << "SDL_Destroyed"
              << "\n";
}

void SDLWindow::setWindow()
{
    std::cout << "window set as SDL"
              << "\n";
};

void SDLWindow::run()
{
}