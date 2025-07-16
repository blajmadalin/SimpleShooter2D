#include <raylib.h>
#include "raymath.h"
#include "enemy.h"
#include "character.h"
#include <random>
#include "screens.h"

//Vector containing all the enemies on screen
std::vector<Enemy> Enemies;

//Declaration for random nr generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distribx(200, screenWidth);
std::uniform_int_distribution<> distriby(200, screenHeight);

float enemySpeed = 2.0f;

Enemy InitEnemy(){
  Enemy enemy;

  float x = distribx(gen);
  float y = distriby(gen);

  enemy.health = 10;
  enemy.speed = enemySpeed;
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

void ChangeSpeed(){
  enemySpeed += 1.0f;
}

void UpdateEnemies(Character *c){
  for(int i = 0; i < Enemies.size(); i ++){
    Enemy enemy = Enemies[i];

    Vector2 direction = {
      c->position.x - enemy.position.x,
      c->position.y - enemy.position.y
    };

    direction = Vector2Normalize(direction);
    enemy.position.x += direction.x * enemy.speed;
    enemy.position.y += direction.y * enemy.speed;

    Enemies[i] = enemy;
  }
}

void DeleteEnemy(int index){
 Enemies.erase(Enemies.begin() + index); 
}
