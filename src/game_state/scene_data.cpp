#include <string>
#include "game_state/scene_data.hpp"
namespace scene
{

    SceneType fromStringToSceneType(const std::string &sceneType)
    {

        std::string typeTmp = sceneType;

        if (typeTmp == "MENU")
        {
            return SceneType::MENU;
        }
        else if (typeTmp == "PLAY")
        {
            return SceneType::PLAY;
        }
        else if (typeTmp == "CREDITS")
        {
            return SceneType::CREDITS;
        }
        else if (typeTmp == "INTRO")
        {
            return SceneType::INTRO;
        }
        return SceneType::NONE;
    }

    std::string fromSceneTypeToString(SceneType sceneType)
    {
        switch (sceneType)
        {

        case SceneType::MENU:
            return "MENU";
        case SceneType::PLAY:
            return "PLAY";
        case SceneType::CREDITS:
            return "CREDITS";
        case SceneType::INTRO:
            return "INTRO";
        }
        return "NONE";
    }

}
