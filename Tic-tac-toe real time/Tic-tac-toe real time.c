#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "shcore.lib")
#include <windows.h>
#include <windowsx.h>
#include <new.h>
#include <stdio.h>
#include <string.h>  
#include <conio.h> 
#include <winuser.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#include "resource.h"
#include <shellscalingapi.h>

#define Start00 105
#define EDIT_ID 1001
#define BUTTON_ID 1002
#define STATIC_ID 1003
#define ID_BEEP 101
#define ID_TIMER_BEFORE_START -1
#define ID_TIMER_START 1
#define ID_TIMER_energy1 2
#define ID_BEEP 101
#define ID_QUIT 102

struct botButton {
    int Status, StasusModeGame, posX, posY, sizeX, sizeY;

} botB;

struct startButton {
    int Status, x, y;

} StartB;

struct RulesButton {
    int Status, posX, posY, sizeX, sizeY;

} RulesB;

struct RulesImage {
    int Status, posX, posY, sizeX, sizeY;

} RulesI;

struct AuthorButton {
    int Status, posX, posY, sizeX, sizeY;

} AuthorB;

struct AuthorImage {
    int Status, posX, posY, sizeX, sizeY;

} AuthorI;

struct ExitButton {
    int Status, posX, posY, sizeX, sizeY;

} ExitB;

struct StopButton {
    int Status, posX, posY, sizeX, sizeY;

} StopB;

struct LeftButton {
    int Status, posX, posY, sizeX, sizeY;

} LeftB;

struct TerptButton {
    int Status, posX, posY, sizeX, sizeY;

} TerpB;

struct RightButton {
    int Status, posX, posY, sizeX, sizeY;

} RightB;

struct buttonSound {
    int Status, posX, posY, sizeX, sizeY;

} SoundB;


wchar_t* arrayP[100];
int arrayCoordinataX[100];
int arrayCoordinataY[100];

int arrayFlag[100];
int sumArrayFlagField = 0;
int countLine1_X = 0; //point x
int countLine1_O = 0; // point O
int WinPoint = 1030; // Разница point при которой победит одна из сторон
int changeLeftClic[100]; 
wchar_t* pX = L"x";
wchar_t* pO = L"o";
int StartGame = -1;

// For Cool numbers
int numberX_1 = 0;
int numberX_2 = 0;
int numberX_3 = 0;
int numberO_1 = 0;
int numberO_2 = 0;
int numberO_3 = 0;

// energy
double energyX = 2;
double energyO = 2;

double energyX1 = 1;
double energyX2 = 1;
double energyX3 = 1;
double energyO1 = 1;
double energyO2 = 1;
double energyO3 = 1;

double energeOadd = 0;
double energeXadd = 0;

double speed = 0.24; // speed return energy

int counter_start = 1;

int mouse_x;
int mouse_y;
int posPancel = 45;
int winMensOpVarible = 1;

int tempm = 0;

RECT rct;
char szImageName[] = "BMImage";

// for watch
double gameDuration = 150;
double gameDurationBuf = 150;
int secondsLeft;
int minutsLeft;
int secondsLeft1;
int secondsLeft2;
int tik_tak=0;


int OnOffLeight = 0;

static HDC memBitT1;   
static HDC memBitT2;   
static HDC memBitT3;   
static HDC memBitT4;   
static HDC memBitT5;   
static HDC memBitT6;   

static HDC memBitT7;   
static HDC memBitT8;   
static HDC memBitT9;   
static HDC memBitT0;   

static HDC memBitX1;   
static HDC memBitX2;   
static HDC memBitX3;   
static HDC memBitX4;   
static HDC memBitX5;   
static HDC memBitX6;   

static HDC memBitO1;   
static HDC memBitO2;   
static HDC memBitO3;   
static HDC memBitO4;   
static HDC memBitO5;   
static HDC memBitO6;   

static HDC memBitPole;

// button menu

static HDC memBitBot;
static HDC memBitStartGame;
static HDC memBitStartGameV;

// button Exit
static HDC memBitExit0;
static HDC memBitExit1;

// button rules
static HDC memBitRules0;
static HDC memBitRules1;

// Image rules
static HDC memBitRuls;

// button author
static HDC memBitAuthor0;
static HDC memBitAuthor1;
static HDC memBitAuthorPeople;

// button arroy
static HDC memBitLeft;
static HDC memBitRight;

static HDC memBitTerp1;
static HDC memBitTerp2;
static HDC memBitTerp3;
static HDC memBitTerp4;
static HDC memBitTerp5;

static HDC memBitTerp1;
static HDC memBitTerp2;
static HDC memBitTerp3;
static HDC memBitTerp4;
static HDC memBitTerp5;

// button stop
static HDC memBitStop0;
static HDC memBitStop1;

// button stop
static HDC memBitSound0;
static HDC memBitSound1;
static HDC memBitSound2;
static HDC memBitSound3;

//  energy
static HDC memBitEnergyX0;
static HDC memBitEnergyX1;
static HDC memBitEnergyX2;
static HDC memBitEnergyX3;
static HDC memBitEnergyX4;
static HDC memBitEnergyX5;
static HDC memBitEnergyX6;
static HDC memBitEnergyX7;
static HDC memBitEnergyX8;
static HDC memBitEnergyX9;
static HDC memBitEnergyX10;

static HDC memBitEnergyO0;
static HDC memBitEnergyO1;
static HDC memBitEnergyO2;
static HDC memBitEnergyO3;
static HDC memBitEnergyO4;
static HDC memBitEnergyO5;
static HDC memBitEnergyO6;
static HDC memBitEnergyO7;
static HDC memBitEnergyO8;
static HDC memBitEnergyO9;
static HDC memBitEnergyO10;

//  numbers
static HDC memBitNumbO_0;
static HDC memBitNumbO_1;
static HDC memBitNumbO_2;
static HDC memBitNumbO_3;
static HDC memBitNumbO_4;
static HDC memBitNumbO_5;
static HDC memBitNumbO_6;
static HDC memBitNumbO_7;
static HDC memBitNumbO_8;
static HDC memBitNumbO_9;
static HDC memBitNumbX_0;
static HDC memBitNumbX_1;
static HDC memBitNumbX_2;
static HDC memBitNumbX_3;
static HDC memBitNumbX_4;
static HDC memBitNumbX_5;
static HDC memBitNumbX_6;
static HDC memBitNumbX_7;
static HDC memBitNumbX_8;
static HDC memBitNumbX_9;

static HDC memBitPancel;

static HDC memBitO_Win;
static HDC memBitX_Win;

static HDC memBitO_WinMensLO;
static HDC memBitO_WinMensPO;
static HDC memBitO_WinMensLX;
static HDC memBitO_WinMensPX;

static HDC memBit1;   
static HDC memBit2;   
static HDC memBit3;   
static HDC memBitBlack;   
wchar_t buferForInt[128];

HWND hwnd;

int CreateGameField(HWND hdc) {

        for (int iii = 0; iii < 10; iii++) {
        for (int jjj = 1; jjj <= 10; jjj++) {

            arrayP[iii * 10 + jjj] = L"";
            arrayCoordinataX[iii * 10 + jjj] = 699 + iii * 35;
            arrayCoordinataY[iii * 10 + jjj] = 155 + jjj * 34;
            arrayFlag[iii * 10 + jjj] = 0;
        }
    }
        
}

