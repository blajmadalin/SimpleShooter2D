#include "screens.h"
#include "raylib.h"
#include "character.h"
#include "bullets.h"
#include "enemy.h"

Character player;

static int finishScreen = 1;

int score = 0;
int lastScoreMilestone = 0;
float lastKillTime = 0.0f;

//enemy spawn tweaks
float enemySpawntimer = 0;
float spawnInterval = 2.0f;

void InitGameplayScreen(){
  InitCharacter(&player);
  score = 0;
  lastKillTime = 0.0f;
  spawnInterval = 2.0f;
  enemySpawntimer = 0;
  finishScreen = 1;
}

void CheckCollisions(float deltaTime){
  //collision between enemies and bullets
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

  //collision between player and Enemies
  for(int i = 0; i < Enemies.size(); i ++){
     if(CheckCollisionCircles(player.position, player.radius, Enemies[i].position, Enemies[i].radius)){
       player.health -= 10 * deltaTime;

     }
  }
}

void UpdateGameplayScreen(){

  if(player.health <= 0){
    finishScreen = 2;
  }
//Calculating deltaTime;
  float deltaTime = GetFrameTime();

//Checking collisions between entities on screen  
  CheckCollisions(deltaTime);


//Updating entities;
  UpdateCharacter(&player);
  UpdateBullets(deltaTime);
  UpdateEnemies(&player);

  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    CreateBullet(&player);
  }

  if(enemySpawntimer >= spawnInterval){
    CreateEnemy();
    enemySpawntimer = 0.0f;
  }

  if(score >= (lastScoreMilestone + 5000)){
    spawnInterval -= 0.5f;
    lastScoreMilestone += 5000;
    ChangeSpeed();
  }


}

void DrawGameplayScreen(){  
  enemySpawntimer += GetFrameTime();

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

void UnloadGameplayScreen(){
  //lol
}

int FinishGameplayScreen(){
  return finishScreen;
}
