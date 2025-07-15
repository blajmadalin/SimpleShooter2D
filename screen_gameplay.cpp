#include "screens.h"
#include "raylib.h"
#include "character.h"
#include "bullets.h"
#include "enemy.h"

Character player;

float enemySpawntimer = 0;
float spawnInterval = 2.0f;

void InitGameplayScreen(){
  InitCharacter(&player);
}

void CheckCollisions(){
  for(int i = 0; i < Bullets.size(); i ++){
    for(int j = 0; j < Enemies.size(); j ++){
      if(CheckCollisionCircles(Bullets[i].position, Bullets[i].radius, Enemies[j].position, Enemies[j].radius)){
        DestroyBullet(i);
        DeleteEnemy(j);
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
  DrawBullet();
  DrawEnemy();

}
