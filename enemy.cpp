#include <raylib.h>
#include "enemy.h"
#include <vector>
#include <random>
#include "screens.h"

//Vector containing all the enemies on screen
std::vector<Enemy> Enemies;

//Declaration for random nr generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distribx(200, screenWidth);
std::uniform_int_distribution<> distriby(200, screenHeight);

Enemy InitEnemy(){
  Enemy enemy;

  float x = distribx(gen);
  float y = distriby(gen);

  enemy.health = 10;
  enemy.velocity = {2,2};
  enemy.position = {x, y};
  enemy.radius = 20;
  
  return enemy;
}

void CreateEnemy(){
  if(Enemies.size() > 5) return;

  Enemy enemy;
  enemy = InitEnemy();
  Enemies.push_back(enemy);

}

void DrawEnemy(){
  for(int i = 0; i < Enemies.size(); i ++){
    DrawCircleV(Enemies[i].position, Enemies[i].radius, RED);
  }
}

void DeleteEnemy(int index){
 Enemies.erase(Enemies.begin() + index); 
}

void UpdateEnemies(){
  
}
