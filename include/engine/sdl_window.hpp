#if !defined(LOCAL_SDL_WINDOW)
#define LOCAL_SDL_WINDOW
#include <SDL2/SDL.h>
#include "engine/game_window.hpp"

class SDLWindow : public GameWindow
{
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

public:
    SDLWindow();
    ~SDLWindow();
    void setWindow() override;

    inline SDL_Renderer *getRenderer() const { return m_renderer; }

    void run();
};

#endif // LOCAL_SDL_WINDOW
