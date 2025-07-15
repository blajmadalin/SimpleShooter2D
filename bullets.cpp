#include "bullets.h"
#include "raylib.h"
#include "raymath.h"
#include <vector>

std::vector <Bullet> Bullets;
float bulletSpeed = 10.0 * 40;

Vector2 Direction(Character *c){
  Vector2 mousePos = GetMousePosition();
  
  Vector2 direction = {mousePos.x - c -> position.x, mousePos.y - c -> position.y};
  direction = Vector2Normalize(direction);

  return direction;
}

Bullet InitBullet(Character *c){
  Bullet bullet;

  bullet.active = true;
  bullet.radius = 5;
  bullet.position = c->position;

  Vector2 direction = Direction(c);

  bullet.velocity = Vector2Scale(direction, bulletSpeed);
 

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

void DrawBullet(){
  
  for(int i = 0; i < Bullets.size(); i ++){

     DrawCircleV(Bullets[i].position, Bullets[i].radius, WHITE);

  }
}

void UpdateBullets(float deltaTime){
  for(int i = 0; i < Bullets.size(); i ++){
    Bullet bullet = Bullets[i];

    if(bullet.position.x < 0 || bullet.position.x > 1920 || bullet.position.y < 0 || bullet.position.y > 1080){
      DestroyBullet(i);
      continue;
    }
    
     bullet.position.x += bullet.velocity.x * deltaTime;
     bullet.position.y += bullet.velocity.y * deltaTime;
     Bullets[i] = bullet;
  }
}


