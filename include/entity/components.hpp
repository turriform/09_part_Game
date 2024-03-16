#if !defined(COMPONENTS_HPP)
#define COMPONENTS_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "glm/glm.hpp"
#include "entity/entity.hpp"
#include "entity/entity_data.hpp"
#include "asset/asset_font.hpp"
#include "asset/asset_data.hpp"
#include "asset/asset_manager.hpp"
#include "entity/IRenderable.hpp"
#include "action/action_data.hpp"
#include "event/event_data.hpp"
using namespace entity;
class Component
{

public:
    Component(){};
    virtual ~Component(){};
    void assign(){};
    bool exists = false;
};

class InitialComponent : public Component
{
public:
    glm::vec2 pos = {0, 0};
    glm::vec2 dim = {0, 0};

    InitialComponent(){};
    ~InitialComponent(){};
    void assign(EntityInitialData::Initial initial)
    {
        exists = initial.exists;
        pos = initial.pos;
        dim = initial.dim;
    }
};

class TransformComponent : public Component
{
public:
    glm::vec2 pos = {0, 0};
    glm::vec2 velocity = {0, 0};
    glm::vec2 accel = {0, 0};

    TransformComponent() {}
    ~TransformComponent() {}

    void assign(EntityInitialData::Transform transform)
    {
        exists = transform.exists;
        pos = transform.pos;
        velocity = transform.velocity;
        accel = transform.accel;
    }
};

class BBoxComponent : public Component
{
public:
    glm::vec2 dims = {0, 0};

    BBoxComponent() {}
    ~BBoxComponent() {}

    void assign(EntityInitialData::BBox bbox)
    {

        exists = bbox.exists;
        dims = bbox.dim;
    }
};

class LabelComponent : public Component
{
public:
    asset::AssetName fontName = asset::AssetName::F_G_MAIN;
    glm::vec2 pos = {0, 0};
    glm::vec2 dim = {0, 0};
    std::string text = "";

    SDL_Surface *surfaceMessage = nullptr;
    SDL_Texture *message = nullptr;
    SDL_Color white = {255, 255, 255, 255};

    TTF_Font *font = nullptr;
    SDL_Rect dest;
    uint8_t padding = 10;

    LabelComponent() {}
    ~LabelComponent()
    {
    }

    void assign(EntityInitialData::Label label)
    {
        exists = label.exists;
        fontName = label.fontName;
        pos = label.pos;
        dim = label.dim;
        text = label.text;
    }

    void pullFont(AssetManager &asseetManager)
    {
        const auto &asset = (AssetFont *)asseetManager.getAsset(asset::AssetType::FONT, fontName);
        font = asset->getFont();
    }

    void prepare()
    {
        surfaceMessage = TTF_RenderText_Blended(font, text.c_str(), white);
    }

    void render(SDL_Renderer *&r)
    {
        message = SDL_CreateTextureFromSurface(r, surfaceMessage);

        dest.x = pos.x + padding;
        dest.y = pos.y + (int)(surfaceMessage->h / 2);
        dest.w = surfaceMessage->w;
        dest.h = surfaceMessage->h;

        SDL_RenderCopy(r, message, NULL, &dest);
        SDL_FreeSurface(surfaceMessage);
    }
    void clean()
    {
        SDL_DestroyTexture(message);
    }
};

class ShapeComponent : public Component, public IRenderable<ShapeComponent>
{
public:
    glm::vec2 pos = {0, 0};
    glm::vec2 dim = {0, 0};
    entity::Color color = {0, 0, 0, 255};

    ShapeComponent(){};
    ~ShapeComponent(){};

    void assign(EntityInitialData::Shape shape)
    {
        exists = shape.exists;
        pos = shape.pos;
        dim = shape.dim;
        color.set(entity::ColorCode::GREEN);

        std::cout << color.r << " " << color.g << " " << color.b << "\n";
    }
    void clean()
    {
    }
    void draw(SDL_Renderer *&r)
    {
    }
    void render(SDL_Renderer *&r)
    {
        SDL_Rect rect = {(int)pos.x, (int)pos.y, (int)dim.x, (int)dim.y};
        SDL_SetRenderDrawColor(r, color.r, color.g, color.b, 255);
        SDL_RenderFillRect(r, &rect);
    }
    void update() {}
};

class MouseDownEventComponent : public Component
{
    public:
    MouseDownEventComponent(){}
    ~MouseDownEventComponent(){}
    action::ActionType actionType = action::ActionType::NONE;

    void assign(EntityInitialData::MouseDownEvent mouseDownEvent)
    {
        exists = mouseDownEvent.exists;
        actionType = mouseDownEvent.actionType;
    }
};

#endif // COMPONENTS_HPP
