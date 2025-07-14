#ifndef BULLETS_H
#define BULLETS_H
#include "raylib.h"
#include <vector>
#include "character.h"

typedef struct Bullet{
  int velocity;
  Vector2 position;
  float radius;
  bool active;
  std::string direction;
  
}Bullet;

extern std::vector<Bullet> Bullets;

//Bullet functions
Bullet InitBullet(Character *c);

void CreateBullet(Character *c);

void DrawBullet(Bullet bullet);

void UpdateBullets();

void DeleteBullet();

#endif
