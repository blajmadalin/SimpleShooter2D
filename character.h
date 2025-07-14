#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "raylib.h"

typedef struct Character{
  Vector2 position;
  int health;
  int moveSpeed;
  std::string direction;
} Character;

void InitCharacter(Character *c);
void UpdateCharacter(Character *c);
void DrawCharacter(Character *c);

#endif
