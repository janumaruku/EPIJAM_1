/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** map_manage.hpp
*/

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "animate_sprite.hpp"
#include <string>
#include <vector>
#include <memory>

enum class ElementState {
    ACTIVE,         
    COLLECTED,      
    DISAPPEARING,   
    INACTIVE        
};

struct MapElement {
    char type;                          
    float x;                           
    float y;                           
    std::shared_ptr<AnimatedSprite> sprite;
     ElementState state;               
    float disappearTimer;              
    Rectangle collisionBox;  
};

class MapManager {
public:
    MapManager(const std::string& mapFilePath, float tileSize = 32.0f);
    ~MapManager();
    
    void loadMap(const std::string& mapFilePath);
    void loadSprites(const std::string& cSpritePath, const std::string& mSpritePath);
    
    void update(float deltaTime);
    void draw(float offsetX, float scrollSpeed); 
    void cleanup();
    
    bool checkCollisionWithCoins(Rectangle playerBox, float offsetX, float scrollSpeed);
    bool checkCollisionWithMines(Rectangle playerBox, float offsetX, float scrollSpeed);
    
    int getMapWidth() const { return mapWidth; }
    int getMapHeight() const { return mapHeight; }
    float getTileSize() const { return tileSize; }
    
private:
    std::vector<std::vector<char>> mapData; 
    std::vector<MapElement> elements;         
    
    int mapWidth;
    int mapHeight;
    float tileSize;
    
    std::string cSpritePath;
    std::string mSpritePath;
     bool checkCollision(Rectangle rect1, Rectangle rect2);
    void updateElementState(MapElement& element, float deltaTime);
};

#endif