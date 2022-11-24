#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "shcore.lib")
#include <windows.h>
#include <stdio.h>
#include <string.h>  
#include <conio.h> 
#include <wchar.h>
#include <time.h>
#include <math.h>
#include <malloc.h>
#include <shellscalingapi.h>
#include "resource.h"

#define ID_TIMER_BEFORE_START -1
#define ID_TIMER_START 1
#define ID_TIMER_energy1 2
#define IMAGE_COUNTER 52


typedef struct PlaceAndStatus {
    int Status, posX, posY, sizeX, sizeY;

 } PlaceAndStatus_t, * PlaceAndStatus_pt;
PlaceAndStatus_t NumberX1, NumberX2, NumberO1, NumberO2, EnergyX1, EnergyX2, EnergyX3, EnergyO1, EnergyO2, EnergyO3, LightB, MinutL, MinutR, SecondL, SecondR, podskazkaB, StartB, RulesB, Field, RulesI, AuthorB, AuthorI, ExitB, StopB, opponenLevelB, opponenLevelNumberB, LeftOpB, RightOpB, LeftB, TerpB, RightB, SoundB;

typedef struct PlaseOnly {
    int posX, posY, sizeX, sizeY;

} PlaseOnly_t, * PlaseOnly_pt;

PlaseOnly_t WatchB;

struct botButton {
  
    int Status, posX, posY, sizeX, sizeY;
    int  StasusModeGame;

} botB;

typedef struct Number {
    HDC array[10];

} Number_t, * Number_pt;
Number_t MemWatchNumber, MemXNumber, MemONumber;

typedef struct Energy {
    HDC array[11];

} Energy_t, * Energy_pt;
Energy_t MemEnergyX, MemEnergyO;

struct Field {

    wchar_t* field[980];
    int coordinataX[100];
    int coordinataY[100];
    int flag[100];
    int sizeX_big, sizeY_big;
    int sizeX_small, sizeY_small;
} s_Field;

int sums_Field;
int sumPoint_X; //point x
int sumPoint_O; // point O

int WinPoint; // Разница point при которой победит одна из сторон
int changeLeftClic[100];
wchar_t* pX;
wchar_t* pO;

int GameMod;
int ForTips;
HBITMAP hBitmap;
HDC hdc;
PAINTSTRUCT ps;
BITMAP bitmap;
BITMAP bm;
HWND hwnd;
RECT rct;

double energyX, energyO; // energy
double speed ; // speed return energy
double speedBot ;
int counter_start;
int mouse_x, mouse_y;
int posPancel;

int tempm; // for dance animation

// for watch
double gameDuration;
double gameDurationBuf ;

int tik_tak;

wchar_t buferForInt[128];

wchar_t* path[];
wchar_t* pathNumberWatch[];
wchar_t* pathNumberX[];
wchar_t* pathNumberO[];
wchar_t* pathEnergyX[];
wchar_t* pathEnergyO[];
HDC memBig[IMAGE_COUNTER];
//HDC memNumberWatch[10];
wchar_t name[];

enum ImagesName {
    memBitBlack, memBit3, memBitPole, memBitX1, memBitX2, memBitX3, memBitX4, memBitX5, memBitX6, memBitO1, memBitO2, memBitO3, memBitO4, memBitO5, memBitO6, memBitBot, memBitGameMod, memBitGameModV, memBitRules0, memBitRules1, memBitRuls, memBitAuthor0, memBitAuthor1, memBitAuthorPeople, memBitOpponentLevel, memBitLeftOpB_0, memBitRightOpB_0, memBitLeftOpB_1, memBitRightOpB_1, memBitLeft, memBitRight, memBitTerp1, memBitTerp2, memBitTerp3, memBitTerp4, memBitTerp5, memBitExit0, memBitExit1, memBitPancel,memBitO_Win, memBitX_Win, memBitO_WinMensLO, memBitO_WinMensPO, memBitO_WinMensLX, memBitO_WinMensPX, memBitSound0, memBitSound1, memBitSound2, memBitSound3, memBitStop0, memBitStop1, memBitPodskazka

};

void addBeforeStartedvalue();
void drawAll(HDC hdc);
void createTimer(HDC hdc);
int CreateGameField(HWND hdc);

int BotMoves(HWND hwnd);
int KeyboardInput(HWND hwnd);
int MouseInput(HWND hwnd);
int sumPoint(wchar_t* who, int* sum);
int convertPointInCoolO(HWND hwnd);
int SumСompletedFields();
int changeMenu(HWND hwnd);
int addEnergy(HWND hwnd);
int changeDisplay();
int convertWatch(HWND hwnd);

void drawhLight(HDC* memDC);
void drawNumberWatch(HDC* memDC);
void drawButton(HDC* memDC);
void drawRightPageBackground(HDC* memDC);
void drawTips(HDC* memDC);
void drawElementsXO(HDC* memDC);
void drawRedPancel(HDC* memDC);
void drawEnergy(HDC* memDC);
void drawScore(HDC* memDC);
void drawWin(HDC* memDC);

void botButton();
void StartGameButton();
void RulesButton();
void AuthorButton();
void LevelOpponentButton();
void SpeedSovlanutButtons();
void ExitButton();
void SoundButton();
void SwitchLight();
void SwitchWatch();
void StopButton();
void TipsClick();

int placeClick(int* posX, int* posY, int* sizeX, int* sizeY);
void LoadImageArr(wchar_t* path[], HDC* arrayVarieble[], int sizeArray);





