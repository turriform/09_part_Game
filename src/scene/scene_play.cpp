#include "scene/scene.hpp"
#include "scene/scene_play.hpp"
#include "game_state/game_state.hpp"
class GameState;
ScenePlay::ScenePlay(GameState *gameState) : Scene(gameState)
{
    m_sceneType = scene::SceneType::PLAY;
}

ScenePlay::~ScenePlay()
{
}

void ScenePlay::run()
{
    update();
    event();
    render();
    SDL_Delay(int(1000 / 60));
}

void ScenePlay::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 10, 200, 255);
    SDL_RenderClear(m_renderer);

    for (const auto &e : m_gameState->getLevel()->getEntityManager().getEntities())
    {

        auto &shape = e->getComponent<ShapeComponent>();
        shape.render(m_renderer);
        auto &label = e->getComponent<LabelComponent>();
        if (label.exists)
        {
            label.pullFont(m_gameState->getGame()->getGameAssetManager());
            label.prepare();
            label.render(m_renderer);
        }
    }
    SDL_RenderPresent(m_renderer);
    for (const auto &e : m_gameState->getLevel()->getEntityManager().getEntities())
    {
        auto &label = e->getComponent<LabelComponent>();

        if (label.exists)
        {
            label.clean();
        }
    }
}

void ScenePlay::event()
{

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        for (const auto &[a, e] : m_sceneActionManager.getActionEventMap())
        {
            if (event.type == e->getEventType() && event.key.keysym.sym == e->getEventCode())
            {
                if (a->getActionType() == action::ActionType::PLAY_EXIT)
                {

                    m_gameState->getGame()->setIsRunning();
                    return;
                }
                else if (a->getActionType() == action::ActionType::PLAY_MENU)
                {
                    m_gameState->switchLevel(1);
                }
            }
        }
    }
}

void ScenePlay::update()
{

    m_gameState->getLevel()->getEntityManager().onFrameUpdateEntities();
    for (const auto &e : m_gameState->getLevel()->getEntityManager().getEntities())
    {

        auto &shape = e->getComponent<ShapeComponent>();
        shape.draw(m_renderer);
    }
}