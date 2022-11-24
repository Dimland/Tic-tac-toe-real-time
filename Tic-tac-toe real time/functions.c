#include "Tic-tac-toe real time.h";

wchar_t* path[] = { L".\\image\\Backround_v0.7_black.bmp", L".\\image\\Backround_v0.11_whate.bmp", L".\\image\\pole1.bmp",	L".\\image\\X1.bmp",	L".\\image\\X2.bmp",	L".\\image\\X3.bmp",	L".\\image\\X4.bmp",	L".\\image\\X5.bmp",	L".\\image\\X6.bmp",	L".\\image\\O1.bmp",	L".\\image\\O2.bmp",	L".\\image\\O3.bmp",	L".\\image\\O4.bmp",	L".\\image\\O5.bmp",	L".\\image\\O.bmp",	L".\\image\\bot_1.bmp",	L".\\image\\startGame.bmp",	L".\\image\\StartGameV.bmp",	L".\\image\\Rules_0.bmp",	L".\\image\\Rules_1.bmp",	L".\\image\\Ruls.bmp",	L".\\image\\Author0.bmp",	L".\\image\\Author1.bmp",	L".\\image\\AuthorPeople.bmp",	L".\\image\\opponentLevel.bmp",	L".\\image\\leftOpB_0.bmp",	L".\\image\\RightOpB_0.bmp",	L".\\image\\leftOpB_1.bmp",	L".\\image\\RightOpB_1.bmp",	L".\\image\\LeftChange.bmp",	L".\\image\\RightChange.bmp",	L".\\image\\Terp1_1.bmp",	L".\\image\\Terp2.bmp",	L".\\image\\Terp3.bmp",	L".\\image\\Terp4.bmp",	L".\\image\\Terp5.bmp",	L".\\image\\exit_0.bmp",	L".\\image\\exit_1.bmp",	L".\\image\\pancel.bmp",
L".\\image\\O_win.bmp",	L".\\image\\x_win.bmp", L".\\image\\win_mens_lO.bmp",	L".\\image\\win_mens_PO.bmp",	L".\\image\\win_mens_lX.bmp",	L".\\image\\win_mens_PX.bmp",	L".\\image\\sound0.bmp",	L".\\image\\sound1.bmp",	L".\\image\\sound2.bmp",	L".\\image\\sound3.bmp",	L".\\image\\stop0.bmp",	L".\\image\\stop1.bmp",	L".\\image\\podskazka.bmp" };


wchar_t* pathEnergyX[] = { L".\\image\\EnergyX_0.bmp",	L".\\image\\EnergyX_1.bmp",	L".\\image\\EnergyX_2.bmp",	L".\\image\\EnergyX_3.bmp",	L".\\image\\EnergyX_4.bmp",	L".\\image\\EnergyX_5.bmp",	L".\\image\\EnergyX_6.bmp",	L".\\image\\EnergyX_7.bmp",	L".\\image\\EnergyX_8.bmp",	L".\\image\\EnergyX_9.bmp",	L".\\image\\EnergyX_10.bmp" };
wchar_t* pathEnergyO[] = { L".\\image\\EnergyO_0.bmp",	L".\\image\\EnergyO_1.bmp",	L".\\image\\EnergyO_2.bmp",	L".\\image\\EnergyO_3.bmp",	L".\\image\\EnergyO_4.bmp",	L".\\image\\EnergyO_5.bmp",	L".\\image\\EnergyO_6.bmp",	L".\\image\\EnergyO_7.bmp",	L".\\image\\EnergyO_8.bmp",	L".\\image\\EnergyO_9.bmp",	L".\\image\\EnergyO_10.bmp" };
wchar_t* pathNumberWatch[] = { L".\\image\\Time0.bmp", L".\\image\\Time1.bmp", L".\\image\\Time2.bmp", L".\\image\\Time3.bmp", L".\\image\\Time4.bmp", L".\\image\\Time5.bmp", L".\\image\\Time6.bmp", L".\\image\\Time7.bmp", L".\\image\\Time8.bmp", L".\\image\\Time9.bmp" };
wchar_t* pathNumberX[] = { L".\\image\\X-0.bmp", L".\\image\\X-1.bmp",	L".\\image\\X-2.bmp",	L".\\image\\X-3.bmp",	L".\\image\\X-4.bmp",	L".\\image\\X-5.bmp",	L".\\image\\X-6.bmp",	L".\\image\\X-7.bmp",	L".\\image\\X-8.bmp",	L".\\image\\X-9.bmp" };
wchar_t* pathNumberO[] = { L".\\image\\O-0.bmp", L".\\image\\O-1.bmp",	L".\\image\\O-2.bmp",	L".\\image\\O-3.bmp",	L".\\image\\O-4.bmp",	L".\\image\\O-5.bmp",	L".\\image\\O-6.bmp",	L".\\image\\O-7.bmp",	L".\\image\\O-8.bmp",	L".\\image\\O-9.bmp" };

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