void update(HDC hdc) {
        HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP memBM = CreateCompatibleBitmap(hdc, rct.right - rct.left, rct.bottom - rct.top);
    SelectObject(memDC, memBM);

    if (StartGame == -1) BitBlt(memDC, 0, 0, 1280, 1024, memBitBlack, 0, 0, SRCCOPY);
    if (StartGame != -1) BitBlt(memDC, 0, 0, 1280, 1024, memBit3, 0, 0, SRCCOPY);



 
    // drowField
    if (StartGame == 4 || counter_start == -100) { BitBlt(memDC, 677, 173, 395, 565, memBitPole, 0, 0, SRCCOPY); }

    int posT1SecX = 905;
    int posT1SecY = 18;
    int posyTRight = 44;

    // first zero
    BitBlt(memDC, 835 - posyTRight, posT1SecY, 37, 73, memBitT0, 0, 0, SRCCOPY);

    if (minutsLeft <= 0) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT0, 0, 0, SRCCOPY); }
    if (minutsLeft == 1) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT1, 0, 0, SRCCOPY); }
    if (minutsLeft == 2) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT2, 0, 0, SRCCOPY); }
    if (minutsLeft == 3) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT3, 0, 0, SRCCOPY); }
    if (minutsLeft == 4) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT4, 0, 0, SRCCOPY); }
    if (minutsLeft == 5) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT5, 0, 0, SRCCOPY); }
    if (minutsLeft == 6) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT6, 0, 0, SRCCOPY); }
    if (minutsLeft == 7) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT7, 0, 0, SRCCOPY); }
    if (minutsLeft == 8) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT8, 0, 0, SRCCOPY); }
    if (minutsLeft == 9) { BitBlt(memDC, 835, posT1SecY, 37, 73, memBitT9, 0, 0, SRCCOPY); }

    if (minutsLeft <= 0) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT0, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 1) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT1, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 2) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT2, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 3) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT3, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 4) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT4, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 5) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT5, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 6) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT6, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 7) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT7, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 8) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT8, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 9) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT9, 0, 0, SRCCOPY); }

    if (secondsLeft1 <= 0) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT0, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 1) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT1, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 2) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT2, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 3) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT3, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 4) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT4, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 5) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT5, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 6) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT6, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 7) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT7, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 8) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT8, 0, 0, SRCCOPY); }
    if (secondsLeft1 == 9) { BitBlt(memDC, posT1SecX, posT1SecY, 37, 73, memBitT9, 0, 0, SRCCOPY); }

    if (secondsLeft2 <= 0) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT0, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 1) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT1, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 2) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT2, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 3) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT3, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 4) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT4, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 5) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT5, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 6) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT6, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 7) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT7, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 8) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT8, 0, 0, SRCCOPY); }
    if (secondsLeft2 == 9) { BitBlt(memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBitT9, 0, 0, SRCCOPY); }

    // ButtonBot
    if (StartB.Status == 1 && StartGame != -1 && botB.Status ==1) { BitBlt(memDC, botB.posX, botB.posY, botB.sizeX, botB.sizeY, memBitBot, 0, 0, SRCCOPY); }
    if (botB.StasusModeGame == 1 && StartGame != -1) { BitBlt(memDC, botB.posX + 10, botB.posY + 10, 28, 28, memBitX6, 0, 0, SRCCOPY); }

    // ButtonStartGame
    if (StartB.Status == 1 && StartGame != -1) { BitBlt(memDC, 237, 360, 321, 66, memBitStartGame, 0, 0, SRCCOPY); }
    if (StartB.Status == 2 && StartGame != -1) { BitBlt(memDC, 237, 360, 321, 66, memBitStartGameV, 0, 0, SRCCOPY); }

    // ButtonRules 
    if (RulesB.Status == 0 && StartGame != -1) { BitBlt(memDC, RulesB.posX, RulesB.posY, RulesB.sizeX, RulesB.sizeY, memBitRules0, 0, 0, SRCCOPY); }
    if (RulesB.Status == 1 && StartGame != -1) { BitBlt(memDC, RulesB.posX, RulesB.posY, RulesB.sizeX, RulesB.sizeY, memBitRules1, 0, 0, SRCCOPY); }

    if (StartGame == 5) { BitBlt(memDC, RulesI.posX, RulesI.posY, RulesI.sizeX, RulesI.sizeY, memBitRuls, 0, 0, SRCCOPY); }


    // ButtonAuthor 
    if (AuthorB.Status == 0 && StartGame != -1) { BitBlt(memDC, AuthorB.posX, AuthorB.posY, AuthorB.sizeX, AuthorB.sizeY, memBitAuthor0, 0, 0, SRCCOPY); }
    if (AuthorB.Status == 1 && StartGame != -1) { BitBlt(memDC, AuthorB.posX, AuthorB.posY, AuthorB.sizeX, AuthorB.sizeY, memBitAuthor1, 0, 0, SRCCOPY); }

    if (StartGame == 6) { BitBlt(memDC, AuthorI.posX, AuthorI.posY, AuthorI.sizeX, AuthorI.sizeY, memBitAuthorPeople, 0, 0, SRCCOPY); }


    // Button Arrey
    if (LeftB.Status == 1 && StartGame != -1) { BitBlt(memDC, LeftB.posX, LeftB.posY, LeftB.sizeX, LeftB.sizeY, memBitLeft, 0, 0, SRCCOPY); }
    if (RightB.Status == 1 && StartGame != -1) { BitBlt(memDC, RightB.posX, RightB.posY, RightB.sizeX, RightB.sizeY, memBitRight, 0, 0, SRCCOPY); }

    if (TerpB.Status == 1 && StartGame != -1) { BitBlt(memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBitTerp1, 0, 0, SRCCOPY); }
    if (TerpB.Status == 2 && StartGame != -1) { BitBlt(memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBitTerp2, 0, 0, SRCCOPY); }
    if (TerpB.Status == 3 && StartGame != -1) { BitBlt(memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBitTerp3, 0, 0, SRCCOPY); }
    if (TerpB.Status == 4 && StartGame != -1) { BitBlt(memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBitTerp4, 0, 0, SRCCOPY); }
    if (TerpB.Status == 5 && StartGame != -1) { BitBlt(memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBitTerp5, 0, 0, SRCCOPY); }
   
      // ButtonSound
    if (SoundB.Status == 0 && StartGame != -1) { BitBlt(memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBitSound0, 0, 0, SRCCOPY); }
    if (SoundB.Status == 1 && StartGame != -1) { BitBlt(memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBitSound1, 0, 0, SRCCOPY); }
    if (SoundB.Status == 2 && StartGame != -1) { BitBlt(memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBitSound2, 0, 0, SRCCOPY); }
    if (SoundB.Status == 3 && StartGame != -1) { BitBlt(memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBitSound3, 0, 0, SRCCOPY); }

    // ButtonExit
    if (ExitB.Status == 0 && StartGame != -1) { BitBlt(memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBitExit0, 0, 0, SRCCOPY); }
    if (ExitB.Status == 1 && StartGame != -1) { BitBlt(memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBitExit1, 0, 0, SRCCOPY); }

        // ButtonStop
    if (StopB.Status == 0 && counter_start == -100)  BitBlt(memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBitStop0, 0, 0, SRCCOPY);
    if (StopB.Status == 1 && counter_start == -100) BitBlt(memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBitStop1, 0, 0, SRCCOPY);

     // Rectangle(memDC, 0, 0, 300, 300);
    for (int i = 1; i <= 100; i++) {
        if (arrayP[i] == L"x" && StartGame != -1 &&  (StartGame ==2 || StartGame ==4)) {
            BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX6, 0, 0, SRCCOPY);  
           
        }
        if (arrayP[i] == L"x5") {
            BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX5, 0, 0, SRCAND); arrayP[i] = L"x"; tik_tak = 10; arrayFlag[i] = 1; sumFlagField();  compareArray();
        }
        if (arrayP[i] == L"x4") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX4, 0, 0, SRCAND); arrayP[i] = L"x5"; }
        if (arrayP[i] == L"x3") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX3, 0, 0, SRCAND); arrayP[i] = L"x4"; }
        if (arrayP[i] == L"x2") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX2, 0, 0, SRCAND); arrayP[i] = L"x3"; }
        if (arrayP[i] == L"x1") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX1, 0, 0, SRCAND); arrayP[i] = L"x2";     if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC); }

        if (arrayP[i] == L"o" && StartGame != -1 && (StartGame == 2 || StartGame == 4)) {
            BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO6, 0, 0, SRCCOPY); 
            
        }
        if (arrayP[i] == L"o5") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO5, 0, 0, SRCAND); arrayP[i] = L"o"; arrayFlag[i] = 1; sumFlagField(); compareArrayO();
        }
        if (arrayP[i] == L"o4") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO4, 0, 0, SRCAND); arrayP[i] = L"o5"; tik_tak = 10;
        }
        if (arrayP[i] == L"o3") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO3, 0, 0, SRCAND); arrayP[i] = L"o4"; }
        if (arrayP[i] == L"o2") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO2, 0, 0, SRCAND); arrayP[i] = L"o3"; }
        if (arrayP[i] == L"o1") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO1, 0, 0, SRCAND); arrayP[i] = L"o2";    if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC); }
    }

    int addENX = 698;
    int addENY = 667;
    int addENNX = 35;
    int addENO = 909;
    int addENNO = 35;

    // energy x1 
    if (counter_start == -100 && energyX1 <= 0) { BitBlt(memDC, 698, 667, 30, 64, memBitEnergyX0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 1) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 2) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 3) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 4) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 5) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 6) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 7) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 8) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 9) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 10) { BitBlt(memDC, addENX, addENY, 30, 64, memBitEnergyX10, 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyX2 <= 0) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 1) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 2) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 3) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 4) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 5) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 6) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 7) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 8) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 9) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 10) { BitBlt(memDC, addENX + addENNX, addENY, 30, 64, memBitEnergyX10, 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyX3 <= 0) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 1) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 2) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 3) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 4) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 5) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 6) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 7) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 8) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 9) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 10) { BitBlt(memDC, addENX + addENNX * 2, addENY, 30, 64, memBitEnergyX10, 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO3 <= 0) { BitBlt(memDC, 909, 667, 30, 64, memBitEnergyO0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 1) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 2) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 3) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 4) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 5) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 6) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 7) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 8) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 9) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 10) { BitBlt(memDC, addENO, addENY, 30, 64, memBitEnergyO10, 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO2 <= 0) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 1) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 2) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 3) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 4) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 5) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 6) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 7) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 8) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 9) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 10) { BitBlt(memDC, addENO + addENNO, addENY, 30, 64, memBitEnergyO10, 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO1 <= 0) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO0, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 1) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO1, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 2) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO2, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 3) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO3, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 4) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO4, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 5) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO5, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 6) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO6, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 7) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO7, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 8) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO8, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 9) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO9, 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 10) { BitBlt(memDC, addENO + addENNO * 2, addENY, 30, 64, memBitEnergyO10, 0, 0, SRCCOPY); }

    int posNumber1_X = 767;
    int addPosNumber = 35;

    if (numberX_1 == 0 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_0, 0, 0, SRCCOPY); }
    if (numberX_1 == 1 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_1, 0, 0, SRCCOPY); }
    if (numberX_1 == 2 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_2, 0, 0, SRCCOPY); }
    if (numberX_1 == 3 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_3, 0, 0, SRCCOPY); }
    if (numberX_1 == 4 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_4, 0, 0, SRCCOPY); }
    if (numberX_1 == 5 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_5, 0, 0, SRCCOPY); }
    if (numberX_1 == 6 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_6, 0, 0, SRCCOPY); }
    if (numberX_1 == 7 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_7, 0, 0, SRCCOPY); }
    if (numberX_1 == 8 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_8, 0, 0, SRCCOPY); }
    if (numberX_1 == 9 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X, 598, 28, 64, memBitNumbX_9, 0, 0, SRCCOPY); }

    if (numberX_2 == 0 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_0, 0, 0, SRCCOPY); }
    if (numberX_2 == 1 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_1, 0, 0, SRCCOPY); }
    if (numberX_2 == 2 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_2, 0, 0, SRCCOPY); }
    if (numberX_2 == 3 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_3, 0, 0, SRCCOPY); }
    if (numberX_2 == 4 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_4, 0, 0, SRCCOPY); }
    if (numberX_2 == 5 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_5, 0, 0, SRCCOPY); }
    if (numberX_2 == 6 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_6, 0, 0, SRCCOPY); }
    if (numberX_2 == 7 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_7, 0, 0, SRCCOPY); }
    if (numberX_2 == 8 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_8, 0, 0, SRCCOPY); }
    if (numberX_2 == 9 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBitNumbX_9, 0, 0, SRCCOPY); }

    int posNumber1_O = 980;

    if (numberO_1 == 0 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_0, 0, 0, SRCCOPY); }
    if (numberO_1 == 1 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_1, 0, 0, SRCCOPY); }
    if (numberO_1 == 2 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_2, 0, 0, SRCCOPY); }
    if (numberO_1 == 3 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_3, 0, 0, SRCCOPY); }
    if (numberO_1 == 4 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_4, 0, 0, SRCCOPY); }
    if (numberO_1 == 5 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_5, 0, 0, SRCCOPY); }
    if (numberO_1 == 6 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_6, 0, 0, SRCCOPY); }
    if (numberO_1 == 7 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_7, 0, 0, SRCCOPY); }
    if (numberO_1 == 8 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_8, 0, 0, SRCCOPY); }
    if (numberO_1 == 9 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O, 598, 28, 64, memBitNumbO_9, 0, 0, SRCCOPY); }

    if (numberO_2 == 0 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_0, 0, 0, SRCCOPY); }
    if (numberO_2 == 1 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_1, 0, 0, SRCCOPY); }
    if (numberO_2 == 2 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_2, 0, 0, SRCCOPY); }
    if (numberO_2 == 3 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_3, 0, 0, SRCCOPY); }
    if (numberO_2 == 4 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_4, 0, 0, SRCCOPY); }
    if (numberO_2 == 5 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_5, 0, 0, SRCCOPY); }
    if (numberO_2 == 6 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_6, 0, 0, SRCCOPY); }
    if (numberO_2 == 7 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_7, 0, 0, SRCCOPY); }
    if (numberO_2 == 8 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_8, 0, 0, SRCCOPY); }
    if (numberO_2 == 9 && (counter_start == -100 || StartGame == 4)) { BitBlt(memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBitNumbO_9, 0, 0, SRCCOPY); }

    if (StartGame == 4 && countLine1_X > countLine1_O) {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\X_Win2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    if (StartGame == 4 && countLine1_X > countLine1_O) {
        BitBlt(memDC, 686, 541, 328, 59, memBitX_Win, 0, 0, SRCCOPY);
    }


    if (StartGame == 4 && countLine1_O > countLine1_X) {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\O_Win.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }

    // dance men red
    if (StartGame == 4 && countLine1_O > countLine1_X) {
        BitBlt(memDC, 686, 541, 328, 59, memBitO_Win, 0, 0, SRCCOPY);
        if (tempm <= 4) {
            BitBlt(memDC, 730, 801, 318, 69, memBitO_WinMensPO, 0, 0, SRCCOPY);
        }
        else {
            BitBlt(memDC, 730, 801, 318, 69, memBitO_WinMensLO, 0, 0, SRCCOPY);
        }
        if (tempm == 9) {
            tempm = 0;
        }
        tempm = tempm + 1;
    }

    if (StartGame == 4 && countLine1_X > countLine1_O) {
        BitBlt(memDC, 686, 541, 328, 59, memBitX_Win, 0, 0, SRCCOPY);
        if (tempm <= 4) {
            BitBlt(memDC, 730, 801, 318, 69, memBitO_WinMensPX, 0, 0, SRCCOPY);
        }
        else {
            BitBlt(memDC, 730, 801, 318, 69, memBitO_WinMensLX, 0, 0, SRCCOPY);
        }
        if (tempm == 9) {
            tempm = 0;
        }
        tempm = tempm + 1;
    }

    // redPancel

    if (counter_start == -100 && botB.StasusModeGame == 1) {
        { BitBlt(memDC, arrayCoordinataX[posPancel] + 10, arrayCoordinataY[posPancel] - 2, 9, 23, memBitPancel, 0, 0, SRCCOPY); }
    }


    if (StartGame == -2) {
        StartGame = 0;
        SetTimer(hdc, ID_TIMER_BEFORE_START, 100, NULL);
    }

    if (counter_start == -100) {

        SetTimer(hdc, ID_TIMER_energy1, 100, NULL);
    }

    BitBlt(hdc, 0, 0, rct.right - rct.left, rct.bottom - rct.top, memDC, 0, 0, SRCCOPY);
    DeleteDC(memDC);
    DeleteObject(memBM);
}

