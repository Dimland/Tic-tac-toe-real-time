#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "shcore.lib")

#define DPI_AWARENESS_CONTEXT_UNAWARE              ((DPI_AWARENESS_CONTEXT)-1)
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


//First1.rc

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


typedef struct startButton Start_Button;

wchar_t* arrayP[10000];
int arrayCoordinataX[100];
int arrayCoordinataY[100];

BOOL arrayFlag[100];

char id000[] = "X";
char id01[] = "01";
int countLine1_X = 0; //point x
int countLine1_O = 0; // point O
int WinPoint = 21; // Разница point при которой победит одна из сторон
int changeLeftClic[100];
wchar_t* pX = L"x";
wchar_t* notSimvol = L"";
wchar_t* pO = L"o";
int StartGame = -1;
int countX = 0;
int VVVod;
int FinishGame = 0;

wchar_t line1[10];
wchar_t buff[100];


// For Cool numbers
int numberX_1 = 0;
int numberX_2 = 0;
int numberX_3 = 0;
int numberO_1 = 0;
int numberO_2 = 0;
int numberO_3 = 0;

// energy
double energyX = 30;
double energyO = 30;

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

HWND hed;
HWND hBtn;
HWND hStatic;
int len;
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


HWND TimerStart;
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
        FinishGame = 0;
}