void addBeforeStartedvalue() {
  
    // Начальные значения
    sums_Field = 0;
    sumPoint_X = 0; //point x
    sumPoint_O = 0; // point O

    WinPoint = 40; // Разница point при которой победит одна из сторон
    changeLeftClic[99];
    pX = L"x";
    pO = L"o";
    GameMod = -1;
    ForTips = 0;
    speed = 0.24; // speed return energy
    speedBot = 1.8;
    counter_start = 1;
    tempm = 0;
    gameDuration = gameDurationBuf = 150;    // for watch
    tik_tak = 0;
  
    // assign positions to structures

    NumberX1.posX = 767;
    NumberX1.posY = 598;
    NumberX1.sizeX = 28;
    NumberX1.sizeY = 64;

    NumberX2.posX = 732;
    NumberX2.posY = 598;
    NumberX2.sizeX = 28;
    NumberX2.sizeY = 64;

    NumberO1.posX = 980;
    NumberO1.posY = 598;
    NumberO1.sizeX = 28;
    NumberO1.sizeY = 64;

    NumberO2.posX = 945;
    NumberO2.posY = 598;
    NumberO2.sizeX = 28;
    NumberO2.sizeY = 64;

    EnergyX1.posX = 698;
    EnergyX1.posY = 667;
    EnergyX1.sizeX = 30;
    EnergyX1.sizeY = 64;

    EnergyX2.posX = 733;
    EnergyX2.posY = 667;
    EnergyX2.sizeX = 30;
    EnergyX2.sizeY = 64;

    EnergyX3.posX = 768;
    EnergyX3.posY = 667;
    EnergyX3.sizeX = 30;
    EnergyX3.sizeY = 64;

    EnergyO1.posX = 979;
    EnergyO1.posY = 667;
    EnergyO1.sizeX = 30;
    EnergyO1.sizeY = 64;

    EnergyO2.posX = 944;
    EnergyO2.posY = 667;
    EnergyO2.sizeX = 30;
    EnergyO2.sizeY = 64;

    EnergyO3.posX = 909;
    EnergyO3.posY = 667;
    EnergyO3.sizeX = 30;
    EnergyO3.sizeY = 64;

    WatchB.posX = 770;
    WatchB.posY = 10;
    WatchB.sizeX = 230;
    WatchB.sizeY = 90;

    SecondL.Status = 0;
    SecondL.posX = 905;
    SecondL.posY = 18;
    SecondL.sizeX = 37;
    SecondL.sizeY = 73;

    SecondR.Status = 0;
    SecondR.posX = 949;
    SecondR.posY = 18;
    SecondR.sizeX = 37;
    SecondR.sizeY = 73;

    MinutL.Status = 0;
    MinutL.posX = 791;
    MinutL.posY = 18;
    MinutL.sizeX = 37;
    MinutL.sizeY = 73;

    MinutR.Status = 0;
    MinutR.posX = 835;
    MinutR.posY = 18;
    MinutR.sizeX = 37;
    MinutR.sizeY = 73;

    LightB.Status = 0;
    LightB.posX = 90;
    LightB.posY = 26;
    LightB.sizeX = 61;
    LightB.sizeY = 64;

    s_Field.sizeX_big = 35;
    s_Field.sizeY_big = 34;
    s_Field.sizeX_small = 28;
    s_Field.sizeY_small = 28;

    botB.Status = 0;
    botB.StasusModeGame = 0;
    botB.posX = 232;
    botB.posY = 314;
    botB.sizeX = 51;
    botB.sizeY = 48;

    podskazkaB.Status = 0;
    podskazkaB.posX = 1280;
    podskazkaB.posY = 550;
    podskazkaB.sizeX = 204;
    podskazkaB.sizeY = 511;

    StartB.Status = 1;
    StartB.posX = 237;
    StartB.posY = 360;
    StartB.sizeX = 321;
    StartB.sizeY = 66;

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

    Field.Status = 0;
    Field.posX = 677;
    Field.posY = 173;
    Field.sizeX = 395;
    Field.sizeY = 565;

    opponenLevelB.Status = 0;
    opponenLevelB.posX = 198;
    opponenLevelB.posY = 663;
    opponenLevelB.sizeX = 180;
    opponenLevelB.sizeY = 45;

    opponenLevelNumberB.Status = 1;
    opponenLevelNumberB.posX = 452;
    opponenLevelNumberB.posY = 632;
    opponenLevelNumberB.sizeX = 28;
    opponenLevelNumberB.sizeY = 64;

    LeftOpB.Status = 0;
    LeftOpB.posX = 416;
    LeftOpB.posY = 667;
    LeftOpB.sizeX = 31;
    LeftOpB.sizeY = 28;

    RightOpB.Status = 0;
    RightOpB.posX = 486;
    RightOpB.posY = 667;
    RightOpB.sizeX = 31;
    RightOpB.sizeY = 28;

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
}

