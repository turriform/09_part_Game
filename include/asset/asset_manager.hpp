#if !defined(ASSET_MANAGER_HPP)
#define ASSET_MANAGER_HPP
#include <string>
#include <unordered_map>
#include <vector>
#include "asset/asset_data.hpp"
#include "asset/asset.hpp"

class AssetManager
{
private:
    std::unordered_map<asset::AssetType, std::vector<Asset *>> m_assetsMap;

public:
    AssetManager();
    ~AssetManager();
    std::vector<Asset *> &getAssetsByType(asset::AssetType assetType);
    Asset *getAsset(asset::AssetType assetType, asset::AssetName assetName);
    void loadAssets(uint16_t levelId = 0);
    void deleteAssets();
};

#endif // ASSET_MANAGER_HPP
