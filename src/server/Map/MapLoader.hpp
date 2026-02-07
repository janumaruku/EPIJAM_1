/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** MapLoader
*/

#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include <string>
#include "Map.hpp"

class MapLoader {
public:
    static Map loadFromFile(const std::string& path, float cellSize);
};

#endif