void drawAll(HDC hdc) {
    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP memBM = CreateCompatibleBitmap(hdc, rct.right - rct.left, rct.bottom - rct.top);
    SelectObject(memDC, memBM);

    drawhLight(&memDC);
   
    drawNumberWatch(&memDC);
  
    drawButton(&memDC);
   
    drawRightPageBackground(&memDC);
 
    drawTips(&memDC);
  
    drawElementsXO(&memDC);

    drawRedPancel(&memDC);
   
    drawEnergy(&memDC);
  
    drawScore(&memDC);
  
    drawWin(&memDC);


    BitBlt(hdc, 0, 0, rct.right - rct.left, rct.bottom - rct.top, memDC, 0, 0, SRCCOPY);
    DeleteDC(memDC);
    DeleteObject(memBM);
}

void createTimer(HDC hdc) {

    if (GameMod == -2) {
        GameMod = 0;
        SetTimer(hdc, ID_TIMER_BEFORE_START, 100, NULL);
    }

    if (counter_start == -100) {

        SetTimer(hdc, ID_TIMER_energy1, 100, NULL);
    }
};

int KeyboardInput(HWND hwnd) {
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



            if (s_Field.field[posPancel] == L"") {
                s_Field.field[posPancel] = L"o1"; energyO = energyO - 1;
            }
        }
    }
}

int MouseInput(HWND hwnd) {
    if (counter_start == -100)
    {
        for (int lp = 0; lp <= 100; lp++) {
            if (GetKeyState(VK_LBUTTON) < 0 && energyX > 1 && s_Field.field[lp] == L""
                && mouse_x >= s_Field.coordinataX[lp] + 2
                && mouse_y >= s_Field.coordinataY[lp] + 2
                && mouse_x <= s_Field.coordinataX[lp] + 28
                && mouse_y <= s_Field.coordinataY[lp] + 28
                ) {
                changeLeftClic[lp] = 1;
            }
            else { changeLeftClic[lp] = 0; }
            for (int lp = 0; lp <= 100; lp++) {
                if (changeLeftClic[lp] == 1) {
                    if (GetKeyState(VK_LBUTTON) >= 0 && energyX > 1 && s_Field.field[lp] == L""
                        && mouse_x >= s_Field.coordinataX[lp] + 2
                        && mouse_y >= s_Field.coordinataY[lp] + 2
                        && mouse_x <= s_Field.coordinataX[lp] + 28
                        && mouse_y <= s_Field.coordinataY[lp] + 28)
                    {
                        s_Field.field[lp] = L"x1"; energyX = energyX - 1;
                        changeLeftClic[lp] = 0;
                    }
                }
            }
        }
    }
}

