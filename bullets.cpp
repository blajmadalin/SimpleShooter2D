#include "bullets.h"
#include "raylib.h"
#include <vector>
#include "character.h"

std::vector <Bullet> Bullets;

Bullet InitBullet(Character *c){
  Bullet bullet;

  bullet.active = true;
  bullet.radius = 5;
  bullet.position = c->position;
  bullet.velocity = 6;
  bullet.direction = c->direction;

  return bullet;
}

void CreateBullet(Character *c){
  if(Bullets.size() > 50) return;

  Bullet bullet;
  bullet = InitBullet(c);
  Bullets.push_back(bullet);
}

void DestroyBullet(int index){
  Bullets.erase(Bullets.begin() + index);
}

void DrawBullet(Bullet bullet){
  DrawCircleV(bullet.position, bullet.radius, WHITE);
}

void UpdateBullets(){
  for(int i = 0; i < Bullets.size(); i ++){
    Bullet bullet = Bullets[i];
    std::string direction = bullet.direction;

    if(bullet.position.x < 0 || bullet.position.x > 1920 || bullet.position.y < 0 || bullet.position.y > 1080){
      DestroyBullet(i);
      continue;
    }
    
    if(direction == "UP"){
      bullet.position.y -= bullet.velocity;
    }

    if(direction == "DOWN"){
      bullet.position.y += bullet.velocity;
    }

    if(direction == "RIGHT"){
      bullet.position.x += bullet.velocity;
    }

    if(direction == "LEFT"){
      bullet.position.x -= bullet.velocity;
    }

     Bullets[i] = bullet;
  }
}