LRESULT WINAPI WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

static HBITMAP hBitmap;
HDC hdc, hmdc, hdcMem;
PAINTSTRUCT ps;
BITMAP bitmap;
HGDIOBJ oldBitmap;
static BITMAP bm;
static RECT rc;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow )
{
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

    MSG  msg;
    WNDCLASSEXW wc = { 0 };
    wc.lpszClassName = L"ЧЩ";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(NULL_BRUSH);
    wc.lpfnWndProc = WndProc;
    wc.hIcon = LoadIcon(hInstance, IDI_ICON2);     // class icon
    wc.hIconSm = LoadIcon(hInstance, IDI_ICON2);
    /*  SetClassLong(hwnd, GCL_CBWNDEXTRA, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));*/

    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));

    HBITMAP hBitmap = LoadBitmap(hInstance, szImageName);

    LPPOINT pPnt;
    pPnt = malloc(sizeof(*pPnt));
    LPRECT rctt; // указатель на размер экрана
    rctt = malloc(sizeof(*pPnt));

    gameDuration = gameDurationBuf;

    SetCursor(LoadCursorFromFile(TEXT(".\\image\\pen1.cur")));

    RegisterClassW(&wc);
    hwnd = CreateWindow(wc.lpszClassName, L"TIC_",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_EX_TOPMOST,
        0, 0, 1280, 1024, 0, 0, hInstance, 0);

    SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 1280, 1024, SWP_SHOWWINDOW);

    ShowWindow(hwnd,
        SW_SHOWMAXIMIZED
    );
    changeDisplay();

    HDC hdc = GetDC(hwnd);

    // назначаю структурам позиции
    botB.Status = 0;
    botB.StasusModeGame = 0;
    botB.posX = 232;
    botB.posY = 314;
    botB.sizeX = 51;
    botB.sizeY = 48;
    
    RulesB.Status = 0;
    RulesB.posX = 233;
    RulesB.posY = 459;
    RulesB.sizeX = 191;
    RulesB.sizeY = 75;

    RulesI.Status = 0;
    RulesI.posX = 627;
    RulesI.posY = 158;
    RulesI.sizeX = 441;
    RulesI.sizeY = 749;

    ExitB.Status = 0;
    ExitB.posX = 181;
    ExitB.posY = 836;
    ExitB.sizeX = 58;
    ExitB.sizeY = 67;

    StopB.Status = 0;
    StopB.posX = 942;
    StopB.posY = 733;
    StopB.sizeX = 72;
    StopB.sizeY = 69;

    AuthorB.Status = 0;
    AuthorB.posX = 236;
    AuthorB.posY = 561;
    AuthorB.sizeX = 223;
    AuthorB.sizeY = 78;

    AuthorI.Status = 0;
    AuthorI.posX = 628;
    AuthorI.posY = 162;
    AuthorI.sizeX = 441;
    AuthorI.sizeY = 748;

    LeftB.Status = 0;
    LeftB.posX = 178;
    LeftB.posY = 734;
    LeftB.sizeX = 59;
    LeftB.sizeY = 64;

    RightB.Status = 0;
    RightB.posX = 489;
    RightB.posY = 741;
    RightB.sizeX = 61;
    RightB.sizeY = 52;

    TerpB.Status = 4;  // start speed
    TerpB.posX = 238;
    TerpB.posY = 733;
    TerpB.sizeX = 249;
    TerpB.sizeY = 69;

    SoundB.Status = 0;  
    SoundB.posX = 472;
    SoundB.posY = 835;
    SoundB.sizeX = 73;
    SoundB.sizeY = 69; 

    while (1) {
        if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) { // check the messages queue
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {

            update(hdc);

            GetCursorPos(pPnt);

            ScreenToClient(hwnd, pPnt);
            mouse_x = pPnt[0].x;
            mouse_y = pPnt[0].y;
            if(counter_start == - 100) gameDuration = gameDuration - 0.063;
            Watch(hwnd);
            VvodO_K(hwnd);
            convertPointInCoolO(hwnd);
            convertWatch(hwnd);
            changeMenu(hwnd);
           if (botB.StasusModeGame ==1) VvodO_s(hwnd);
           else { VvodO_bot(hwnd); };
           

            Sleep(50);
        }
    }
    return 0;


    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_SIZE:
        GetClientRect(hwnd, &rct); // размер экрана
    case WM_CREATE:

        PlaySoundW(TEXT(".\\sounds\\startSong.wav"), NULL, SND_FILENAME | SND_ASYNC);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Backround_v0.7_black.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        hdc = GetDC(hwnd);
        memBitBlack = CreateCompatibleDC(hdc);
        SelectObject(memBitBlack, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Backround_v0.10_whate.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBit3 = CreateCompatibleDC(hdc);
        SelectObject(memBit3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\pole1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitPole = CreateCompatibleDC(hdc);
        SelectObject(memBitPole, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX1 = CreateCompatibleDC(hdc);
        SelectObject(memBitX1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX2 = CreateCompatibleDC(hdc);
        SelectObject(memBitX2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX3 = CreateCompatibleDC(hdc);
        SelectObject(memBitX3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX4 = CreateCompatibleDC(hdc);
        SelectObject(memBitX4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX5 = CreateCompatibleDC(hdc);
        SelectObject(memBitX5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX6 = CreateCompatibleDC(hdc);
        SelectObject(memBitX6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO1 = CreateCompatibleDC(hdc);
        SelectObject(memBitO1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO2 = CreateCompatibleDC(hdc);
        SelectObject(memBitO2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO3 = CreateCompatibleDC(hdc);
        SelectObject(memBitO3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO4 = CreateCompatibleDC(hdc);
        SelectObject(memBitO4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO5 = CreateCompatibleDC(hdc);
        SelectObject(memBitO5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO6 = CreateCompatibleDC(hdc);
        SelectObject(memBitO6, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\bot_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitBot = CreateCompatibleDC(hdc);
        SelectObject(memBitBot, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\startGame.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitStartGame = CreateCompatibleDC(hdc);
        SelectObject(memBitStartGame, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\startGameV.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitStartGameV = CreateCompatibleDC(hdc);
        SelectObject(memBitStartGameV, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Rules_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitRules0 = CreateCompatibleDC(hdc);
        SelectObject(memBitRules0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Rules_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitRules1 = CreateCompatibleDC(hdc);
        SelectObject(memBitRules1, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Ruls.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitRuls = CreateCompatibleDC(hdc);
        SelectObject(memBitRuls, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Author0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitAuthor0 = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthor0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Author1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitAuthor1 = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthor1, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\AuthorPeople.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitAuthorPeople = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthorPeople, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\LeftChange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitLeft = CreateCompatibleDC(hdc);
        SelectObject(memBitLeft, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\RightChange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitRight = CreateCompatibleDC(hdc);
        SelectObject(memBitRight, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitTerp1 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitTerp2 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitTerp3 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitTerp4 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitTerp5 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp5, hBitmap);




        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\exit_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitExit0 = CreateCompatibleDC(hdc);
        SelectObject(memBitExit0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\exit_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitExit1 = CreateCompatibleDC(hdc);
        SelectObject(memBitExit1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\pancel.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitPancel = CreateCompatibleDC(hdc);
        SelectObject(memBitPancel, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX0 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX1 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX2 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX3 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX4 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX5 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX6 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX7 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX8 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX9 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX9, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_10.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyX10 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX10, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO0 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO1 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO2 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO2, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO3 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO4 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO5 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO5, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO6 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO7 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO8 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO9 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO9, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_10.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitEnergyO10 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO10, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O_win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO_Win = CreateCompatibleDC(hdc);
        SelectObject(memBitO_Win, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\x_win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitX_Win = CreateCompatibleDC(hdc);
        SelectObject(memBitX_Win, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_0 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_1 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_2 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_3 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_4 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_5 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_6 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_7 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_8 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbO_9 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_9, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_0 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_1 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_2 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_3 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_4 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_5 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_6 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_7 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_8 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitNumbX_9 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_9, hBitmap);

        // Whatch Number
        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT0 = CreateCompatibleDC(hdc);
        SelectObject(memBitT0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT1 = CreateCompatibleDC(hdc);
        SelectObject(memBitT1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT2 = CreateCompatibleDC(hdc);
        SelectObject(memBitT2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT3 = CreateCompatibleDC(hdc);
        SelectObject(memBitT3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT4 = CreateCompatibleDC(hdc);
        SelectObject(memBitT4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT5 = CreateCompatibleDC(hdc);
        SelectObject(memBitT5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT6 = CreateCompatibleDC(hdc);
        SelectObject(memBitT6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT7 = CreateCompatibleDC(hdc);
        SelectObject(memBitT7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT8 = CreateCompatibleDC(hdc);
        SelectObject(memBitT8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitT9 = CreateCompatibleDC(hdc);
        SelectObject(memBitT9, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_lO.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO_WinMensLO = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensLO, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_PO.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO_WinMensPO = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensPO, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_lX.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO_WinMensLX = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensLX, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_PX.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitO_WinMensPX = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensPX, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\sound0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitSound0 = CreateCompatibleDC(hdc);
        SelectObject(memBitSound0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\sound1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitSound1 = CreateCompatibleDC(hdc);
        SelectObject(memBitSound1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\sound2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitSound2 = CreateCompatibleDC(hdc);
        SelectObject(memBitSound2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\sound3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitSound3 = CreateCompatibleDC(hdc);
        SelectObject(memBitSound3, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\stop0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitStop0 = CreateCompatibleDC(hdc);
        SelectObject(memBitStop0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\stop1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        memBitStop1 = CreateCompatibleDC(hdc);
        SelectObject(memBitStop1, hBitmap);


        if (hBitmap == NULL) {
            MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
        }

        ReleaseDC(hwnd, hdc);

    case WM_PAINT:


        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rct);

        update(hdc);


        EndPaint(hdc, &ps);
        return 0;

    case WM_TIMER:

        if (counter_start != -100 && (StartGame == 2)) counter_start = counter_start - 1;

        if (counter_start == 0) {

            KillTimer(hwnd, ID_TIMER_START);
            counter_start = -100;
            CreateGameField(hwnd);

            // вставлять что обновить перед началом игры
            numberX_1 = 0;
            numberX_2 = 0;
            numberX_3 = 0;
            numberO_1 = 0;
            numberO_2 = 0;
            numberO_3 = 0;

        }

        if (StartGame == 4) {
            SetTimer(hwnd, ID_TIMER_BEFORE_START, 100, NULL);
            KillTimer(hwnd, ID_TIMER_energy1);
            energyX = 2;
            energyO = 2;
            gameDuration = gameDurationBuf;
        }

        break;


    case WM_DESTROY:
        DeleteObject(hBitmap);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int VvodO_s(HWND hwnd) {
    if (counter_start == -100) {
        if (GetKeyState('A') < 0 || GetKeyState(VK_LEFT) < 0) {
            if (posPancel - 10 > 0) {
                posPancel = posPancel - 10;  Sleep(100);
            }
        }
        if (GetKeyState('W') < 0 || GetKeyState(VK_UP) < 0) {
            if (posPancel - 1 > 0) {
                posPancel = posPancel - 1; Sleep(100);
            }
        }
        if (GetKeyState('S') < 0 || GetKeyState(VK_DOWN) < 0) {
            if (posPancel + 1 < 101) {
                posPancel = posPancel + 1; Sleep(100);
            }
        }

        if (GetKeyState('D') < 0 || GetKeyState(VK_RIGHT) < 0) {
            if (posPancel + 10 < 101) {
                posPancel = posPancel + 10; Sleep(100);
            }
        }

        if ((GetKeyState(VK_RETURN) < 0 || GetKeyState(VK_SPACE) < 0) && energyO > 1) {



            if (arrayP[posPancel] == L"") {
                arrayP[posPancel] = L"o1"; energyO = energyO - 1;
            }
        }
    }
}

int VvodO_K(HWND hwnd) {
    if (counter_start == -100)
    {
        for (int lp = 0; lp <= 100; lp++) {
            if (GetKeyState(VK_LBUTTON) < 0 && energyX > 1 && arrayP[lp] == L""
                && mouse_x >= arrayCoordinataX[lp] + 2
                && mouse_y >= arrayCoordinataY[lp] + 2
                && mouse_x <= arrayCoordinataX[lp] + 28
                && mouse_y <= arrayCoordinataY[lp] + 27
                ) {
                changeLeftClic[lp] = 1;
            }
            else { changeLeftClic[lp] = 0; }
            for (int lp = 0; lp <= 100; lp++) {
                if (changeLeftClic[lp] == 1) {
                    if (GetKeyState(VK_LBUTTON) >= 0 && energyX > 1 && arrayP[lp] == L""
                        && mouse_x >= arrayCoordinataX[lp] + 2
                        && mouse_y >= arrayCoordinataY[lp] + 2
                        && mouse_x <= arrayCoordinataX[lp] + 28
                        && mouse_y <= arrayCoordinataY[lp] + 27)
                    {
                        arrayP[lp] = L"x1"; energyX = energyX - 1;
                        changeLeftClic[lp] = 0;
                    }
                }
            }
        }
    }
}


int compareArray() {
    int  X5 = 0;
    int tempX = 0;
    //Считаем очки по линиям слева направо  
    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 10; i++) {

            if (arrayP[p + 1 + i * 10] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        tempX = 0;
    }

    //считаем очки по линиям сверху вниз
    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 10; i++) {

            if (arrayP[i + 1 + p * 10] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        tempX = 0;
    }
    // Косые вот такие \\ вправо
    int m1 = 10;
    for (int p = 0; p < 80; p = p + 10) {

        for (int i = 0; i < m1; i++) {

            if (arrayP[p + 1 + i * 11] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        } m1 = m1 - 1;
        tempX = 0;
    }

    // Косые вот такие \\ вниз
    int m2 = 8;
    for (int p = 1; p < 8; p = p + 1) {

        for (int i = 0; i <= m2; i++) {

            if (arrayP[p + 1 + i * 11] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        m2 = m2 - 1;
        tempX = 0;
    }

    // Косые вот такие // Вверх
    int m3 = 10;
    for (int p = 9; p > 1; p = p - 1) {

        for (int i = 0; i < m3; i++) {

            if (arrayP[p + 1 + i * 9] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        } m3 = m3 - 1;
        tempX = 0;
    }

    //// Косые вот такие // Вправо
    int m4 = 8;
    for (int p = 20; p < 90; p = p + 10) {

        for (int i = 0; i <= m4; i++) {

            if (arrayP[p + i * 9] == pX) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        m4 = m4 - 1;
        tempX = 0;
    }


    countLine1_X = X5;
}

int compareArrayO() {
    int  X5 = 0;
    int tempX = 0;
    /*  wchar_t* line1[10];*/

    //Считаем очки по линиям слева направо  
    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 10; i++) {

            if (arrayP[p + 1 + i * 10] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        tempX = 0;
    }

    //считаем очки по линиям сверху вниз
    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 10; i++) {

            if (arrayP[i + 1 + p * 10] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        tempX = 0;
    }
    // Косые вот такие \\ вправо
    int m1 = 10;
    for (int p = 0; p < 80; p = p + 10) {

        for (int i = 0; i < m1; i++) {

            if (arrayP[p + 1 + i * 11] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        } m1 = m1 - 1;
        tempX = 0;
    }
    // Косые вот такие \\ вниз
    int m2 = 8;
    for (int p = 1; p < 8; p = p + 1) {

        for (int i = 0; i <= m2; i++) {

            if (arrayP[p + 1 + i * 11] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        m2 = m2 - 1;
        tempX = 0;
    }
    // Косые вот такие // Вверх
    int m3 = 10;
    for (int p = 9; p > 1; p = p - 1) {

        for (int i = 0; i < m3; i++) {

            if (arrayP[p + 1 + i * 9] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        } m3 = m3 - 1;
        tempX = 0;
    }
    //// Косые вот такие // Вправо
    int m4 = 8;
    for (int p = 20; p < 90; p = p + 10) {

        for (int i = 0; i <= m4; i++) {

            if (arrayP[p + i * 9] == pO) {
                tempX = tempX + 1;
                if (tempX == 3) {
                    X5 = X5 + 1;
                }
                if (tempX == 5) {
                    X5 = X5 + 2;
                }
                if (tempX == 8) {
                    X5 = X5 + 1;
                }
                if (tempX == 10) {
                    X5 = X5 + 2;
                }
            }
            else {
                tempX = 0;
            }
        }
        m4 = m4 - 1;
        tempX = 0;
    }


    countLine1_O = X5;
}

int convertPointInCoolO(HWND hwnd) {
    if (countLine1_O < 10) {
        numberO_1 = countLine1_O;
    }
    else {
        if (countLine1_O < 100)
        {
            numberO_2 = floor(countLine1_O / 10);
            numberO_1 = countLine1_O - numberO_2 * 10;
        }
    }
    if (countLine1_X < 10) {
        numberX_1 = countLine1_X;
    }
    else {
        if (countLine1_X < 100)
        {
            numberX_2 = floor(countLine1_X / 10);
            numberX_1 = countLine1_X - numberX_2 * 10;
        }
    }

}

int convertWatch(HWND hwnd) {
    if (secondsLeft < 10) {
        secondsLeft1 = 0;
        secondsLeft2 = secondsLeft;
    }
    else {
        if (secondsLeft < 61)
        {
            secondsLeft1 = floor(secondsLeft / 10);
            secondsLeft2 = secondsLeft - secondsLeft1 * 10;
        }
    }

    if (countLine1_X < 10) {
        numberX_1 = countLine1_X;
    }
    else {
        if (countLine1_X < 100)
        {
            numberX_2 = floor(countLine1_X / 10);
            numberX_1 = countLine1_X - numberX_2 * 10;
        }
    }

}

int changeDisplay() {

    DEVMODE dm;
    {
        dm.dmSize = sizeof(DEVMODE);
        dm.dmPelsWidth = 1280;
        dm.dmPelsHeight = 1024;
        dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    }
    ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
}


int Watch(HWND hwnd) {
    minutsLeft = floor(gameDuration / 60);
    secondsLeft = gameDuration - (minutsLeft * 60);

    if (counter_start == -100 && energyX < 3 && energyX >= 2) {
        energeXadd = 0.1 * speed;
        energyX = energyX + energeXadd;

    }

    if (counter_start == -100 && energyO < 3 && energyO >= 2) {
        energeOadd = 0.1 * speed;
        energyO = energyO + energeOadd;
    }

    if (counter_start == -100 && energyX < 2 && energyX >= 1) {
        energeXadd = 0.066 * speed;
        energyX = energyX + energeXadd;

    }

    if (counter_start == -100 && energyO < 2 && energyO >= 1) {
        energeOadd = 0.066 * speed;
        energyO = energyO + energeOadd;
    }

    if (counter_start == -100 && energyX < 1) {
        energeXadd = 0.044 * speed;
        energyX = energyX + energeXadd;

    }
    if (counter_start == -100 && energyO < 1) {
        energeOadd = 0.044 * speed;
        energyO = energyO + energeOadd;
    }
    // Тиканье времени
    if (counter_start == -100) {
       
        if (tik_tak == 0) {
            if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\tik-tak2.wav"), NULL, SND_FILENAME | SND_ASYNC);
            tik_tak = 350;
        }
        else { tik_tak--; }
    }

    //Проверка конца игры по времени
    if (counter_start < -1 && (gameDuration <= 0 || WinPoint <= countLine1_X - countLine1_O || WinPoint <= countLine1_O - countLine1_X || sumArrayFlagField >=100)) {
        StartGame = 4;
        counter_start = 1;
        sumArrayFlagField = 0;
        gameDuration = gameDurationBuf;
    }

    // drow eneggy
    if (energyX >= 1) { energyX1 = 10; }
    else {
        energyX1 = floor(energyX * 10);
    }
    if (energyX >= 2) { energyX2 = 10; }
    else {
        energyX2 = floor((energyX - 1) * 10);
    }

    if (energyX >= 3) { energyX3 = 10; }
    else {
        energyX3 = floor((energyX - 2) * 10);
    }
    if (energyO >= 1) { energyO1 = 10; }
    else {
        energyO1 = floor(energyO * 10);
    }
    if (energyO >= 2) { energyO2 = 10; }

    else {
        energyO2 = floor((energyO - 1) * 10);
    }

    if (energyO >= 3) { energyO3 = 10; }

    else {
        energyO3 = floor((energyO - 2) * 10);
    }

}

int changeMenu(HWND hwnd) {
    // botButton
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= botB.posX
        && mouse_y >= botB.posY
        && mouse_x <= botB.posX + botB.sizeX
        && mouse_y <= botB.posY + botB.sizeY
        && StartGame >= 0 && StartGame != 2)
    {
        if (botB.StasusModeGame == 0) {
            if (SoundB.Status == 0 || SoundB.Status == 1)   PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);
            botB.StasusModeGame = 1;
            Sleep(300);
        }
        else {
            if (SoundB.Status == 0 || SoundB.Status == 1)    PlaySoundW(TEXT(".\\sounds\\delete.wav"), NULL, SND_FILENAME | SND_ASYNC);
            botB.StasusModeGame = 0;
            Sleep(300);
        }
    }

    if (mouse_x >= botB.posX
        && mouse_y >= botB.posY
        && mouse_x <= botB.posX + botB.sizeX
        && mouse_y <= botB.posY + botB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 6 || StartGame == 5))
    {
        botB.Status = 1;
    }
    else { botB.Status = 0; }

    // Start Game
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 237
        && mouse_y >= 360
        && mouse_x <= 237 + 321
        && mouse_y <= 360 + 66
        && (StartGame == 0 || StartGame == 4|| StartGame == 5 || StartGame == 6))
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        StartGame = 2;
        SetTimer(hwnd, ID_TIMER_START, 1000, NULL);
        KillTimer(hwnd, ID_TIMER_BEFORE_START);
        CreateGameField(hwnd);
        counter_start = 1;
        energyX = 2;
        energyO = 2;
        gameDuration = gameDurationBuf;
        countLine1_X = 0;
        countLine1_O = 0;
         }

    if (mouse_x >= 237
        && mouse_y >= 360
        && mouse_x <= 237 + 321
        && mouse_y <= 360 + 66
        && (StartGame !=2) && StartGame >=0 ) {
        StartB.Status = 2;
    }
    else { StartB.Status = 1; }

    // button Rules
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= RulesB.posX
        && mouse_y >= RulesB.posY
        && mouse_x <= RulesB.posX + RulesB.sizeX
        && mouse_y <= RulesB.posY + RulesB.sizeY
        && StartGame >=0 && StartGame !=2 && StartGame != 5)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        StartGame = 5;

    }

    if ((mouse_x >= RulesB.posX
        && mouse_y >= RulesB.posY
        && mouse_x <= RulesB.posX + RulesB.sizeX
        && mouse_y <= RulesB.posY + RulesB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 6)) || StartGame == 5  )
    {
        RulesB.Status = 1;

    }
    else { RulesB.Status = 0; }


    // button Author
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= AuthorB.posX
        && mouse_y >= AuthorB.posY
        && mouse_x <= AuthorB.posX + AuthorB.sizeX
        && mouse_y <= AuthorB.posY + AuthorB.sizeY
        && StartGame >= 0 && StartGame != 2 && StartGame != 6)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        StartGame = 6;

    }

    if ((mouse_x >= AuthorB.posX
        && mouse_y >= AuthorB.posY
        && mouse_x <= AuthorB.posX + AuthorB.sizeX
        && mouse_y <= AuthorB.posY + AuthorB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5)) || StartGame == 6)
    {
        AuthorB.Status = 1;

    }
    else { AuthorB.Status = 0; }

    // button Arrey Left
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= LeftB.posX
        && mouse_y >= LeftB.posY
        && mouse_x <= LeftB.posX + LeftB.sizeX
        && mouse_y <= LeftB.posY + LeftB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && speed > 0.06 && TerpB.Status >1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        speed = speed - 0.06;
        TerpB.Status = TerpB.Status - 1;
        Sleep(400);
    }
   

    if (mouse_x >= LeftB.posX
        && mouse_y >= LeftB.posY
        && mouse_x <= LeftB.posX + LeftB.sizeX
        && mouse_y <= LeftB.posY + LeftB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && speed > 0.06 && TerpB.Status > 1)
    {
        LeftB.Status = 1;
        
    }
    else { LeftB.Status = 0; }
  

    // button Arrey Right
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= RightB.posX
        && mouse_y >= RightB.posY
        && mouse_x <= RightB.posX + RightB.sizeX
        && mouse_y <= RightB.posY + RightB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && speed != 0.30 && TerpB.Status !=5) {

        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);
            

        speed = speed + 0.06;
        TerpB.Status = TerpB.Status +1;
        Sleep(300);
    }

    if (mouse_x >= RightB.posX
        && mouse_y >= RightB.posY
        && mouse_x <= RightB.posX + RightB.sizeX
        && mouse_y <= RightB.posY + RightB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && speed != 0.30 && TerpB.Status !=5)
    {
        RightB.Status = 1;

    }
    else { RightB.Status = 0; }

    //Button Lamp
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 90
        && mouse_y >= 26
        && mouse_x <= 151
        && mouse_y <= 90
        && (StartGame == -1 || StartGame == 5 || StartGame == 6) && OnOffLeight == 0
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        /*CreateGameField(hdc);*/
        StartGame = -2;
        OnOffLeight = 1;
    }

    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 90
        && mouse_y >= 26
        && mouse_x <= 151
        && mouse_y <= 90
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && OnOffLeight == 1
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        StartGame = -1;
        OnOffLeight = 0;
    }

    // Button Stop
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= StopB.posX
        && mouse_y >= StopB.posY
        && mouse_x <= StopB.posX + StopB.sizeX
        && mouse_y <= StopB.posY + StopB.sizeY
        && (counter_start == -100)
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\otriv.wav"), NULL, SND_FILENAME | SND_ASYNC);
        CreateGameField(hdc);
        StartGame = 0;
        counter_start = 1;
        energyX = 2;
        energyO = 2;
        gameDuration = gameDurationBuf;
      

    }

    if (mouse_x >= StopB.posX
        && mouse_y >= StopB.posY
        && mouse_x <= StopB.posX + StopB.sizeX
        && mouse_y <= StopB.posY + StopB.sizeY
        && (counter_start == -100))
    {
        StopB.Status = 1;

    }
    else { StopB.Status = 0; }


    // button Sound
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= SoundB.posX
        && mouse_y >= SoundB.posY
        && mouse_x <= SoundB.posX + SoundB.sizeX
        && mouse_y <= SoundB.posY + SoundB.sizeY
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)
        {
            PlaySoundW(TEXT(".\\sounds\\onOffSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            SoundB.Status = 3;
            Sleep(300);
        }

        else {
            if (SoundB.Status == 2 || SoundB.Status == 3) {
                PlaySoundW(TEXT(".\\sounds\\onOffSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
                SoundB.Status = 1;
                Sleep(300);
            }
        }
    }



    if (mouse_x >= SoundB.posX
        && mouse_y >= SoundB.posY
        && mouse_x <= SoundB.posX + SoundB.sizeX
        && mouse_y <= SoundB.posY + SoundB.sizeY
        ) 
    {
        if(SoundB.Status == 0)
        SoundB.Status = 1;
        else {
        if (SoundB.Status == 2) {
            SoundB.Status = 3;
    }
    }

    }
    else {
        if (SoundB.Status == 1) {
            SoundB.Status = 0;
        }
        else  if (SoundB.Status == 3) {
            SoundB.Status = 2;
        }
        
         }

    // button Exit
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= ExitB.posX
        && mouse_y >= ExitB.posY
        && mouse_x <= ExitB.posX + ExitB.sizeX
        && mouse_y <= ExitB.posY + ExitB.sizeY
        )
    {
        PostQuitMessage(0);
    }

    if (mouse_x >= ExitB.posX
        && mouse_y >= ExitB.posY
        && mouse_x <= ExitB.posX + ExitB.sizeX
        && mouse_y <= ExitB.posY + ExitB.sizeY
        ) {
        ExitB.Status = 1;

    }
    else { ExitB.Status = 0; }


    // button Rules
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 770
        && mouse_y >= 10
        && mouse_x <= 1000
        && mouse_y <= 100
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6))

    {
        changeLeftClic[0] = 1;

    }

    if (GetKeyState(VK_LBUTTON) >= 0
        && mouse_x >= 770
        && mouse_y >= 10
        && mouse_x <= 1000
        && mouse_y <= 100
        && (StartGame == 0 || StartGame == 4 || StartGame == 5 || StartGame == 6) && changeLeftClic[0] == 1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\zavod.wav"), NULL, SND_FILENAME | SND_ASYNC);
        changeLeftClic[0] = 0;
    
        if (gameDurationBuf == 540) {
            gameDurationBuf = 60;
        }
        else { gameDurationBuf = gameDurationBuf + 30;}

        gameDuration = gameDurationBuf;
    }
 
}

int sumFlagField() {
    int tempV =0;
    for (int i = 1; i <= 100; i++) {
        if (arrayFlag[i] == 1) {
            tempV = tempV + 1; 
        }
    }
    sumArrayFlagField = tempV;
    tempV = 0;
}

int VvodO_bot(HWND hwnd) {

    if (counter_start == -100 && botB.StasusModeGame == 0 && energyO >= 3)
    {
       
        if (arrayP[55] == L"" && energyO >= 1) {
            arrayP[55] = L"o1";
            energyO = energyO - 1;
        }
        else {
            if (arrayP[56] == L"" && energyO >= 1) {
                arrayP[56] = L"o1";
                energyO = energyO - 1;
            }
            else {
                if (arrayP[46] == L"" && energyO >= 1) {
                    arrayP[46] = L"o1";
                    energyO = energyO - 1;
                }
                else  if (arrayP[45] == L"" && energyO >= 1) {
                    arrayP[45] = L"o1";
                    energyO = energyO - 1;
                }
                // AI

                else {
                    int resultR = 1;
                    struct arrayGradeBot {
                        int right[101], left[101], up[101], down[101], rightX[101], leftX[101], upX[101], downX[101], result[101];
                    } arrayGB;
                    for (int i = 0; i < 101; i++) {
                        arrayGB.rightX[i] = 0;
                        arrayGB.right[i] = 0;
                        arrayGB.left[i] = 0;
                        arrayGB.leftX[i] = 0;
                        arrayGB.upX[i] = 0;
                        arrayGB.up[i] = 0;
                        arrayGB.downX[i] = 0;
                        arrayGB.down[i] = 0;
                    }
                    for (int i = 1; i <= 100; i++) {
                        if (arrayP[i] == L"") {

                            // right
                            int tempRX = 0;
                            for (int iOR = 1; iOR < 10; iOR++) {
                                if((i + iOR * 10)<101){
                                if (arrayP[i + iOR * 10] == L"x" 
                                    && tempRX < 5) {
                                    tempRX = tempRX + 1;
                                    arrayGB.rightX[i] = tempRX;
                                }
                                else {
                                    arrayGB.rightX[i] = tempRX;
                                    tempRX = 0;
                                    iOR = 10;
                                }
                                }
                            }
                            //left
                            int tempLX = 0;
                            for (int iOL = 1; iOL < 10; iOL++) {
                                if ((i - iOL * 10) > 0) {
                                    if (arrayP[i - iOL * 10] == L"x"
                                        && tempLX < 5) {
                                        tempLX = tempLX + 1;
                                        arrayGB.leftX[i] = tempLX;
                                    }
                                    else {
                                        arrayGB.leftX[i] = tempLX;
                                        tempLX = 0;
                                        iOL = 10;
                                    }
                                }
                            }
                            //up
                            int tempUX = 0;
                            for (int iOU = 1; iOU < 10; iOU++) {
                                if (i - iOU == 10 || i - iOU == 0 || i - iOU == 20 || i - iOU == 30 || i - iOU == 40 ||
                                    i - iOU == 50 || i - iOU == 60 || i - iOU == 70 || i - iOU == 80 || i - iOU == 90) {
                                    iOU = 10;
                                   
                                }
                                else {
                                    if (arrayP[i - iOU] == L"x" && tempUX < 5) {
                                        tempUX = tempUX + 1;
                                        arrayGB.upX[i] = tempUX;
                                    }
                                    else {
                                        arrayGB.upX[i] = tempUX;
                                        tempUX = 0;
                                        iOU = 10;
                                    }
                                }
                            }
                            //down
                            int tempDX = 0;
                            for (int iOD = 1; iOD < 10; iOD++) {
                                if (i + iOD == 11 || i + iOD == 101 || i + iOD == 21 || i + iOD == 31 || i + iOD == 41 ||
                                    i + iOD == 51 || i + iOD == 61 || i + iOD == 71 || i + iOD == 81 || i + iOD == 91) {
                                    iOD = 10;
                                    
                                }
                                else {
                                    if (arrayP[i + iOD] == L"x" && tempDX < 5) {
                                        tempDX = tempDX + 1;
                                        arrayGB.downX[i] = tempDX;
                                    }
                                    else {
                                        arrayGB.downX[i] = tempDX;
                                        tempDX = 0;
                                        iOD = 10;
                                    }
                                }
                            }

                            // right
                            int tempR = 0;
                            for (int iOR = 1; iOR < 10; iOR++) {
                                if ((i + iOR * 10) < 101) {
                                    if (arrayP[i + iOR * 10] == L"o" && tempR < 5) {
                                        tempR = tempR + 1;
                                        arrayGB.right[i] = tempR;
                                    }
                                    else {
                                        arrayGB.right[i] = tempR;
                                        tempR = 0;
                                        iOR = 10;
                                    }
                                }
                            }
                                //left
                                int tempL = 0;
                                for (int iOL = 1; iOL < 10; iOL++) {
                                    if ((i - iOL * 10) >= 1) {
                                        if (arrayP[i - iOL * 10] == L"o" && tempL < 5) {
                                            tempL = tempL + 1;
                                            arrayGB.left[i] = tempL;
                                        }
                                        else {
                                            arrayGB.left[i] = tempL;
                                            tempL = 0;
                                            iOL = 10;
                                        }
                                    }
                                }
                                    //up
                                    int tempU = 0;
                                    for (int iOU = 1; iOU < 10; iOU++) {
                                        if (i - iOU == 10 || i - iOU == 0 || i - iOU == 20 || i - iOU == 30 || i - iOU == 40 ||
                                            i - iOU == 50 || i - iOU == 60 || i - iOU == 70 || i - iOU == 80 || i - iOU == 90) {
                                            iOU = 11;
                                          
                                        }
                                        else {
                                            if (arrayP[i - iOU] == L"o" && tempU < 5) {
                                                tempU = tempU + 1;
                                                arrayGB.up[i] = tempU;
                                            }
                                            else {
                                                arrayGB.up[i] = tempU;
                                                tempU = 0;
                                                iOU = 10;
                                            }
                                        }
                                    }
                                            //down
                                            int tempD = 0;
                                            for (int iOD = 1; iOD < 10; iOD++) {
                                                if (i + iOD == 11 || i + iOD == 101 || i + iOD == 21 || i + iOD == 31 || i + iOD == 41 ||
                                                    i + iOD == 51 || i + iOD == 61 || i + iOD == 71 || i + iOD == 81 || i + iOD == 91) {
                                                    iOD = 11;
                                                 
                                                }
                                                else {
                                                    if (arrayP[i + iOD] == L"o" && tempD < 5) {
                                                        tempD = tempD + 1;
                                                        arrayGB.down[i] = tempD;
                                                    }
                                                    else {
                                                        arrayGB.down[i] = tempD;
                                                        tempD = 0;
                                                        iOD = 10;
                                                    }
                                                }
                                            }
                                        
                        arrayGB.result[i] = 0;
                        int tempArray[8];

                        tempArray[0] = arrayGB.rightX[i];
                        tempArray[1] = arrayGB.leftX[i];
                        tempArray[2] = arrayGB.upX[i];
                        tempArray[3] = arrayGB.downX[i];
                        tempArray[4] = arrayGB.right[i];
                        tempArray[5] = arrayGB.left[i];
                        tempArray[6] = arrayGB.up[i];
                        tempArray[7] = arrayGB.down[i];

                        int maxP = 0;
                        for (int ii = 0; ii <= 7; ii++) {
                            if (tempArray[ii] > arrayGB.result[i]) {
                                if (tempArray[ii] > maxP) {
                                    maxP = tempArray[ii];
                                    arrayGB.result[i] = tempArray[ii];
                                }
                            }


                        }
                    }
                    }

                    int max = 0;
                    for (int iRes = 2; iRes < 100; iRes++) {
                        if(arrayP[iRes] == L"") {
                        if (arrayGB.result[iRes] > arrayGB.result[iRes-1])
                        {
                            if (arrayGB.result[iRes] > max) {
                                max = arrayGB.result[iRes];
                                resultR = iRes;
                            }
                        }
                        }
                    }
                    if (energyO >= 1 && arrayP[resultR] == L"") {
                        arrayP[resultR] = L"o1";
                        energyO = energyO -0.95;
    
                    }
                }
            }
        }
    }
}