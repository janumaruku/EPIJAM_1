// /*
// ** EPITECH PROJECT, 2025
// ** EPIJAM_1 [WSL: Ubuntu]
// ** File description:
// ** test.cpp
// */



// #include "raylib.h"
// #include "../include/animate_sprite.hpp"

// int main()
// {
//     const int screenWidth = 800;
//     const int screenHeight = 600;
    
//     InitWindow(screenWidth, screenHeight, "Animated Sprite Example");
//     SetTargetFPS(60);
    
    
//     AnimatedSprite player("assets/individual_sheets/male_hero-run.png", 128, 128);

    
   
//     player.addAnimation("run", 0, 3, 0.1f, true);      
  
    
//     player.playAnimation("run");
    
//     Vector2 playerPos = { 200.0f, 300.0f };
//     bool facingRight = true;
    
    
    
//     float moveSpeed = 200.0f;
    
//     while (!WindowShouldClose()) {
//         float deltaTime = GetFrameTime();
        
        
//         bool isMoving = false;
        
       
        
//         // else if (IsKeyPressed(KEY_J)) {
//         //     player.playAnimation("jump");
//         // }
//         // else if (player.isAnimationFinished() || 
//         //          (player.getCurrentAnimationName() != "attack" && 
//         //           player.getCurrentAnimationName() != "jump")) {
//         //     if (isMoving) {
//         //         player.playAnimation("run");
//         //     } else {
//         //         player.playAnimation("idle");
//         //     }
//         // }
        
//         player.update(deltaTime);
        
//         BeginDrawing();
//         ClearBackground(Color{100, 150, 200, 255});
        
//         player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
        
        
//         DrawText("WASD - Move | SPACE - Attack | J - Jump", 10, 10, 20, WHITE);
//         DrawText(TextFormat("Animation: %s", player.getCurrentAnimationName().c_str()), 
//                 10, 40, 20, YELLOW);
//         DrawText(TextFormat("Frame: %d", player.getCurrentFrame()), 10, 70, 20, YELLOW);
        
//         DrawFPS(10, screenHeight - 30);
        
//         EndDrawing();
//     }
//     player.cleanup();
//     CloseWindow();
//     return 0;
// }
  