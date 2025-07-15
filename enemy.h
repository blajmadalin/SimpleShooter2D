#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <vector>

typedef struct Enemy{
  Vector2 velocity;
  Vector2 position;
  int health;
  float radius;

}Enemy;

extern std::vector<Enemy> Enemies;

//Functions 
Enemy InitEnemy();
void CreateEnemy();
void DrawEnemy(); 
void DeleteEnemy(int index);
void UpdateEnemy();


#endif // ENEMY.H
