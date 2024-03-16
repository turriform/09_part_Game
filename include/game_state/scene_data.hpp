#if !defined(SCENE_DATA_HPP)
#define SCENE_DATA_HPP
#include <string>
namespace scene
{
    enum class SceneType
    {
        NONE,
        MENU,
        PLAY,
        INTRO,
        CREDITS

    };

    SceneType fromStringToSceneType(const std::string &sceneType);
 
    std::string fromSceneTypeToString(SceneType sceneType);
  

}

#endif // SCENE_DATA_HPP
