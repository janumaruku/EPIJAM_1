/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** GameEngine
*/

#ifndef EPIJAM_1_GAMEENGINE_HPP
#define EPIJAM_1_GAMEENGINE_HPP

#include "IScene.hpp"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    void run();

private:
    void update(float dt);
    void draw();

    IScene* currentScene;
};


#endif //EPIJAM_1_GAMEENGINE_HPP