void update(HDC hdc) {

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP memBM = CreateCompatibleBitmap(hdc, rct.right - rct.left, rct.bottom - rct.top);
    SelectObject(memDC, memBM);



    if (StartGame == -1) BitBlt(memDC, 0, 0, 1280, 1024, memBitBlack, 0, 0, SRCCOPY);

    if (StartGame != -1) BitBlt(memDC, 0, 0, 1280, 1024, memBit3, 0, 0, SRCCOPY);


    // drowField
    if (StartGame == 4 || counter_start == -100) { BitBlt(memDC, 677, 173, 395, 565, memBitPole, 0, 0, SRCCOPY); }


    // ButtonStartGame

    if (StartB.Status == 1 && StartGame != -1) { BitBlt(memDC, 237, 355, 321, 71, memBitStartGame, 0, 0, SRCCOPY); }
    if (StartB.Status == 2 && StartGame != -1) { BitBlt(memDC, 237, 355, 321, 71, memBitStartGameV, 0, 0, SRCCOPY); }



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
   

    // ButtonExit
    if (ExitB.Status == 0 && StartGame != -1) { BitBlt(memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBitExit0, 0, 0, SRCCOPY); }
    if (ExitB.Status == 1 && StartGame != -1) { BitBlt(memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBitExit1, 0, 0, SRCCOPY); }


    // ButtonStop
    if (StopB.Status == 0 && counter_start == -100)  BitBlt(memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBitStop0, 0, 0, SRCCOPY);
    if (StopB.Status == 1 && counter_start == -100) BitBlt(memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBitStop1, 0, 0, SRCCOPY);


    // Rectangle(memDC, 0, 0, 300, 300);

    for (int i = 1; i <= 100; i++) {
        if (arrayP[i] == L"x" && StartGame != -1 && (StartGame ==2 || StartGame ==4)) {
            BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX6, 0, 0, SRCCOPY); arrayFlag[i] = 1; 
        }
        if (arrayP[i] == L"x5") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX5, 0, 0, SRCAND); arrayP[i] = L"x"; tik_tak = 10;
        }
        if (arrayP[i] == L"x4") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX4, 0, 0, SRCAND); arrayP[i] = L"x5"; }
        if (arrayP[i] == L"x3") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX3, 0, 0, SRCAND); arrayP[i] = L"x4"; }
        if (arrayP[i] == L"x2") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX2, 0, 0, SRCAND); arrayP[i] = L"x3"; }
        if (arrayP[i] == L"x1") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitX1, 0, 0, SRCAND); arrayP[i] = L"x2";  PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC); }

        if (arrayP[i] == L"o" && StartGame != -1 && (StartGame == 2 || StartGame == 4)) {
            BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO6, 0, 0, SRCCOPY); arrayFlag[i] = 1;
        }
        if (arrayP[i] == L"o5") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO5, 0, 0, SRCAND); arrayP[i] = L"o"; }
        if (arrayP[i] == L"o4") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO4, 0, 0, SRCAND); arrayP[i] = L"o5"; tik_tak = 10;
        }
        if (arrayP[i] == L"o3") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO3, 0, 0, SRCAND); arrayP[i] = L"o4"; }
        if (arrayP[i] == L"o2") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO2, 0, 0, SRCAND); arrayP[i] = L"o3"; }
        if (arrayP[i] == L"o1") { BitBlt(memDC, arrayCoordinataX[i], arrayCoordinataY[i], 28, 28, memBitO1, 0, 0, SRCAND); arrayP[i] = L"o2";  PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC); }

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



    if (StartGame == 4 && countLine1_X > countLine1_O && FinishGame == 0) {
        PlaySoundW(TEXT(".\\sounds\\X_Win2.wav"), NULL, SND_FILENAME | SND_ASYNC); FinishGame = 1;
    }
    if (StartGame == 4 && countLine1_X > countLine1_O) {
        BitBlt(memDC, 686, 541, 328, 59, memBitX_Win, 0, 0, SRCCOPY);
    }


    if (StartGame == 4 && countLine1_O > countLine1_X && FinishGame == 0) {
        PlaySoundW(TEXT(".\\sounds\\O_Win.wav"), NULL, SND_FILENAME | SND_ASYNC); FinishGame = 1;
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



    if (counter_start == -100) {
        { BitBlt(memDC, arrayCoordinataX[posPancel] + 10, arrayCoordinataY[posPancel] - 2, 9, 23, memBitPancel, 0, 0, SRCCOPY); }
    }



    //Point X
    if (counter_start == -100 || StartGame == 4) {
        compareArray();
        /*    int c = wsprintf(buferForInt, TEXT("%i"), countLine1_X);
            TextOut(memDC, 700, 600, buferForInt, c);*/

    }


    //int energX = _swprintf(buferForInt, TEXT("Энергия X: %f"), energyX);
    //TextOut(memDC, 800, 950, buferForInt, energX );

    if (counter_start == -100 || StartGame == 4) {
        compareArrayO();

        //Point O
     /*   int c = wsprintf(buferForInt, TEXT("%i "), countLine1_O);
        TextOut(memDC, 900, 600, buferForInt, c);*/
    }

    //if (counter_start == -100) {

    //    int c = wsprintf(buferForInt, TEXT("%i "), minutsLeft);
    //    TextOut(memDC, 800, 50, buferForInt, c);
    //}

    //if (counter_start == -100) {

    //    int c = wsprintf(buferForInt, TEXT(" : %i"), secondsLeft);
    //    TextOut(memDC, 808, 50, buferForInt, c);
    //}

    /* int energO = _swprintf(buferForInt, TEXT("Энергия O: %f"), energyO);
     TextOut(memDC, 1000, 950, buferForInt, energO-5 );*/

    //int cTime = wsprintf(buferForInt, TEXT("До начала игры:%i"), counter_start);
    //TimerStart = TextOut(memDC, 25, 10, buferForInt, cTime);



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


HWND vvod;

HWND ButtonStart;


HWND arrayHWND[100];


static HBITMAP hBitmap;
HDC hdc, hmdc, hdcMem;
PAINTSTRUCT ps;
BITMAP bitmap;

HGDIOBJ oldBitmap;
static BITMAP bm;
static RECT rc;







int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,

    PWSTR lpCmdLine, int nCmdShow





) {
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


    /*  wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_FUNKY));
      LoadCursorFromFile(TEXT("pen.cur"));*/





    HBITMAP hBitmap = LoadBitmap(hInstance, szImageName);


    LPPOINT pPnt;
    pPnt = malloc(sizeof(*pPnt));
    LPRECT rctt; // указатель на размер экрана
    rctt = malloc(sizeof(*pPnt));





 





    gameDuration = gameDurationBuf;

    SetCursor(LoadCursorFromFile(TEXT("pen1.cur")));




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

            VvodO_K(hwnd);
            VvodO_s(hwnd);
            Watch(hwnd);
            convertPointInCoolO(hwnd);
            convertWatch(hwnd);
            changeMenu(hwnd);

            //  твои функции для главного цикла
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

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Backround_v0.9_whate.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
       
        memBit3 = CreateCompatibleDC(hdc);
        SelectObject(memBit3, hBitmap);

        /* ButtonStart = CreateWindowW(L"Button", L"Start game",
             WS_VISIBLE | WS_CHILD,
             160, 10, 120, 20, hwnd, (HMENU)105, NULL, NULL);*/


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\pole1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitPole = CreateCompatibleDC(hdc);
        SelectObject(memBitPole, hBitmap);





        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX1 = CreateCompatibleDC(hdc);
        SelectObject(memBitX1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX2 = CreateCompatibleDC(hdc);
        SelectObject(memBitX2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX3 = CreateCompatibleDC(hdc);
        SelectObject(memBitX3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX4 = CreateCompatibleDC(hdc);
        SelectObject(memBitX4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX5 = CreateCompatibleDC(hdc);
        SelectObject(memBitX5, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX6 = CreateCompatibleDC(hdc);
        SelectObject(memBitX6, hBitmap);



        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO1 = CreateCompatibleDC(hdc);
        SelectObject(memBitO1, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO2 = CreateCompatibleDC(hdc);
        SelectObject(memBitO2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO3 = CreateCompatibleDC(hdc);
        SelectObject(memBitO3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO4 = CreateCompatibleDC(hdc);
        SelectObject(memBitO4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO5 = CreateCompatibleDC(hdc);
        SelectObject(memBitO5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO6 = CreateCompatibleDC(hdc);
        SelectObject(memBitO6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\startGame.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitStartGame = CreateCompatibleDC(hdc);
        SelectObject(memBitStartGame, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\startGameV.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitStartGameV = CreateCompatibleDC(hdc);
        SelectObject(memBitStartGameV, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Rules_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitRules0 = CreateCompatibleDC(hdc);
        SelectObject(memBitRules0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Rules_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitRules1 = CreateCompatibleDC(hdc);
        SelectObject(memBitRules1, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Ruls.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitRuls = CreateCompatibleDC(hdc);
        SelectObject(memBitRuls, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Author0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitAuthor0 = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthor0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Author1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitAuthor1 = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthor1, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\AuthorPeople.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitAuthorPeople = CreateCompatibleDC(hdc);
        SelectObject(memBitAuthorPeople, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\LeftChange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitLeft = CreateCompatibleDC(hdc);
        SelectObject(memBitLeft, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\RightChange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitRight = CreateCompatibleDC(hdc);
        SelectObject(memBitRight, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitTerp1 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitTerp2 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitTerp3 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitTerp4 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp4, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Terp5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitTerp5 = CreateCompatibleDC(hdc);
        SelectObject(memBitTerp5, hBitmap);

       


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\exit_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitExit0 = CreateCompatibleDC(hdc);
        SelectObject(memBitExit0, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\exit_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitExit1 = CreateCompatibleDC(hdc);
        SelectObject(memBitExit1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\pancel.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitPancel = CreateCompatibleDC(hdc);
        SelectObject(memBitPancel, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX0 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX1 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX2 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX3 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX4 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyX5 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX5, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX6 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX6, hBitmap);
        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyX7 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyX8 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX8, hBitmap);
        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyX9 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX9, hBitmap);
        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyX_10.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyX10 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyX10, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO0 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO1 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO2 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO2, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO3 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO4 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO5 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO5, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);

        memBitEnergyO6 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyO7 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyO8 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyO9 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO9, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\EnergyO_10.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitEnergyO10 = CreateCompatibleDC(hdc);
        SelectObject(memBitEnergyO10, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O_win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO_Win = CreateCompatibleDC(hdc);
        SelectObject(memBitO_Win, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\x_win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitX_Win = CreateCompatibleDC(hdc);
        SelectObject(memBitX_Win, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_0 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_1 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_2 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_3 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_4 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_5 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_6 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_7 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_8 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\O-9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbO_9 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbO_9, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_0 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_1 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_2 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_3 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_4 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_5 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_6 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_7 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_8 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\X-9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitNumbX_9 = CreateCompatibleDC(hdc);
        SelectObject(memBitNumbX_9, hBitmap);



        // Whatch Number

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT0 = CreateCompatibleDC(hdc);
        SelectObject(memBitT0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT1 = CreateCompatibleDC(hdc);
        SelectObject(memBitT1, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT2 = CreateCompatibleDC(hdc);
        SelectObject(memBitT2, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT3 = CreateCompatibleDC(hdc);
        SelectObject(memBitT3, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT4 = CreateCompatibleDC(hdc);
        SelectObject(memBitT4, hBitmap);


        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT5 = CreateCompatibleDC(hdc);
        SelectObject(memBitT5, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT6 = CreateCompatibleDC(hdc);
        SelectObject(memBitT6, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time7.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT7 = CreateCompatibleDC(hdc);
        SelectObject(memBitT7, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time8.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT8 = CreateCompatibleDC(hdc);
        SelectObject(memBitT8, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\Time9.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitT9 = CreateCompatibleDC(hdc);
        SelectObject(memBitT9, hBitmap);






        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_lO.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO_WinMensLO = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensLO, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_PO.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO_WinMensPO = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensPO, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_lX.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO_WinMensLX = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensLX, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\win_mens_PX.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitO_WinMensPX = CreateCompatibleDC(hdc);
        SelectObject(memBitO_WinMensPX, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\stop0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
        memBitStop0 = CreateCompatibleDC(hdc);
        SelectObject(memBitStop0, hBitmap);

        hBitmap = (HBITMAP)LoadImage(NULL, TEXT(".\\image\\stop1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        GetObject(hBitmap, sizeof(bm), &bm);
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
        //ControlFocus("EDIT", "", hwnd);



       /* InvalidateRect(hwnd, 0, 0);*/
     /*   RECT rc;
        SetRect(&rc, 600, 100, 1100, 1000);*/
        //InvalidateRect(hwnd, 0, FALSE);

        break;


    case WM_DESTROY:
        DeleteObject(hBitmap);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}



//HWND CreateButton(wchar_t* title, int x, int y, HWND hwnd, int id) {
//    HWND hwndX = CreateWindow(L"Button", title,
//        WS_VISIBLE | WS_CHILD,
//        x, y, 28, 28, hwnd, (HMENU)id, NULL, NULL);
//    return hwndX;
//}




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


        /*   if (GetKeyState(VK_RETURN) < 0) {
               SetFocus(hed);
           }*/
        if ((GetKeyState(VK_RETURN) < 0 || GetKeyState(VK_SPACE) < 0) && energyO > 1) {
            /*  len = GetWindowTextLength(hed) + 1;
              GetWindowText(hed, buff, len);*/

              //VVVod = 1000;

              //VVVod = wcstol(buff, 0, 10);

                  //if (i == 1 && p01 = L"") {


            if (arrayP[posPancel] == L"") {
                arrayP[posPancel] = L"o1"; energyO = energyO - 1;
                // DestroyWindow(arrayHWND[VVVod]); 


                //DestroyWindow(hed);
                //hed = CreateWindowW(L"Edit", notSimvol,
                //    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT | ES_NUMBER | WS_TABSTOP,
                //    400, 50, 120, 20, hwnd, (HMENU)EDIT_ID, NULL, NULL);

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
    /*  wchar_t* line1[10];*/

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
        gameDuration = gameDuration - 0.063;
        if (tik_tak == 0) {
            PlaySoundW(TEXT(".\\sounds\\tik-tak2.wav"), NULL, SND_FILENAME | SND_ASYNC); 
            tik_tak = 350;
        }
        else { tik_tak--; }
    }

    //Проверка конца игры по времени
    if (counter_start < -1 && (gameDuration <= 0 || WinPoint <= countLine1_X - countLine1_O || WinPoint <= countLine1_O - countLine1_X)) {
        StartGame = 4;
        counter_start = 1;
        FinishGame == 0;
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

    // Start Game
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 271
        && mouse_y >= 355
        && mouse_x <= 271 + 321
        && mouse_y <= 355 + 71
        && (StartGame == 0 || StartGame == 4|| StartGame == 5 || StartGame == 6))
    {


        PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);

        StartGame = 2;
        
        SetTimer(hwnd, ID_TIMER_START, 1000, NULL);
        KillTimer(hwnd, ID_TIMER_BEFORE_START);
        CreateGameField(hwnd);
        counter_start = 1;
        energyX = 2;
        energyO = 2;
        gameDuration = gameDurationBuf;

    }

    if (mouse_x >= 271
        && mouse_y >= 355
        && mouse_x <= 271 + 321
        && mouse_y <= 355 + 71
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
        PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        StartGame = 5;

    }

    if (mouse_x >= RulesB.posX
        && mouse_y >= RulesB.posY
        && mouse_x <= RulesB.posX + RulesB.sizeX
        && mouse_y <= RulesB.posY + RulesB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 6) && StartGame != 5)
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
        PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        StartGame = 6;

    }

    if (mouse_x >= AuthorB.posX
        && mouse_y >= AuthorB.posY
        && mouse_x <= AuthorB.posX + AuthorB.sizeX
        && mouse_y <= AuthorB.posY + AuthorB.sizeY
        && (StartGame == 0 || StartGame == 4 || StartGame == 5) && StartGame != 6)
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
        PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

        PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);
            

        speed = speed + 0.06;
        TerpB.Status = TerpB.Status +1;
        Sleep(400);
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
        PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
        PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
        PlaySoundW(TEXT(".\\sounds\\otriv.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
        PlaySoundW(TEXT(".\\sounds\\zavod.wav"), NULL, SND_FILENAME | SND_ASYNC);
        changeLeftClic[0] = 0;
    
        if (gameDurationBuf == 540) {
            gameDurationBuf = 60;
        }
        else { gameDurationBuf = gameDurationBuf + 30;}

        gameDuration = gameDurationBuf;
    }
 
}


