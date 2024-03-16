#include <algorithm>
#include <string>
#include "asset/asset_data.hpp"

namespace asset
{
    const std::string fromAssetTypeToString(AssetType assetType)
    {

        switch (assetType)
        {
        case AssetType::FONT:
            return "FONT";
        case AssetType::TEXTURE:
            return "IMAGE";
        case AssetType::VIDEO:
            return "VIDEO";
        case AssetType::SOUND:
            return "SOUND";

        default:
            return "FONT";
        }
    }
    AssetType fromStringToAssetType(const std::string &assetType)
    {
        std::string typeTmp = assetType;
        std::transform(typeTmp.begin(), typeTmp.end(), typeTmp.begin(), ::toupper);

        if (typeTmp == "FONT")
        {
            return AssetType::FONT;
        }

        else if (typeTmp == "VIDEO")
        {
            return AssetType::VIDEO;
        }
        else if (typeTmp == "TEXTURE")
        {
            return AssetType::TEXTURE;
        }
        else if (typeTmp == "SOUND")
        {
            return AssetType::SOUND;
        }

        return AssetType::NONE;
    }

    const std::string fromAssetNameToString(AssetName assetName)
    {
        switch (assetName)
        {
        case AssetName::F_G_MAIN:
            return "F_G_MAIN";
        case AssetName::F_G_SUB:
            return "F_G_SUB";
        case AssetName::F_G_DEBUG:
            return "F_G_DEBUG";
        case AssetName::T_G_BG:
            return "T_G_BG";

        default:
            return "NONE";
        }
    }
    AssetName fromStringToAssetName(const std::string &assetName)
    {
        if (assetName == "F_G_MAIN")
        {
            return AssetName::F_G_MAIN;
        }
        else if (assetName == "F_G_SUB")
        {
            return AssetName::F_G_SUB;
        }
        else if (assetName == "F_G_DEBUG")
        {
            return AssetName::T_G_BG;
        }

        return AssetName::NONE;
    }

}
