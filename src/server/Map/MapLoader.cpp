/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** MapLoader
*/
#include "MapLoader.hpp"
#include <fstream>
#include <stdexcept>

Map MapLoader::loadFromFile(const std::string& path, float cellSize)
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open map file: " + path);

    Map map;
    std::string line;
    int y = 0;

    while (std::getline(file, line)) {
        for (int x = 0; x < static_cast<int>(line.size()); ++x) {
            if (char c = line[x]; c == 'c') {
                map.addEntity({
                    EntityType::Collectible,
                    x * cellSize,
                    y * cellSize
                });
            } else if (c == 'e') {
                map.addEntity({
                    EntityType::Obstacle,
                    x * cellSize,
                    y * cellSize
                });
            }
        }
        ++y;
    }

    return map;
}
