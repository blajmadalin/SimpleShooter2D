#include "raylib.h"
#include "screens.h"

GameScreen currentScreen = TITLE;
int screenWidth = 800;
int screenHeight = 600;

static void UpdateDraw();

int main() {
   
   
    InitWindow(screenWidth, screenHeight, "Window");

    SetTargetFPS(60);

    while(!WindowShouldClose()){
      UpdateDraw(); 
    } 

    CloseWindow();
    return 0;
}

static void UpdateDraw(){
  //Change screens - add restart screen or something 
  if(currentScreen == TITLE){
    UpdateTitleScreen();

    if(FinishTitleScreen() == 1){
      InitGameplayScreen();
      UnloadTitleScreen();
      currentScreen = GAMEPLAY;
    }
  }

  //Draw
   BeginDrawing();

        ClearBackground(RAYWHITE);

        switch(currentScreen)
        {
            case TITLE: DrawTitleScreen(); break;
            case GAMEPLAY: DrawGameplayScreen(); break;
           // case ENDING: DrawEndingScreen(); break;
            default: break;
        }
    EndDrawing();
}

