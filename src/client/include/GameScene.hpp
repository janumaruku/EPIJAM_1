//
// Created by kotti on 08/02/2026.
//

#ifndef EPIJAM_1_GAMEPLAY_HPP
#define EPIJAM_1_GAMEPLAY_HPP

#include "animate_sprite.hpp"
#include "IScene.hpp"
#include "Parallax_layer.hpp"
#include "Parallax_Manager.hpp"
#include "map_manage.hpp"

// class GamePlay {
// };

class GameScene : public IScene {
public:
    GameScene(int width, int height);
    ~GameScene() override;

    void update(float dt) override;
    void draw() override;
    bool isGameOver() const { return gameOver; }
    void restart();
private:
    ParallaxManager parallax;
    MapManager map;
    AnimatedSprite player;

    Vector2 playerPos;
    float playerVelocityY;
    bool facingRight;
     bool isOnGround;

     int coinsCollected;          
    int playerHealth;             
    int maxHealth;               
    bool isInvincible;            
    float invincibilityTimer;     
    bool isHit;                   
    float hitAnimTimer;          
    bool gameOver;   

    float gameSpeed;
    float totalDistance;
    int screenWidth;
    int screenHeight;
    
    const float gravity = 1200.0f;
    const float jumpForce = -750.0f;     
    const float groundLevel = 906.0f; 
    const float INVINCIBILITY_DURATION = 2.0f;  
    const float HIT_ANIMATION_DURATION = 0.3f;
    
    
    void handleCollisions();
    void updateInvincibility(float dt);
    void drawHUD();
    void drawGameOver();
};


#endif 