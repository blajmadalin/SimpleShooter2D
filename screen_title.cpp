#include "screens.h"
#include <raylib.h>

const char* titleText;
static int fontSize;
static int textWidth;
static int posTextX;
static int posTextY;
static int finishScreen = 0;

void InitTitleScreen(){
  titleText = "Click to start";
  fontSize = 24;
  textWidth = MeasureText(titleText, fontSize);
 
  posTextX  = (screenWidth - textWidth) / 2;
  posTextY  = (screenHeight - fontSize) / 2;
 }

void DrawTitleScreen(){
  InitTitleScreen();
  
  BeginDrawing();

  DrawText(titleText, posTextX, posTextY, fontSize, BLACK);
  
  EndDrawing();
}

void UpdateTitleScreen(){
  if(IsGestureDetected(GESTURE_TAP)){
      finishScreen = 1;  
      }
}

void UnloadTitleScreen(){
  titleText = "";
  fontSize  = 0;
  textWidth = 0;

  posTextX = 0;
  posTextY = 0;
}

int FinishTitleScreen()
{
    return finishScreen;
}
