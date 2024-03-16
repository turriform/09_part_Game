#include <tuple>
#include "glm/glm.hpp"
#include "entity/entity.hpp"
#include "entity/entity_data.hpp"
#include "entity/components.hpp"

using namespace entity;

Entity::Entity(/* args */)
{
}

Entity::Entity(size_t id, EntityInitialData initialData) : m_type(initialData.type), m_entityID(id)
{

    init(initialData);
}

Entity::~Entity()
{
}

void Entity::init(EntityInitialData initialData)
{
    if (initialData.initial.exists)
    {
        addComponent<InitialComponent>(initialData.initial);
    }
    if (initialData.transform.exists)
    {
        addComponent<TransformComponent>(initialData.transform);
    }
    if (initialData.shape.exists)
    {
        addComponent<ShapeComponent>(initialData.shape);
    }
    if (initialData.bbox.exists)
    {
        addComponent<BBoxComponent>(initialData.bbox);
    }
    if (initialData.label.exists)
    {
        addComponent<LabelComponent>(initialData.label);
    }
    if (initialData.mouseDownEvent.exists)
    {
        addComponent<MouseDownEventComponent>(initialData.mouseDownEvent);
    }
};
