/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** main.cpp
*/

#include "../include/Parallax_Manager.hpp"
#include "../include/animate_sprite.hpp"

#include "raylib.h"

int main()
{
    const int screenWidth = 1990;
    const int screenHeight = 1034;
    
    InitWindow(screenWidth, screenHeight, "Parallax Background Racing Game");
    
    ParallaxManager parallaxManager(screenWidth, screenHeight);
    parallaxManager.loadLayers();
    AnimatedSprite player("assets/individual_sheets/male_hero-run.png", 128, 128);
    player.addAnimation("run", 0, 3, 0.1f, true);      
    player.playAnimation("run");
     
    float parallaxSpeed = 200.0f;
    Vector2 playerPos = { 200.0f, 800.0f };
    bool facingRight = true;
    // float moveSpeed = 200.0f;
    
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        // bool isMoving = false;
        
        parallaxManager.update(deltaTime, parallaxSpeed);
        player.update(deltaTime);
        
        BeginDrawing();
        ClearBackground(Color{135, 206, 235, 255});
        
        
        parallaxManager.draw();
        player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
        
        DrawFPS(10, 10);
        
        EndDrawing();
    }
    player.cleanup();
    parallaxManager.cleanup();
    
    CloseWindow();
    return 0;
}
