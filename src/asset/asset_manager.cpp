#include <string>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>
#include "asset/asset_manager.hpp"
#include "asset/asset.hpp"
#include "asset/asset_data.hpp"
#include "asset/asset_font.hpp"
AssetManager::AssetManager(/* args */)
{
    m_assetsMap.insert({asset::AssetType::TEXTURE, {}});
    m_assetsMap.insert({asset::AssetType::FONT, {}});
    m_assetsMap.insert({asset::AssetType::SOUND, {}});
    m_assetsMap.insert({asset::AssetType::VIDEO, {}});
}

AssetManager::~AssetManager()
{
    for (const auto &[k, v] : m_assetsMap)
    {
        for (const auto e : v)
        {
            delete e;
        }
    }
}

std::vector<Asset *> &AssetManager::getAssetsByType(asset::AssetType assetType)
{
    return m_assetsMap[assetType];
}
Asset *AssetManager::getAsset(asset::AssetType assetType, asset::AssetName assetName)
{

    for (const auto &el : m_assetsMap[assetType])
    {
        if (el->getAssetGlobalName() == assetName)
        {

            return el;
        }
    }

    return nullptr;
}
void AssetManager::loadAssets(uint16_t levelId)
{
    // if nothing is passed as levelId asset manager should build global assets pack

    const std::string filepath = (levelId > 0) ? "./input/levels/" + std::to_string(levelId) + "/assets.json"
                                               : "./input/g_assets.json";

    using json = nlohmann::json;
    std::fstream file(filepath);
    std::stringstream stream;
    stream << file.rdbuf();
    json parsedStream = nlohmann::json::parse(stream);
    for (const auto &obj : parsedStream["Assets"])
    {
        asset::AssetType type = asset::fromStringToAssetType(obj["type"]);
        asset::AssetName name = asset::fromStringToAssetName(obj["name"]);
        switch (type)
        {
        case asset::AssetType::FONT:
        {
            std::cout << "Found font " << obj["name"] << "loading..."
                      << "\n";
            m_assetsMap[asset::AssetType::FONT].push_back(new AssetFont(obj["path"], name));
            break;
        }
        case asset::AssetType::TEXTURE:
        {
            /* code */
            break;
        }

        default:
            break;
        }
    }
}

void AssetManager::deleteAssets()
{
    for (const auto &[k, v] : m_assetsMap)
    {

        for (const auto &e : v)
        {
            if (e != nullptr)
            {

                delete e;
            }
        }
    }
}
