#if !defined(SCENE_CREDITS_HPP)
#define SCENE_CREDITS_HPP
#include "scene.hpp"
class GameState;
class SceneCredits : public Scene
{
private:
    /* data */
public:
    SceneCredits(GameState *gameState);
    ~SceneCredits();
    void run() override;
};

#endif // SCENE_CREDITS_HPP