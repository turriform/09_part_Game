#if !defined(LOCAL_WINDOW_HPP)
#define LOCAL_WINDOW_HPP
#include <cstdint>

class WindowData
{
public:
    uint16_t posX = 0;
    uint16_t posY = 0;
    uint16_t width = 500;
    uint16_t height = 500;

    WindowData(){};
};

class GameWindow
{
public:
    GameWindow();
    virtual ~GameWindow();

    

protected:
    WindowData m_windowData;

    virtual void setWindow() = 0;
};

#endif // LOCAL_WINDOW_HPP
