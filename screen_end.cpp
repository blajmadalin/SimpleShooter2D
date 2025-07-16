#include "screens.h"
#include "raylib.h"

const char* EndText;
static int fontSize;
static int textWidth;
static int posTextX;
static int posTextY;
static int finishScreen = 2;

void InitEndScreen(){
  EndText = "You died! Click to restart";
  fontSize = 24;
  textWidth = MeasureText(EndText, fontSize);
 
  posTextX  = (screenWidth - textWidth) / 2;
  posTextY  = (screenHeight - fontSize) / 2;
 }

void UpdateEndScreen(){
  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    finishScreen = 1;
  }
}

void DrawEndScreen(){
  DrawText(EndText, posTextX, posTextY, fontSize, BLACK);
}

void UnloadEndScreen(){
  EndText = "";
  fontSize  = 0;
  textWidth = 0;

  posTextX = 0;
  posTextY = 0;
}

int FinishEndScreen(){
  return finishScreen;
}

