#if !defined(ENTITY_MANAGER_HPP)
#define ENTITY_MANAGER_HPP
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "entity/entity.hpp"
using namespace entity;
class Entity;
class EntityManager
{

private:
    std::map<EntityType, std::vector<std::shared_ptr<Entity>>> m_entitiesMap;
    std::vector<std::shared_ptr<Entity>> m_allEnities;
    std::vector<std::shared_ptr<Entity>> m_pendingEntities;
    size_t m_entitiesCount = 0;

public:
    EntityManager(/* args */);
    ~EntityManager();

    const std::shared_ptr<Entity> &addEntity(EntityInitialData initData);
    std::vector<std::shared_ptr<Entity>> &getEntities();
    std::vector<std::shared_ptr<Entity>> &getEntities(EntityType eType);
    void onFrameUpdateEntities();
    void clean();
};

#endif // ENTITY_MANAGER_HPP
