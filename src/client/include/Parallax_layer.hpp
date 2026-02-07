/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** Parallax_layer.hpp
*/

#ifndef PARALLAXLAYER_HPP
#define PARALLAXLAYER_HPP

#include "raylib.h"
#include <string>

struct ParallaxLayer {
    Texture2D texture;
    float scrollSpeed;
    float offsetX;
    std::string name;
};

#endif 