#if !defined(SCENE_INTRO_HPP)
#define SCENE_INTRO_HPP
#include "scene.hpp"
class GameState;
class SceneIntro : public Scene
{
private:
    /* data */
public:
    SceneIntro(GameState *gameState);
    ~SceneIntro();
    void run() override;
};

#endif // SCENE_INTRO_HPP