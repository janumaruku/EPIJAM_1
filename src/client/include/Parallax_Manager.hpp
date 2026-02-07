/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** Parallax_Manager.hpp
*/

#ifndef PARALLAXMANAGER_HPP
#define PARALLAXMANAGER_HPP

#include "Parallax_layer.hpp"
#include <vector>

class ParallaxManager {
public:
    ParallaxManager(int screenWidth, int screenHeight);
    ~ParallaxManager();
    
    void loadLayers();
    void cleanup();
    void update(float deltaTime, float speed);
    void draw();
    
private:
    std::vector<ParallaxLayer> layers;
    int screenWidth;
    int screenHeight;
};

#endif 