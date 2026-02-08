//
// Created by kotti on 08/02/2026.
//

#ifndef EPIJAM_1_GAMEPLAY_HPP
#define EPIJAM_1_GAMEPLAY_HPP

#include "animate_sprite.hpp"
#include "IScene.hpp"
#include "Parallax_layer.hpp"
#include "Parallax_Manager.hpp"

// class GamePlay {
// };

class GameScene : public IScene {
public:
    GameScene(int width, int height);
    ~GameScene() override;

    void update(float dt) override;
    void draw() override;

private:
    ParallaxManager parallax;
    AnimatedSprite player;

    Vector2 playerPos;
    bool facingRight;
};


#endif //EPIJAM_1_GAMEPLAY_HPP