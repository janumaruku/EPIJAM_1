/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** main.cpp
*/

#include "../include/animate_sprite.hpp"
#include "../include/Parallax_Manager.hpp"
#include "../include/TcpClient.hpp"
#include "../include/ClientApp.hpp"

// #include "raylib.h"

// int main(int, char* av[])
// {
//     // const int screenWidth = 1990;
//     // const int screenHeight = 1034;
//     //
//     // InitWindow(screenWidth, screenHeight, "Parallax Background Racing Game");
//     //
//     // ParallaxManager parallaxManager(screenWidth, screenHeight);
//     // parallaxManager.loadLayers();
//     // AnimatedSprite player("assets/individual_sheets/male_hero-run.png", 128, 128);
//     // player.addAnimation("run", 0, 3, 0.1f, true);
//     // player.playAnimation("run");
//     //
//     // float parallaxSpeed = 200.0f;
//     // Vector2 playerPos = { 200.0f, 800.0f };
//     // bool facingRight = true;
//     // // float moveSpeed = 200.0f;
//     //
//     // while (!WindowShouldClose()) {
//     //     float deltaTime = GetFrameTime();
//     //     // bool isMoving = false;
//     //
//     //     parallaxManager.update(deltaTime, parallaxSpeed);
//     //     player.update(deltaTime);
//     //
//     //     BeginDrawing();
//     //     ClearBackground(Color{135, 206, 235, 255});
//     //
//     //
//     //     parallaxManager.draw();
//     //     player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
//     //
//     //     DrawFPS(10, 10);
//     //
//     //     EndDrawing();
//     // }
//     // player.cleanup();
//     // parallaxManager.cleanup();
//     //
//     // CloseWindow();
//     try {
//         const int port = atoi(av[1]);
//         asio::io_context io;
//         TcpClient client(io, "127.0.0.1", port);
//
//         io.run();
//     } catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << "\n";
//     }
// }

int main(int ac, char* av[])
{
    if (ac < 2) {
        std::cerr << "Usage: ./client <port>\n";
        return 1;
    }

    try {
        ClientApp app(std::atoi(av[1]));
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
