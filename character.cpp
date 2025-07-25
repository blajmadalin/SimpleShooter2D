#include "screens.h"
#include "raylib.h"
#include "character.h"
#include <iostream>

void InitCharacter(Character *c){
  c -> position = (Vector2){100, 100};
  c -> health = 100;
  c -> radius = 20;
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
  //Drawing player;
  DrawCircleV(c -> position, c -> radius, BLUE);

  //Drawing player health;
  const char* healthText =TextFormat("Health: %d", c -> health); 
  int padding = 20;
  int fontSize = 24;
 
  DrawText(healthText, padding, padding, fontSize, WHITE);
}

bool ShootBullets(Character *c){
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
   return true; 
  }

  return false;
}

