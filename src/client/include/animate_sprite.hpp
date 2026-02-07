/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** animate_sprite.hpp
*/


#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP

#include "raylib.h"
#include <map>
#include <string>


struct Animation {
    std::string name;              
    int startFrame;                
    int endFrame;                
    float frameTime;              
    bool loop;                    
};
class AnimatedSprite {
public:
    
    AnimatedSprite(const std::string& texturePath, int frameWidth, int frameHeight);
    ~AnimatedSprite();
    void cleanup();
    
    
    void addAnimation(const std::string& name, int startFrame, int endFrame, 
                     float frameTime, bool loop = true);
    void playAnimation(const std::string& name);
    
    void update(float deltaTime);
    void draw(float x, float y, float scale = 1.0f, bool flipX = false);
    void draw(Vector2 position, float rotation = 0.0f, float scale = 1.0f, 
             Color tint = WHITE, bool flipX = false);
    
    int getCurrentFrame() const { return currentFrame; }
    std::string getCurrentAnimationName() const { return currentAnimationName; }
    bool isAnimationFinished() const { return animationFinished; }
    int getFrameWidth() const { return frameWidth; }
    int getFrameHeight() const { return frameHeight; }
    
    void setFrame(int frame);
    void pause() { paused = true; }
    void resume() { paused = false; }
    void reset();
    
private:
    void calculateSourceRect();
    
    Texture2D spriteSheet;
    int frameWidth;
    int frameHeight;
    int framesPerRow;
    int totalFrames;
    
    std::map<std::string, Animation> animations;
    std::string currentAnimationName;
    Animation* currentAnimation;
    
    int currentFrame;
    float frameTimer;
    bool animationFinished;
    bool paused;
    
    Rectangle sourceRect;
};

#endif