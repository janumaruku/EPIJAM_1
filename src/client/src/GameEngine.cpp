/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
#include "GameScene.hpp"
#include "raylib.h"

GameEngine::GameEngine()
{
    InitWindow(1200, 700, "Zappy Client");
    SetTargetFPS(60);

    currentScene = new GameScene(1200, 700);
}

GameEngine::~GameEngine()
{
    delete currentScene;
    CloseWindow();
}

void GameEngine::run()
{
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        update(dt);

        BeginDrawing();
        ClearBackground({135, 206, 235, 255});
        draw();
        DrawFPS(10, 10);
        EndDrawing();
    }
}

void GameEngine::update(float dt)
{
    currentScene->update(dt);
}

void GameEngine::draw()
{
    currentScene->draw();
}
