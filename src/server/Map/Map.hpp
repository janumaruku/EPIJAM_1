/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include "types.hpp"

class Map {
public:
    void addEntity(const MapEntity& entity);

    const std::vector<MapEntity>& getEntities() const;

private:
    std::vector<MapEntity> _entities;
};

#endif
