#if !defined(SCENE_PLAY_HPP)
#define SCENE_PLAY_HPP
#include "scene.hpp"
class GameState;
class ScenePlay : public Scene
{
private:
    /* data */
public:
    ScenePlay(GameState *gameState);
    ~ScenePlay();
    void run() override;
    void render() override;
    void event() override;

    void update() override;
};

#endif // SCENE_PLAY_HPP