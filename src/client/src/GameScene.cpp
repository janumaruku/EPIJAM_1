/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** GamePlay
*/

#include "../include/GameScene.hpp"

GameScene::GameScene(int width, int height)
    : parallax(width, height),
      player("assets/individual_sheets/male_hero-run.png", 128, 128),
      playerPos{200.f, 800.f},
      facingRight(true)
{
    parallax.loadLayers();

    player.addAnimation("run", 0, 3, 0.1f, true);
    player.playAnimation("run");
}

GameScene::~GameScene()
{
    player.cleanup();
    parallax.cleanup();
}

void GameScene::update(float dt)
{
    parallax.update(dt, 200.f);
    player.update(dt);
}

void GameScene::draw()
{
    parallax.draw();
    player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
}
