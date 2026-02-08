/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

#include <iostream>

#include "GameScene.hpp"
#include "PacketQueue.hpp"
#include "raylib.h"
#include "../../server/Serializer/utils.hpp"

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

void GameEngine::handlePacket(Packet& packet)
{
    const auto type = packet.read<PacketType>();

    if (type != PacketType::CONNECTION_REQUEST) {
        std::cerr << "Unexpected packet type\n";
        return;
    }

    const auto count = packet.read<uint8_t>();

    std::cout << "Received map with " << static_cast<int>(count) << " entities\n";

    for (uint8_t i = 0; i < count; ++i) {
        const auto entityType = packet.read<uint8_t>();
        const auto x = packet.read<float>();
        const auto y = packet.read<float>();

        std::cout << "Entity "
                  << (int)entityType
                  << " at (" << x << ", " << y << ")\n";

        // Here: spawn sprite / entity in your game world
    }
}

void GameEngine::run()
{
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        auto packets = PacketQueue::getInstance().popAll();
        for (auto &packet : packets) {
            GameEngine::handlePacket(*packet.get());
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
