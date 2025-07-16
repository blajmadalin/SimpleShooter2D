#include "screens.h"
#include "raylib.h"
#include "character.h"
#include <iostream>

void InitCharacter(Character *c){
  c -> position = (Vector2){100, 100};
  c -> health = 100;
  c -> moveSpeed = 6;
  c -> direction = "LEFT";
}

void UpdateCharacter(Character *c){
  if(IsKeyDown(KEY_D)){
    c -> position.x += c -> moveSpeed;
    c -> direction = "RIGHT";
  }

  if(IsKeyDown(KEY_A)){
    c -> position.x -= c -> moveSpeed;
    c -> direction = "LEFT";
  }

  if(IsKeyDown(KEY_W)){
    c -> position.y -= c -> moveSpeed;
    c -> direction = "UP";
  }   

  if(IsKeyDown(KEY_S)){
     c -> position.y += c -> moveSpeed;
     c -> direction = "DOWN";
  }
}

void DrawCharacter(Character *c){
  DrawCircleV(c -> position, 20, BLUE);
}

bool ShootBullets(Character *c){
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
   return true; 
  }

  return false;
}

