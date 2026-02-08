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
    InitWindow(1980, 1034, "game");
    SetTargetFPS(60);

    currentScene = new GameScene(1980, 1034);
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
        if (currentScene->isGameOver() && IsKeyPressed(KEY_R)) {
            currentScene->restart();
        }
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
