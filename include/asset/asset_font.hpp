#if !defined(ASSET_FONT_HPP)
#define ASSET_FONT_HPP
#include <string>
#include <cstdint>
#include <SDL2/SDL_ttf.h>

#include "asset.hpp"

class AssetFont : public Asset
{
private:
    TTF_Font *m_font;
    uint8_t m_size = 15;

public:
    AssetFont(const std::string &resource, asset::AssetName assetName);
    ~AssetFont();
    AssetFont(const AssetFont &rhs);
    AssetFont &operator=(const AssetFont &rhs);
    inline TTF_Font *getFont() { return m_font; };
    void closeFont();
};

#endif // ASSET_FONT_HPP
