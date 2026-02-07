/*
** EPITECH PROJECT, 2025
** EPIJAM_1 [WSL: Ubuntu]
** File description:
** animated_sprite.cpp
*/

#include "../include/animate_sprite.hpp"
#include <cmath>

AnimatedSprite::AnimatedSprite(const std::string& texturePath, int frameWidth, int frameHeight)
    : frameWidth(frameWidth), frameHeight(frameHeight), currentFrame(0),
      frameTimer(0.0f), animationFinished(false), paused(false),
      currentAnimation(nullptr)
{
    spriteSheet = LoadTexture(texturePath.c_str());    
    framesPerRow = spriteSheet.width / frameWidth;
    int rows = spriteSheet.height / frameHeight;
    totalFrames = framesPerRow * rows;
    
    calculateSourceRect();
}

AnimatedSprite::~AnimatedSprite()
{
  
}

void AnimatedSprite::cleanup()
{
    if (spriteSheet.id > 0) {
        UnloadTexture(spriteSheet);
        spriteSheet.id = 0;
    }
}

void AnimatedSprite::addAnimation(const std::string& name, int startFrame, int endFrame,
                                  float frameTime, bool loop)
{
    Animation anim;
    anim.name = name;
    anim.startFrame = startFrame;
    anim.endFrame = endFrame;
    anim.frameTime = frameTime;
    anim.loop = loop;
    
    animations[name] = anim;
}

void AnimatedSprite::playAnimation(const std::string& name)
{
    if (currentAnimationName == name && currentAnimation != nullptr) {
        return;
    }
    
    auto it = animations.find(name);
    if (it == animations.end()) {
        return;
    }
    
    currentAnimationName = name;
    currentAnimation = &(it->second);
    currentFrame = currentAnimation->startFrame;
    frameTimer = 0.0f;
    animationFinished = false;
    paused = false;
    
    calculateSourceRect();
}

void AnimatedSprite::update(float deltaTime)
{
    if (paused || currentAnimation == nullptr) {
        return;
    }
    
    if (animationFinished && !currentAnimation->loop) {
        return;
    }
    
    frameTimer += deltaTime;
    
    if (frameTimer >= currentAnimation->frameTime) {
        frameTimer -= currentAnimation->frameTime;
        currentFrame++;
        
        if (currentFrame > currentAnimation->endFrame) {
            if (currentAnimation->loop) {
                currentFrame = currentAnimation->startFrame;
            } else {
                currentFrame = currentAnimation->endFrame;
                animationFinished = true;
            }
        }
        
        calculateSourceRect();
    }
}

void AnimatedSprite::draw(float x, float y, float scale, bool flipX)
{
    Rectangle destRect = {
        x,
        y,
        frameWidth * scale * (flipX ? -1.0f : 1.0f),
        frameHeight * scale
    };
    
    Vector2 origin = { 0, 0 };
    
    DrawTexturePro(spriteSheet, sourceRect, destRect, origin, 0.0f, WHITE);
}

void AnimatedSprite::draw(Vector2 position, float rotation, float scale, Color tint, bool flipX)
{
    Rectangle destRect = {
        position.x,
        position.y,
        frameWidth * scale * (flipX ? -1.0f : 1.0f),
        frameHeight * scale
    };
    
    Vector2 origin = {
        frameWidth * scale / 2.0f,
        frameHeight * scale / 2.0f
    };
    
    DrawTexturePro(spriteSheet, sourceRect, destRect, origin, rotation, tint);
}

void AnimatedSprite::setFrame(int frame)
{
    if (frame >= 0 && frame < totalFrames) {
        currentFrame = frame;
        calculateSourceRect();
    }
}

void AnimatedSprite::reset()
{
    if (currentAnimation != nullptr) {
        currentFrame = currentAnimation->startFrame;
        frameTimer = 0.0f;
        animationFinished = false;
        calculateSourceRect();
    }
}

void AnimatedSprite::calculateSourceRect()
{
    int frameX = currentFrame % framesPerRow;
    int frameY = currentFrame / framesPerRow;
    
    sourceRect = {
        (float)(frameX * frameWidth),
        (float)(frameY * frameHeight),
        (float)frameWidth,
        (float)frameHeight
    };
}