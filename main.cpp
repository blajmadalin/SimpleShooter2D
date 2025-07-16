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
  if(currentScreen == TITLE){
    UpdateTitleScreen();

    if(FinishTitleScreen() == 1){
      InitGameplayScreen();
      UnloadTitleScreen();
      currentScreen = GAMEPLAY;
    }
  }

  else if(currentScreen == GAMEPLAY){
    UpdateGameplayScreen();

    if(FinishGameplayScreen() == 2){
      InitEndScreen();
      UnloadGameplayScreen();
      currentScreen = END;
    }
  }

  else if(currentScreen == END){
    UpdateEndScreen();
    if(FinishEndScreen() == 1){
      UnloadEndScreen();
      currentScreen = GAMEPLAY;
      InitGameplayScreen();
    }
  }

  //Draw
   BeginDrawing();

        ClearBackground(RAYWHITE);

        switch(currentScreen)
        {
            case TITLE: DrawTitleScreen(); break;
            case GAMEPLAY: DrawGameplayScreen(); break;
            case END: DrawEndScreen(); break;
            default: break;
        }
    EndDrawing();
}

