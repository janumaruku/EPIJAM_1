/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** Parallax_Manager.cpp
*/

#include "../include/Parallax_Manager.hpp"
#include "raylib.h"
#include <cmath>

ParallaxManager::ParallaxManager(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

ParallaxManager::~ParallaxManager()
{
    
}

void ParallaxManager::cleanup()
{
    for (auto& layer : layers) {
        if (layer.texture.id > 0) { 
            UnloadTexture(layer.texture);
        }
    }
    layers.clear();
}

void ParallaxManager::loadLayers()
{
    layers.push_back({
        LoadTexture("assets/Background.png"),
        0.0f,
        0.0f,
        "Background"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0011_0.png"),
        0.1f,
        0.0f,
        "Layer_0011_0"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0010_1.png"),
        0.15f,
        0.0f,
        "Layer_0010_1"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0009_2.png"),
        0.2f,
        0.0f,
        "Layer_0009_2"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0008_3.png"),
        0.25f,
        0.0f,
        "Layer_0008_3"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0007_Lights.png"),
        0.3f,
        0.0f,
        "Layer_0007_Lights"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0006_4.png"),
        0.35f,
        0.0f,
        "Layer_0006_4"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0005_5.png"),
        0.4f,
        0.0f,
        "Layer_0005_5"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0004_Lights.png"),
        0.5f,
        0.0f,
        "Layer_0004_Lights"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0003_6.png"),
        0.6f,
        0.0f,
        "Layer_0003_6"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0002_7.png"),
        0.7f,
        0.0f,
        "Layer_0002_7"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0001_8.png"),
        0.8f,
        0.0f,
        "Layer_0001_8"
    });
    
    layers.push_back({
        LoadTexture("assets/Layer_0000_9.png"),
        1.0f,
        0.0f,
        "Layer_0000_9"
    });
}

void ParallaxManager::update(float deltaTime, float speed)
{
    for (auto& layer : layers) {
        layer.offsetX -= layer.scrollSpeed * speed * deltaTime;
        
        float scaleY = (float)screenHeight / layer.texture.height;
        float scaledWidth = layer.texture.width * scaleY;
        
       if (layer.offsetX <= -scaledWidth) {
            layer.offsetX += scaledWidth;
        }
    }
}

void ParallaxManager::draw()
{
    for (const auto& layer : layers) {
        float scaleY = (float)screenHeight / layer.texture.height;
        float scaleX = scaleY;
        
        float scaledWidth = layer.texture.width * scaleX;
        
        DrawTextureEx(layer.texture,
                     (Vector2){ layer.offsetX, 0 },
                     0.0f, scaleX, WHITE);
        
        DrawTextureEx(layer.texture,
                     (Vector2){ layer.offsetX + scaledWidth, 0 },
                     0.0f, scaleX, WHITE);
        
        if (layer.offsetX + scaledWidth * 2 < screenWidth) {
            DrawTextureEx(layer.texture,
                         (Vector2){ layer.offsetX + scaledWidth * 2, 0 },
                         0.0f, scaleX, WHITE);
        }
    }
}