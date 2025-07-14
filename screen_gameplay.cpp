#include "screens.h"
#include "raylib.h"
#include "character.h"
#include "bullets.h"

Character player;
Bullet bullet;

void InitGameplayScreen(){
  InitCharacter(&player);
}

void UpdateGameplayScreen(){
  UpdateCharacter(&player);

  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    CreateBullet(&player);
  }

  UpdateBullets();
}

void DrawGameplayScreen(){
  UpdateGameplayScreen();

  ClearBackground(BLACK);
  DrawRectangle(0, 0, screenWidth, screenHeight, BLACK); 
  DrawCharacter(&player);

  for(int i = 0; i < Bullets.size(); i ++){
    DrawBullet(Bullets[i]); 
  }
 

}
