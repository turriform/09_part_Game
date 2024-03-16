#if !defined(ASSET_DATA_HPP)
#define ASSET_DATA_HPP
#include <string>
namespace asset
{
    enum class AssetType
    {
        NONE,
        FONT,
        TEXTURE,
        SOUND,
        VIDEO
    };

    enum class AssetName
    {
        NONE,
        F_G_MAIN,
        F_G_SUB,
        F_G_DEBUG,
        T_G_BG

    };

    const std::string fromAssetTypeToString(AssetType assetType);
    AssetType fromStringToAssetType(const std::string &assetType);

    const std::string fromAssetNameToString(AssetName aseetName);
    AssetName fromStringToAssetName(const std::string &assetType);

}

#endif // ASSET_DATA_HPP
