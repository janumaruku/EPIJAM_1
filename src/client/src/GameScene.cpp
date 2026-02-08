/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** GamePlay
*/

#include "../include/GameScene.hpp"

GameScene::GameScene(int width, int height)
    : parallax(width, height),
      map("maps/map.txt", 32.0f),
      player("assets/individual_sheets/player_sheet.png", 102, 102),
      playerPos{200.f, 850.f},
      playerVelocityY(0.0f),
      facingRight(true),
      isOnGround(true),
      coinsCollected(0),
      playerHealth(3),
      maxHealth(3),
      isInvincible(false),
      invincibilityTimer(0.0f),
      isHit(false),
      hitAnimTimer(0.0f),
      gameOver(false),
      gameSpeed(200.0f),
      totalDistance(0.0f),
      screenWidth(width),
      screenHeight(height),
      groundLevel(800.0f)
{
    parallax.loadLayers();
    map.loadSprites("assets/Tomato/tomato_sheet.png",  
                    "assets/Sprites/with_outline/FLYING.png");

    player.addAnimation("run", 12, 21, 0.1f, true);
    player.addAnimation("jump", 6, 11, 0.1f, false);
    player.addAnimation("hit", 0, 5, 0.08f, false);
    player.playAnimation("run");
}

GameScene::~GameScene()
{
    player.cleanup();
    map.cleanup();
    parallax.cleanup();
}

void GameScene::handleCollisions()
{
    Rectangle playerBox = {
        playerPos.x + 30,
        playerPos.y + 20,
        128 * 2 - 60,
        128 * 2 - 40          
    };
    
    if (map.checkCollisionWithCoins(playerBox, totalDistance, 1.0f)) {
        coinsCollected++;
    }
    
    if (!isInvincible && map.checkCollisionWithMines(playerBox, totalDistance, 1.0f)) {
        playerHealth--;
        isInvincible = true;
        invincibilityTimer = 0.0f;
        isHit = true;
        hitAnimTimer = 0.0f;
        
        player.playAnimation("hit");
        
        
        if (playerHealth <= 0) {
            gameOver = true;
        }
    }
}

void GameScene::updateInvincibility(float dt)
{
    if (isInvincible) {
        invincibilityTimer += dt;
        
        if (invincibilityTimer >= INVINCIBILITY_DURATION) {
            isInvincible = false;
            invincibilityTimer = 0.0f;
        }
    }
    
    if (isHit) {
        hitAnimTimer += dt;
        
        if (hitAnimTimer >= HIT_ANIMATION_DURATION || player.isAnimationFinished()) {
            isHit = false;
            hitAnimTimer = 0.0f;
            
            if (isOnGround) {
                player.playAnimation("run");
            } else {
                player.playAnimation("jump");
            }
        }
    }
}

void GameScene::update(float dt)
{
    if (gameOver) return;
   isOnGround = (playerPos.y >= groundLevel - 5);  
   
    if ((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) && isOnGround  && !isHit) {
        playerVelocityY = jumpForce; 
        isOnGround = false;
        player.playAnimation("jump"); 
    }
    
    if (!isOnGround) {
        playerVelocityY += gravity * dt;  
    }
    
    playerPos.y += playerVelocityY * dt;
    
    if (playerPos.y >= groundLevel) {
        playerPos.y = groundLevel;
        playerVelocityY = 0.0f;
        isOnGround = true;
        
        if (!isHit &&player.getCurrentAnimationName() != "run") {
            player.playAnimation("run");
        }
    }
    if (playerPos.y < 0) {
        playerPos.y = 0;
        playerVelocityY = 0;
    }
    
   
    totalDistance += gameSpeed * dt;
    handleCollisions();
    
    updateInvincibility(dt);
    
 
    parallax.update(dt, 200.f);
    map.update(dt); 
    player.update(dt);
}

