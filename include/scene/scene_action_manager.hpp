#if !defined(SCENE_ACTION_MANAGER_HPP)
#define SCENE_ACTION_MANAGER_HPP
#include <map>
#include <set>
#include "game/game_global_actions.hpp"
#include "event/event.hpp"
#include "action/action.hpp"
#include "game_state/scene_data.hpp"

class SceneActionManager
{
private:
    std::map<Action *, Event *> m_actionEventMap;
    std::set<Event *> m_takenEvents;

public:
    SceneActionManager();
    ~SceneActionManager();
    void loadActionInputMap(const std::string &path,
                            GameGlobalActions &gameActions,
                            scene::SceneType sceneType);
    inline std::map<Action *, Event *> & getActionEventMap(){return m_actionEventMap;}                       
};

#endif // SCENE_ACTION_MANAGER_HPP
