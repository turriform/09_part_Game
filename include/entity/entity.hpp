#if !defined(MAIN_ENTITY_HPP)
#define MAIN_ENTITY_HPP
#include <iostream>
#include <tuple>
#include <memory>

#include "entity_data.hpp"
#include "components.hpp"

using namespace entity;

typedef std::tuple<
    InitialComponent,
    TransformComponent,
    ShapeComponent,
    LabelComponent,
    BBoxComponent,
    MouseDownEventComponent>
    Components;

class Entity
{
private:
    friend class EntityManager;
    EntityType m_type;
    Components m_components;
    size_t m_entityID;
    bool m_isAlive = true;

    void init(EntityInitialData initialData);

public:
    Entity();
    Entity(size_t id, EntityInitialData initialData);
    // Entity(const Entity &) = delete;
    // Entity &operator=(const Entity &) = delete;
    
    ~Entity();
    template <typename T>
    T &getComponent()
    {
        return std::get<T>(m_components);
    }

    template <typename T, typename TArg>
    T &addComponent(TArg arg)
    {
        auto &comp = getComponent<T>();
      
        comp.assign(arg);
        return comp;
    }

    template <typename T>
    void deleteComponent()
    {
        if (getComponent<T>().exists)
        {
            getComponent<T>() = T();
        }
    }

    template <typename T>
    bool componentExists()
    {
        return getComponent<T>().exists;
    }
};

#endif // MAIN_ENTITY_HPP