void GameScene::drawHUD()
{
    DrawRectangle(10, 10, 350, 120, Fade(BLACK, 0.8f));
    
    DrawText(TextFormat("Tomato: %d", coinsCollected), 20, 20, 24, YELLOW);
    
    DrawText("HEALTH:", 20, 55, 20, WHITE);
    for (int i = 0; i < maxHealth; i++) {
        Color heartColor = (i < playerHealth) ? RED : DARKGRAY;
        
        int heartX = 130 + i * 40;
        int heartY = 55;
        DrawRectangle(heartX, heartY + 5, 12, 12, heartColor);
        DrawRectangle(heartX + 12, heartY + 5, 12, 12, heartColor);
        DrawTriangle(
            {(float)heartX, (float)heartY + 17},
            {(float)heartX + 24, (float)heartY + 17},
            {(float)heartX + 12, (float)heartY + 30},
            heartColor
        );
        DrawTriangle(
            {(float)heartX, (float)heartY + 5},
            {(float)heartX + 12, (float)heartY - 3},
            {(float)heartX + 12, (float)heartY + 5},
            heartColor
        );
        DrawTriangle(
            {(float)heartX + 12, (float)heartY - 3},
            {(float)heartX + 24, (float)heartY + 5},
            {(float)heartX + 12, (float)heartY + 5},
            heartColor
        );
    }
    
    DrawText(TextFormat("DISTANCE: %.0fm", totalDistance / 32.0f), 20, 95, 18, GREEN);
    
    if (isInvincible) {
        float remaining = INVINCIBILITY_DURATION - invincibilityTimer;
        DrawText(TextFormat("INVINCIBLE: %.1fs", remaining), 20, screenHeight - 40, 18, SKYBLUE);
    }
}

void GameScene::drawGameOver()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.7f));
    
    DrawText("GAME OVER U :(", screenWidth/2 + 500, screenHeight/2 - 100, 80, RED);
    
    DrawRectangle(screenWidth/2 - 250, screenHeight/2, 500, 200, Fade(BLACK, 0.9f));
    DrawText(TextFormat("Coins Collected: %d", coinsCollected), 
             screenWidth/2 - 150, screenHeight/2 + 30, 30, YELLOW);
    DrawText(TextFormat("Distance: %.0fm", totalDistance / 32.0f), 
             screenWidth/2 - 150, screenHeight/2 + 80, 30, GREEN);
    
    DrawText("Press R to Restart", screenWidth/2 - 140, screenHeight/2 + 140, 25, WHITE);
    DrawText("Press ESC to Quit", screenWidth/2 - 120, screenHeight/2 + 175, 20, GRAY);
}

void GameScene::draw()
{
    parallax.draw();
    map.draw(totalDistance, 1.0f);

    if (isInvincible) {
        int blinkSpeed = 10;
        if (((int)(invincibilityTimer * blinkSpeed)) % 2 == 0) {
            player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
        }
    } else {
        player.draw(playerPos.x, playerPos.y, 2.0f, !facingRight);
    }
    drawHUD();
    
    if (gameOver) {
        drawGameOver();
    }
    
    if (!gameOver) {
        DrawText("SPACE/ENTER - Jump", 10, screenHeight - 30, 16, WHITE);
    }

}

void GameScene::restart()
{
    playerPos = {200.f, 800.f};
    playerVelocityY = 0.0f;
    isOnGround = true;
    
    coinsCollected = 0;
    playerHealth = maxHealth;
    isInvincible = false;
    invincibilityTimer = 0.0f;
    isHit = false;
    hitAnimTimer = 0.0f;
    gameOver = false;
    
    gameSpeed = 200.0f;
    totalDistance = 0.0f;
    
    player.playAnimation("run");
    
    map.loadMap("maps/map.txt");
    map.loadSprites("assets/Tomato/tomato_sheet.png",  
                    "assets/Sprites/with_outline/FLYING.png");
    
}