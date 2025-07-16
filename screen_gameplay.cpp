#include "screens.h"
#include "raylib.h"
#include "character.h"
#include "bullets.h"
#include "enemy.h"

Character player;

int score = 0;
float lastKillTime = 0.0f;

//enemy spawn tweaks
float enemySpawntimer = 0;
float spawnInterval = 2.0f;

void InitGameplayScreen(){
  InitCharacter(&player);
}

void CheckCollisions(){
  for(int i = 0; i < Bullets.size(); i ++){
    for(int j = 0; j < Enemies.size(); j ++){
      if(CheckCollisionCircles(Bullets[i].position, Bullets[i].radius, Enemies[j].position, Enemies[j].radius)){
        //Destroying bullet and enemy
        DestroyBullet(i);
        DeleteEnemy(j);

        //Score calculation
        float timeSinceLastKill = GetTime() - lastKillTime;
        int bonus = (int)(500.0f / (timeSinceLastKill + 1));
        score += 100 + bonus;
        lastKillTime = GetTime();
      }
    }
  }
}


void UpdateGameplayScreen(){
CheckCollisions();
float deltaTime = GetFrameTime();

//Check colisions
  UpdateCharacter(&player);

  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    CreateBullet(&player);
  }

  if(enemySpawntimer >= spawnInterval){
    CreateEnemy();
    enemySpawntimer = 0.0f;
  }

  UpdateBullets(deltaTime);
}

void DrawGameplayScreen(){
  UpdateGameplayScreen();
  
  enemySpawntimer += GetFrameTime();

  ClearBackground(BLACK);

  DrawRectangle(0, 0, screenWidth, screenHeight, BLACK); 
  DrawCharacter(&player);
  
  //Drawing the score to the top right of the screen;
  const char* scoreText = TextFormat("Score: %d", score);
  int fontSize = 24;
  int textWidth = MeasureText(scoreText, fontSize);
  int padding = 20;
  DrawText(scoreText, screenWidth - textWidth - padding, padding, fontSize, WHITE);

 //Draw rest;
  DrawBullet();
  DrawEnemy();

}
