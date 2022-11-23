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
#define IMAGE_COUNTER 104

typedef struct image {
    wchar_t* path;
    HDC* mem;
} images;

typedef struct element {
    int Status, posX, posY, sizeX, sizeY;


} element_t, *element_pt;


struct botButton {
    //element_t element;
    int Status, posX, posY, sizeX, sizeY;
    int  StasusModeGame;

} botB;

element_t podskazkaB, StartB, RulesB, Field, RulesI, AuthorB, AuthorI, ExitB, StopB, opponenLevelB, opponenLevelNumberB, LeftOpB, RightOpB, LeftB, TerpB, RightB, SoundB;

struct Field {

    wchar_t* field[980];
    int coordinataX[100];
    int coordinataY[100];
    int flag[100];
    int sizeX_big, sizeY_big;
    int sizeX_small, sizeY_small;
} s_Field;

int sums_Field;
int countLine1_X; //point x
int countLine1_O; // point O

int WinPoint; // Разница point при которой победит одна из сторон
int changeLeftClic[100];
wchar_t* pX;
wchar_t* pO;

int GameMod;
int ForTips;
HBITMAP hBitmap;
HDC hdc, hmdc, hdcMem;
PAINTSTRUCT ps;
BITMAP bitmap;
BITMAP bm;
HWND hwnd;
RECT rct;

int numberX_1, numberX_2, numberX_3, numberO_1, numberO_2, numberO_3;// For Cool numbers
double energyX, energyO, energyX1, energyX2, energyX3, energyO1, energyO2, energyO3; // energy
double energeOadd, energeXadd;  // energy add
double speed ; // speed return energy
double speedBot ;
int counter_start;
int mouse_x, mouse_y;
int posPancel;
int winMensOpVarible;
int tempm; // for dance animation

// for watch
double gameDuration;
double gameDurationBuf ;
int secondsLeft;
int minutsLeft;
int secondsLeft1;
int secondsLeft2;
int tik_tak;
int OnOffLeight ;

wchar_t buferForInt[128];

wchar_t* path[];
HDC memBig[IMAGE_COUNTER];
wchar_t name[];

enum ImagesName {
    memBitBlack, memBit3, memBitPole, memBitX1, memBitX2, memBitX3, memBitX4, memBitX5, memBitX6, memBitO1, memBitO2, memBitO3, memBitO4, memBitO5, memBitO6, memBitBot, memBitGameMod, memBitGameModV, memBitRules0, memBitRules1, memBitRuls, memBitAuthor0, memBitAuthor1, memBitAuthorPeople, memBitOpponentLevel, memBitLeftOpB_0, memBitRightOpB_0, memBitLeftOpB_1, memBitRightOpB_1, memBitLeft, memBitRight, memBitTerp1, memBitTerp2, memBitTerp3, memBitTerp4, memBitTerp5, memBitExit0, memBitExit1, memBitPancel, memBitEnergyX0, memBitEnergyX1, memBitEnergyX2, memBitEnergyX3, memBitEnergyX4, memBitEnergyX5, memBitEnergyX6, memBitEnergyX7, memBitEnergyX8, memBitEnergyX9, memBitEnergyX10, memBitEnergyO0, memBitEnergyO1, memBitEnergyO2, memBitEnergyO3, memBitEnergyO4, memBitEnergyO5, memBitEnergyO6, memBitEnergyO7, memBitEnergyO8, memBitEnergyO9, memBitEnergyO10, memBitO_Win, memBitX_Win, memBitNumbO_0, memBitNumbO_1, memBitNumbO_2, memBitNumbO_3, memBitNumbO_4, memBitNumbO_5, memBitNumbO_6, memBitNumbO_7, memBitNumbO_8, memBitNumbO_9, memBitNumbX_0, memBitNumbX_1, memBitNumbX_2, memBitNumbX_3, memBitNumbX_4, memBitNumbX_5, memBitNumbX_6, memBitNumbX_7, memBitNumbX_8, memBitNumbX_9, memBitT0, memBitT1, memBitT2, memBitT3, memBitT4, memBitT5, memBitT6, memBitT7, memBitT8, memBitT9, memBitO_WinMensLO, memBitO_WinMensPO, memBitO_WinMensLX, memBitO_WinMensPX, memBitSound0, memBitSound1, memBitSound2, memBitSound3, memBitStop0, memBitStop1, memBitPodskazka

};

void addBeforeStartedvalue();
void drawAll(HDC hdc);

void createTimer(HDC hdc);

int CreateGameField(HWND hdc);
void LoadImageDimaArr(wchar_t* path[]);
int BotMoves(HWND hwnd);
int KeyboardInput(HWND hwnd);
int MouseInput(HWND hwnd);
int compareArray(wchar_t* who, int* sum);
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

struct sImage {
    wchar_t path;
    HDC mem;
} sI;

typedef struct sImages ssImage;