int BotMoves(HWND hwnd) {

    if (counter_start == -100 && botB.StasusModeGame == 0 && energyO >= speedBot)
    {

        if (s_Field.field[55] == L"" && energyO >= 1) {
            s_Field.field[55] = L"o1";
            energyO = energyO - 0.9;
        }
        else {
            if (s_Field.field[56] == L"" && energyO >= 1) {
                s_Field.field[56] = L"o1";
                energyO = energyO - 0.9;
            }
            else {
                if (s_Field.field[46] == L"" && energyO >= 1) {
                    s_Field.field[46] = L"o1";
                    energyO = energyO - 0.9;
                }
                else  if (s_Field.field[45] == L"" && energyO >= 1) {
                    s_Field.field[45] = L"o1";
                    energyO = energyO - 0.9;
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
                        if (s_Field.field[i] == L"") {

                            // right
                            int tempRX = 0;
                            for (int iOR = 1; iOR < 10; iOR++) {
                                if ((i + iOR * 10) < 101) {
                                    if (s_Field.field[i + iOR * 10] == L"x"
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
                                    if (s_Field.field[i - iOL * 10] == L"x"
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
                                    if (s_Field.field[i - iOU] == L"x" && tempUX < 5) {
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
                                    if (s_Field.field[i + iOD] == L"x" && tempDX < 5) {
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
                                    if (s_Field.field[i + iOR * 10] == L"o" && tempR < 5) {
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
                                    if (s_Field.field[i - iOL * 10] == L"o" && tempL < 5) {
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
                                    if (s_Field.field[i - iOU] == L"o" && tempU < 5) {
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
                                    if (s_Field.field[i + iOD] == L"o" && tempD < 5) {
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
                        if (s_Field.field[iRes] == L"") {
                            if (arrayGB.result[iRes] > arrayGB.result[iRes - 1])
                            {
                                if (arrayGB.result[iRes] > max) {
                                    max = arrayGB.result[iRes];
                                    resultR = iRes;
                                }
                            }
                        }
                    }
                    if (energyO >= 1 && s_Field.field[resultR] == L"") {
                        s_Field.field[resultR] = L"o1";
                        energyO = energyO - 0.87;

                    }
                }
            }
        }
    }
}

int sumPoint(wchar_t* who, int* sum) {
    int  X5 = 0;
    int tempX = 0;

    //Считаем очки по линиям слева направо  
    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 10; i++) {

            if (s_Field.field[p + 1 + i * 10] == who) {
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

            if (s_Field.field[i + 1 + p * 10] == who) {
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

            if (s_Field.field[p + 1 + i * 11] == who) {
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

            if (s_Field.field[p + 1 + i * 11] == who) {
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

            if (s_Field.field[p + 1 + i * 9] == who) {
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

            if (s_Field.field[p + i * 9] == who) {
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


   *sum = X5;
  
}

int convertPointInCoolO(HWND hwnd) {
    if (sumPoint_O < 10) {
        NumberO1.Status = sumPoint_O;
    }
    else {
        if (sumPoint_O < 100)
        {
            NumberO2.Status = floor(sumPoint_O / 10);
            NumberO1.Status = sumPoint_O - NumberO2.Status * 10;
        }
    }
    if (sumPoint_X < 10) {
        NumberX1.Status = sumPoint_X;
    }
    else {
        if (sumPoint_X < 100)
        {
            NumberX2.Status = floor(sumPoint_X / 10);
            NumberX1.Status = sumPoint_X - NumberX2.Status * 10;
        }
    }

}

int convertWatch(HWND hwnd) {
    MinutR.Status = floor(gameDuration / 60);
    int allSecond = gameDuration - (MinutR.Status * 60);

    if (allSecond < 10) {
        SecondL.Status = 0;
        SecondR.Status = allSecond;
    }
    else {
        if (allSecond < 61)
        {
            SecondL.Status = floor(allSecond / 10);
            SecondR.Status = allSecond - SecondL.Status * 10;
        }
    }
    if (counter_start == -100) { gameDuration = gameDuration - 0.063; }
}

int addEnergy(HWND hwnd) {
    double energyAdd;
        if (counter_start == -100 && energyX < 3 && energyX >= 2) {
            energyAdd = 0.1 * speed;
        energyX = energyX + energyAdd;

    }

    if (counter_start == -100 && energyO < 3 && energyO >= 2) {
        energyAdd = 0.1 * speed;
        energyO = energyO + energyAdd;
    }

    if (counter_start == -100 && energyX < 2 && energyX >= 1) {
        energyAdd = 0.066 * speed;
        energyX = energyX + energyAdd;

    }

    if (counter_start == -100 && energyO < 2 && energyO >= 1) {
        energyAdd = 0.066 * speed;
        energyO = energyO + energyAdd;
    }

    if (counter_start == -100 && energyX < 1) {
        energyAdd = 0.044 * speed;
        energyX = energyX + energyAdd;

    }
    if (counter_start == -100 && energyO < 1) {
        energyAdd = 0.044 * speed;
        energyO = energyO + energyAdd;
    }



    //Проверка конца игры
    if ((gameDuration <= 0 || WinPoint <= sumPoint_X - sumPoint_O || WinPoint <= sumPoint_O - sumPoint_X || sums_Field == 100)) {
        
        GameMod = 4;
        counter_start = 1;
        sums_Field = 0;
        gameDuration = gameDurationBuf;
       
        if (GameMod == 4 && sumPoint_X > sumPoint_O) {
            if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\X_Win2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        if (GameMod == 4 && sumPoint_O > sumPoint_X) {
            if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\O_Win.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
       

    }

    // Тиканье времени
    if (counter_start == -100) {

        if (tik_tak == 0) {
            if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\tik-tak2.wav"), NULL, SND_FILENAME | SND_ASYNC);
            tik_tak = 350;
        }
        else { tik_tak--; }
    }

        // draw eneggy
    if (energyX >= 1) { EnergyX1.Status = 10; }
    else {
        EnergyX1.Status = floor(energyX * 10);
    }
    if (energyX >= 2) { EnergyX2.Status = 10; }
    else {
        EnergyX2.Status = floor((energyX - 1) * 10);
    }

    if (energyX >= 3) { EnergyX3.Status = 10; }
    else {
        EnergyX3.Status = floor((energyX - 2) * 10);
    }
    if (energyO >= 1) { EnergyO1.Status = 10; }
    else {
        EnergyO1.Status = floor(energyO * 10);
    }
    if (energyO >= 2) { EnergyO2.Status = 10; }

    else {
        EnergyO2.Status = floor((energyO - 1) * 10);
    }

    if (energyO >= 3) { EnergyO3.Status = 10; }

    else {
        EnergyO3.Status = floor((energyO - 2) * 10);
    }

}

int changeMenu(HWND hwnd) {
    botButton();

    StartGameButton();

    RulesButton();

    AuthorButton();

    LevelOpponentButton();

    SpeedSovlanutButtons();

    ExitButton();

    SoundButton();

    SwitchLight();

    SwitchWatch();

    StopButton();

    TipsClick();

}

int SumСompletedFields() {
    int tempV = 0;
    for (int i = 1; i <= 100; i++) {
        if (s_Field.flag[i] == 1) {
            tempV = tempV + 1;
        }
    }
    sums_Field = tempV;
    tempV = 0;
}

void LoadImageArr(wchar_t* path[], HDC* arrayVarieble[], int sizeArray) {

      for (int i = 0; i < sizeArray; i++) {

       
        hBitmap = (HBITMAP)LoadImage(NULL, path[i], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        HDC mem = CreateCompatibleDC(hdc);
        SelectObject(mem, hBitmap);
        DeleteObject(hBitmap);
        arrayVarieble[i] = mem;
        
    }
 
}

int CreateGameField(HWND hdc) {

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 10; j++) {

            s_Field.field[i * 10 + j] = L"";
            s_Field.coordinataX[i * 10 + j] = 699 + i * 35;
            s_Field.coordinataY[i * 10 + j] = 155 + j * 34;
            s_Field.flag[i * 10 + j] = 0;
        }
    }

}


int placeClick(int* posX, int* posY, int* sizeX, int* sizeY) {
    if (mouse_x >= *posX
        && mouse_y >= *posY
        && mouse_x <= *posX + *sizeX
        && mouse_y <= *posY + *sizeY)
    return 1;
}