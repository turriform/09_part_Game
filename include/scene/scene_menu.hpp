#if !defined(SCENE_MENU_HPP)
#define SCENE_MENU_HPP
#include "scene.hpp"
class GameState;
class SceneMenu : public Scene
{
private:
    /* data */
public:
    SceneMenu(GameState *gameState);
    ~SceneMenu();
    void run() override;
    void render() override;
    void event() override;

    void update() override;
};

#endif // SCENE_MENU_HPP
