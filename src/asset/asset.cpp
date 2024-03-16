#include <string>
#include "asset/asset.hpp"
#include "asset/asset_data.hpp"
Asset::Asset(const std::string &resource, asset::AssetName assetName)
    : m_resourcePath(resource),
      m_assetName(assetName)
{
}

Asset::~Asset()
{
}