#ifndef SCREENS_H
#define SCREENS_H

extern int screenWidth;
extern int screenHeight;

typedef enum GameScreen {UNKNOWN = -1, TITLE = 0, GAMEPLAY, END} GameScreen; 

extern GameScreen currentScreen;

#endif

//Title screen
void InitTitleScreen(void);
void DrawTitleScreen(void);
void UpdateTitleScreen(void);
int FinishTitleScreen(void);
void UnloadTitleScreen(void);

//Gameplay screen
void InitGameplayScreen(void);
void DrawGameplayScreen(void);
void UpdateGameplayScreen(void);
void UnloadGameplayScreen(void);
int FinishGameplayScreen(void);

//End screen
void InitEndScreen(void);
void DrawEndScreen(void);
void UnloadEndScreen(void);
void UpdateEndScreen(void);
int FinishEndScreen(void);
