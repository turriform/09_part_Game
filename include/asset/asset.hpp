#if !defined(ASSET_HPP)
#define ASSET_HPP
#include <string>
#include "asset/asset_data.hpp"
class Asset
{
protected:
    std::string m_resourcePath;
    asset::AssetType m_assetType;
    asset::AssetName m_assetName;

public:
    Asset(const std::string &resource, asset::AssetName assetName);
    virtual ~Asset() = 0;
    inline asset::AssetName getAssetGlobalName() { return m_assetName; }
    inline asset::AssetType getAssetType() { return m_assetType; }
};

#endif // ASSET_HPP
