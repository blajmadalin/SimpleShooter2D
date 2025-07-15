#ifndef BULLETS_H
#define BULLETS_H
#include "raylib.h"
#include <vector>
#include "character.h"

typedef struct Bullet{
  Vector2 velocity;
  Vector2 position;
  float radius;
  bool active;
}Bullet;

extern std::vector<Bullet> Bullets;

//Bullet functions
Bullet InitBullet(Character *c);

void CreateBullet(Character *c);

void DrawBullet();

void UpdateBullets(float deltaTime);

void DestroyBullet(int index);

void DeleteBullet();

#endif
