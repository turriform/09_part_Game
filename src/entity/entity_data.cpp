#include "entity/entity_data.hpp"
#include <string>

namespace entity
{
    std::string entityTypeToString(EntityType entityType)
    {
        switch (entityType)
        {
        case EntityType::ACTOR:
            return "ACTOR";
        case EntityType::TILE:
            return "TILE";
        case EntityType::SHAPE:
            return "SHAPE";
        }
        return "DEFAULT";
    }
    EntityType stringToEnitityType(const std::string &entityType)
    {
        if (entityType == "ACTOR")
        {
            return EntityType::ACTOR;
        }
        else if (entityType == "TILE")
        {
            return EntityType::TILE;
        }
        else if (entityType == "SHAPE")
        {
            return EntityType::SHAPE;
        }
        return EntityType::DEFAULT;
    }

    std::string fromLabelLocationToString(EntityLabelLocation labelLocation)
    {
        switch (labelLocation)
        {
        case EntityLabelLocation::TOP:
            return "TOP_LEFT";
        case EntityLabelLocation::RIGHT:
            return "TOP_RIGHT";
        case EntityLabelLocation::BOTTOM:
            return "BOTTOM_LEFT";
        case EntityLabelLocation::LEFT:
            return "BOTTOM_RIGHT";
        case EntityLabelLocation::CENTER:
            return "CENTER";
        }
        return "DEFAULT";
    }

    EntityLabelLocation fromStringToLabelLocation(const std::string &labelLocation)
    {
        if (labelLocation == "TOP")
        {
            return EntityLabelLocation::TOP;
        }
        else if (labelLocation == "LEFT")
        {
            return EntityLabelLocation::LEFT;
        }
        else if (labelLocation == "TOP_RIGHT")
        {
            return EntityLabelLocation::BOTTOM;
        }
        else if (labelLocation == "BOTTOM_RIGHT")
        {
            return EntityLabelLocation::RIGHT;
        }
        else if (labelLocation == "CENTER")
        {
            return EntityLabelLocation::CENTER;
        }
        return EntityLabelLocation::DEFAULT;
    }

 

}