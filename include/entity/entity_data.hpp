#if !defined(ENTITY_DATA_HPP)
#define ENTITY_DATA_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glm/glm.hpp"
#include "nlohmann/json.hpp"
#include "asset/asset_data.hpp"
#include "action/action_data.hpp"
#include "event/event_data.hpp"
namespace entity
{
    enum class ColorCode
    {
        RED = 0xFFFFFF,
        GREEN = 0x00FF00,
        BLUE = 0x0000FF,

    };
    struct Color
    {
        uint8_t r, g, b, a;

        void set(ColorCode colorCode)
        {

            r = (uint8_t)colorCode / 100000;
            g = ((uint8_t)colorCode / 100) % 100;
            b = (uint8_t)colorCode % 100000;
        }
    };

    enum class EntityType
    {
        DEFAULT,
        ACTOR,
        TILE,
        SHAPE

    };

    enum class EntityTileType
    {
        DEFAULT,
    };

    enum class EntityLabelLocation
    {
        DEFAULT,
        LEFT,
        RIGHT,
        TOP,
        BOTTOM,
        CENTER
    };

    struct EntityRawData
    {
        using json = nlohmann::json;
        std::string type;
        double posX, posY,
            dimX, dimY,
            speedX, speedY,
            accelX, accelY,
            bboxX, bboxY,
            bRad, density,
            volumeC;

        int r, g, b, a;

        void parseLine(const std::string &line)
        {
            std::stringstream stream(line);
            stream >> type >>
                posX >>
                posY >>
                dimX >>
                dimY >>
                speedX >> speedY >>
                accelX >> accelY >>
                bboxX >> bboxY >>
                bRad >> density >>
                volumeC;
        }
    };

    std::string entityTypeToString(EntityType entityType);
    EntityType stringToEnitityType(const std::string &entityType);
    EntityLabelLocation fromStringToLabelLocation(const std::string &labelLocation);
    std::string fromLabelLocationToString(EntityLabelLocation labelLocation);

    struct EntityInitialData
    {
        using json = nlohmann::json;
        EntityType type = EntityType::DEFAULT;
        struct Shape
        {
            bool exists = false;
            glm::vec2 pos = {0, 0};
            glm::vec2 dim = {0, 0};
            short r = 0, g = 0, b = 0, a = 0;
        };
        Shape shape;

        struct Initial
        {
            bool exists = false;
            glm::vec2 pos = {0, 0};
            glm::vec2 dim = {0, 0};
        };
        Initial initial;
        struct Transform
        {
            bool exists = false;
            glm::vec2 pos = {0, 0};
            glm::vec2 velocity = {0, 0};
            glm::vec2 accel = {0, 0};
        };
        Transform transform;
        struct BBox
        {
            bool exists = false;

            glm::vec2 dim = {0, 0}; // if bb > 0 for CBBox
        };

        BBox bbox;

        struct Label
        {
            bool exists = false;
            asset::AssetName fontName = asset::AssetName::F_G_MAIN;
            glm::vec2 pos = {0, 0};
            glm::vec2 dim = {0, 0};
            std::string text = "";
        };

        Label label;

        struct MouseDownEvent
        {
            bool exists = false;
            action::ActionType actionType = action::ActionType::NONE;
            event::EventType eventType = event::EventType::NONE;
        };

        MouseDownEvent mouseDownEvent;

        void parseJsonOject(const json &obj)
        {

            type = stringToEnitityType(obj["type"]);

            if (obj.contains("Initial"))
            {

                initial.exists = true;
                initial.pos = {(int)obj["Initial"]["pos"][0], (int)obj["Initial"]["pos"][1]};
                initial.dim = {(int)obj["Initial"]["dim"][0], (int)obj["Initial"]["dim"][1]};
            }
            if (obj.contains("Transform"))
            {
                transform.exists = (bool)obj["Transform"]["exists"];
                transform.pos = {(int)obj["Transform"]["pos"][0], (int)obj["Transform"]["pos"][1]};
                transform.velocity = {(int)obj["Transform"]["velocity"][0], (int)obj["Transform"]["velocity"][1]};
                transform.accel = {(int)obj["Transform"]["accel"][0], (int)obj["Transform"]["accel"][1]};
            }
            if (obj.contains("Shape"))
            {
                // initial has to exist for each entity so it is ok
                shape.exists = true;
                shape.pos = {(int)obj["Initial"]["pos"][0], (int)obj["Initial"]["pos"][1]};
                shape.dim = {(int)obj["Initial"]["dim"][0], (int)obj["Initial"]["dim"][1]};
                if (obj.contains("ShapeColor"))
                {
                    shape.r = (short)obj["ShapeColor"]["rgba"][0];
                    shape.g = (short)obj["ShapeColor"]["rgba"][1];
                    shape.b = (short)obj["ShapeColor"]["rgba"][2];
                    shape.a = (short)obj["ShapeColor"]["rgba"][3];
                }
            }
            if (obj.contains("Label"))
            {
                label.exists = true;
                asset::AssetName assetName = asset::fromStringToAssetName(obj["Label"]["font"]);
                std::string text = obj["Label"]["text"];
                entity::EntityLabelLocation locX = entity::fromStringToLabelLocation(obj["Label"]["locX"]);
                entity::EntityLabelLocation locY = entity::fromStringToLabelLocation(obj["Label"]["locY"]);
                label.text = obj["Label"]["text"];
                switch (locX)
                {
                case entity::EntityLabelLocation::LEFT:
                {
                    label.pos.x = 0;
                    break;
                }
                case entity::EntityLabelLocation::RIGHT:
                {
                    label.pos.x = (int)(initial.dim.x - label.dim.x);
                    break;
                }
                case entity::EntityLabelLocation::CENTER:
                {
                    label.pos.x = int((initial.dim.x - label.dim.x) / 2);
                    break;
                }

                default:
                {
                    label.pos.x = (int)obj["Label"]["pos"][0] + initial.pos.x;

                    break;
                }
                }

                switch (locY)
                {
                case entity::EntityLabelLocation::TOP:
                {
                    label.pos.y = 0;
                    break;
                }
                case entity::EntityLabelLocation::BOTTOM:
                {
                    label.pos.y = (int)(initial.dim.y - label.dim.y);

                    break;
                }
                case entity::EntityLabelLocation::CENTER:
                {
                    label.pos.y = int((initial.dim.y - label.dim.y) / 2);
                    break;
                }

                default:
                {
                    label.pos.y = (int)obj["Label"]["pos"][1] + initial.pos.y;

                    break;
                }
                }
            }

            if (obj.contains("MouseDownEvent"))
            {
                mouseDownEvent.exists = true;
                mouseDownEvent.actionType = action::getActionTypeFromString(obj["MouseDownEvent"]["actionAttached"]);

              
            }
        }

        void print()
        {
            std::cout << "type: " << (int)type << "\n";
            std::cout << "Shape: " << shape.pos.x << " " << shape.pos.y << "\n";
            std::cout << "Shape: " << shape.dim.x << " " << shape.dim.y << "\n\n";

            if (label.exists)
            {
                std::cout << "label: " << label.text << "\n";
            }
        }
    };

}

#endif // ENTITY_DATA_HPP
