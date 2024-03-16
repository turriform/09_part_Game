#include <string>
#include <cstdint>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "asset/asset_data.hpp"
#include "asset/asset_font.hpp"

AssetFont::AssetFont(const std::string &resource, asset::AssetName assetName) : Asset(resource, assetName)
{

    std::cout << "AssetFont +"
              << "\n";
    m_assetType = asset::AssetType::FONT;
    m_font = TTF_OpenFont(m_resourcePath.c_str(), m_size);
    if (m_font)
    {
        std::cout << "Asset font: " << m_resourcePath << ": font loaded Successfully"
                  << "\n";
    }
    else
    {
        std::cout << SDL_GetError() << "Asset didnt load"
                  << "\n";
    }
}

AssetFont::AssetFont(const AssetFont &rhs) : Asset(rhs.m_resourcePath, rhs.m_assetName)
{
    std::cout << "AssetFont copy constr called"
              << "\n";

    m_font = rhs.m_font;
    m_assetName = rhs.m_assetName;
    m_assetType = rhs.m_assetType;
    m_size = rhs.m_size;
}
AssetFont &AssetFont::operator=(const AssetFont &rhs)
{
    std::cout << "AssetFont assignment constr called"
              << "\n";

    if (this == &rhs)
    {
        return *this;
    }
    else
    {
        m_resourcePath = rhs.m_resourcePath;
        m_font = rhs.m_font;
        m_assetName = rhs.m_assetName;
        m_assetType = rhs.m_assetType;
        m_size = rhs.m_size;
    }
    return *this;
}

AssetFont::~AssetFont()

{
    if (m_font != nullptr)
    {
        TTF_CloseFont(m_font);
    }
}

void AssetFont::closeFont()
{
    if (m_font != nullptr)
    {
        TTF_CloseFont(m_font);
    }
}