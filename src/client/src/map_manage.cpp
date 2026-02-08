/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** mao_manager.cpp
*/

#include "map_manage.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

MapManager::MapManager(const std::string& mapFilePath, float tileSize)
    : mapWidth(0), mapHeight(0), tileSize(tileSize)
{
    loadMap(mapFilePath);
}

MapManager::~MapManager()
{
    cleanup();
}

void MapManager::loadMap(const std::string& mapFilePath)
{
    std::ifstream file(mapFilePath);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open map file: " << mapFilePath << "\n";
        return;
    }
    
    std::string line;
    mapData.clear();
    
    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        
        if (!row.empty()) {
            mapData.push_back(row);
            
            if ((int)row.size() > mapWidth) {
                mapWidth = (int)row.size();
            }
        }
    }
    
    mapHeight = (int)mapData.size();
    
    file.close();
    
    std::cout << "Map loaded: " << mapWidth << "x" << mapHeight << " tiles\n";
}

void MapManager::loadSprites(const std::string& cSpritePath, const std::string& mSpritePath)
{
    this->cSpritePath = cSpritePath;
    this->mSpritePath = mSpritePath;
    
    elements.clear();
    
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (x >= (int)mapData[y].size()) continue;
            
            char tile = mapData[y][x];
            
            if (tile == '_') continue;
            
            MapElement element;
            element.type = tile;
            element.x = x * tileSize;
            element.y = y * tileSize +550;
            element.state = ElementState::ACTIVE;
            element.disappearTimer = 0.0f;
            
            element.collisionBox = {
                element.x + 4,         
                element.y + 4,
                tileSize - 8,           
                tileSize - 8
            };
            if (tile == 'c') {
                element.sprite = std::make_shared<AnimatedSprite>(cSpritePath, 96, 96);
                element.sprite->addAnimation("idle", 11, 15, 0.1f, true);
                element.sprite->addAnimation("collect", 0, 9, 0.05f, false);
                element.sprite->playAnimation("idle");
            }
            else if (tile == 'm') {
                element.sprite = std::make_shared<AnimatedSprite>(mSpritePath, 81, 71);
                element.sprite->addAnimation("fly", 0, 3, 0.15f, true);
                element.sprite->playAnimation("fly");
            }
            
            if (element.sprite) {
                elements.push_back(element);
            }
        }
    }
    
    std::cout << "Sprites loaded: " << elements.size() << " elements\n";
}

void MapManager::updateElementState(MapElement& element, float deltaTime)
{
    if (element.state == ElementState::DISAPPEARING) {
        element.disappearTimer += deltaTime;
        
        if (element.disappearTimer >= 0.4f) {
            element.state = ElementState::INACTIVE;
        }
    }
}

void MapManager::update(float deltaTime)
{
    for (auto& element : elements) {
        if (element.sprite && element.state != ElementState::INACTIVE) {
            element.sprite->update(deltaTime);
            updateElementState(element, deltaTime);
        }
    }
}

void MapManager::draw(float offsetX, float scrollSpeed)
{
    float mapWidthPixels = mapWidth * tileSize;
    float adjustedOffset = offsetX * scrollSpeed;
    float loopedOffset = fmod(adjustedOffset, mapWidthPixels);
    
    for (const auto& element : elements) {
        
        if (element.state == ElementState::INACTIVE) continue;
        
        if (element.sprite) {
            float drawX = element.x - loopedOffset;
            
            if (drawX < -tileSize) {
                drawX += mapWidthPixels;
            }
            
            float drawY = element.y;
            
            Color tint = WHITE;
            float scale = 1.0f;
            
            if (element.state == ElementState::DISAPPEARING) {
                float progress = element.disappearTimer / 0.4f; 
                tint.a = (unsigned char)((1.0f - progress) * 255);  
                scale = 1.0f + progress * 0.5f;  
            }
            
            if (drawX > -tileSize && drawX < 2000) {
                element.sprite->draw(drawX, drawY, scale, false);
            }
            
            float drawX2 = drawX + mapWidthPixels;
            if (drawX2 > -tileSize && drawX2 < 2000) {
                element.sprite->draw(drawX2, drawY, scale, false);
            }
        }
    }
}

bool MapManager::checkCollision(Rectangle rect1, Rectangle rect2)
{
    return (rect1.x < rect2.x + rect2.width &&
            rect1.x + rect1.width > rect2.x &&
            rect1.y < rect2.y + rect2.height &&
            rect1.y + rect1.height > rect2.y);
}

bool MapManager::checkCollisionWithCoins(Rectangle playerBox, float offsetX, float scrollSpeed)
{
    float mapWidthPixels = mapWidth * tileSize;
    float adjustedOffset = offsetX * scrollSpeed;
    float loopedOffset = fmod(adjustedOffset, mapWidthPixels);
    
    bool collided = false;
    
    for (auto& element : elements) {
        if (element.type != 'c' || element.state != ElementState::ACTIVE) continue;
        
        float drawX = element.x - loopedOffset;
        if (drawX < -tileSize) {
            drawX += mapWidthPixels;
        }
        
        Rectangle elementBox = {
            drawX + 4,
            element.y + 4,
            tileSize - 8,
            tileSize - 8
        };
        
        if (checkCollision(playerBox, elementBox)) {
            element.state = ElementState::DISAPPEARING;
            element.disappearTimer = 0.0f;
            element.sprite->playAnimation("collect");  
            collided = true;
            std::cout << "Coin collected!" << std::endl;
        }
        
        Rectangle elementBox2 = {
            drawX + mapWidthPixels + 4,
            element.y + 4,
            tileSize - 8,
            tileSize - 8
        };
        
        if (checkCollision(playerBox, elementBox2)) {
            element.state = ElementState::DISAPPEARING;
            element.disappearTimer = 0.0f;
            element.sprite->playAnimation("collect");
            collided = true;
            std::cout << "Coin collected!" << std::endl;
        }
    }
    
    return collided;
}

bool MapManager::checkCollisionWithMines(Rectangle playerBox, float offsetX, float scrollSpeed)
{
    float mapWidthPixels = mapWidth * tileSize;
    float adjustedOffset = offsetX * scrollSpeed;
    float loopedOffset = fmod(adjustedOffset, mapWidthPixels);
    
    for (auto& element : elements) {
        if (element.type != 'm' || element.state != ElementState::ACTIVE) continue;
        
        float drawX = element.x - loopedOffset;
        if (drawX < -tileSize) {
            drawX += mapWidthPixels;
        }
        
        Rectangle elementBox = {
            drawX + 4,
            element.y + 4,
            tileSize - 8,
            tileSize - 8
        };
        
        if (checkCollision(playerBox, elementBox)) {
            std::cout << "Hit by mine!" << std::endl;
            return true;
        }
        
        Rectangle elementBox2 = {
            drawX + mapWidthPixels + 4,
            element.y + 4,
            tileSize - 8,
            tileSize - 8
        };
        
        if (checkCollision(playerBox, elementBox2)) {
            std::cout << "Hit by mine!" << std::endl;
            return true;
        }
    }
    
    return false;
}


void MapManager::cleanup()
{
    for (auto& element : elements) {
        if (element.sprite) {
            element.sprite->cleanup();
        }
    }
    elements.clear();
}