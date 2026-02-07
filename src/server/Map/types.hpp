/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** types
*/

#ifndef BISTROMATIC_TYPES_HPP
#define BISTROMATIC_TYPES_HPP

#include <cstdint>

enum class EntityType : std::uint8_t {
    Collectible,
    Obstacle
};

struct MapEntity {
    EntityType type;
    float x;
    float y;
};

#endif //BISTROMATIC_TYPES_HPP
