#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "level/entity_manager.hpp"
#include "entity/entity.hpp"
#include "entity/entity_data.hpp"

using namespace entity;

EntityManager::EntityManager(/* args */)
{
}

EntityManager::~EntityManager()
{
}

const std::shared_ptr<Entity> &EntityManager::addEntity(EntityInitialData initData)
{

    const std::shared_ptr<Entity> &entity =
        std::make_shared<Entity>(m_entitiesCount++,
                                 initData);
    m_pendingEntities.push_back(entity);
    m_entitiesMap[initData.type].push_back(entity);
    return *m_pendingEntities.end();
};

std::vector<std::shared_ptr<Entity>> &EntityManager::getEntities()
{
    return m_allEnities;
};
std::vector<std::shared_ptr<Entity>> &EntityManager::getEntities(EntityType eType)
{

    return m_entitiesMap[eType];
};

void EntityManager::onFrameUpdateEntities()
{

    std::remove_if(m_allEnities.begin(), m_allEnities.end(),
                   [](auto &a)
                   { return !(a->m_isAlive); });

    for (auto &[k, v] : m_entitiesMap)
    {
        std::remove_if(v.begin(), v.end(),
                       [](auto &a)
                       { return !(a->m_isAlive); });
    }

    for (auto &e : m_pendingEntities)
    {
        m_allEnities.push_back(e);
        m_entitiesMap[e->m_type].push_back(e);
    }
    m_pendingEntities.clear();
};

void EntityManager::clean()
{
    m_allEnities.clear();
}