#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <vector>
#include "character.h"

typedef struct Enemy{
  float speed;
  Vector2 position;
  int health;
  float radius;

}Enemy;

extern std::vector<Enemy> Enemies;

//Functions 
Enemy InitEnemy();
void CreateEnemy();
void DrawEnemy(); 
void ChangeSpeed();
void DeleteEnemy(int index);
void UpdateEnemies(Character *c);


#endif // ENEMY.H
