/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Map
*/

#include "Map.hpp"

void Map::addEntity(const MapEntity& entity)
{
    _entities.push_back(entity);
}

const std::vector<MapEntity>& Map::getEntities() const
{
    return _entities;
}
