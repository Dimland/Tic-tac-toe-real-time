#include "Tic-tac-toe real time.h";

void drawhLight(HDC* memDC) {

    if (GameMod == -1) BitBlt(*memDC, 0, 0, 1280, 1024, memBig[memBitBlack], 0, 0, SRCCOPY);
    if (GameMod != -1) BitBlt(*memDC, 0, 0, 1280, 1024, memBig[memBit3], 0, 0, SRCCOPY);
};

void drawNumberWatch(HDC* memDC) {
    int posT1SecX = 905;
    int posT1SecY = 18;
    int posyTRight = 44;
    BitBlt(*memDC, 835 - posyTRight, posT1SecY, 37, 73, memBig[memBitT0], 0, 0, SRCCOPY);

    if (minutsLeft <= 0) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT0], 0, 0, SRCCOPY); }
    if (minutsLeft == 1) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT1], 0, 0, SRCCOPY); }
    if (minutsLeft == 2) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT2], 0, 0, SRCCOPY); }
    if (minutsLeft == 3) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT3], 0, 0, SRCCOPY); }
    if (minutsLeft == 4) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT4], 0, 0, SRCCOPY); }
    if (minutsLeft == 5) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT5], 0, 0, SRCCOPY); }
    if (minutsLeft == 6) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT6], 0, 0, SRCCOPY); }
    if (minutsLeft == 7) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT7], 0, 0, SRCCOPY); }
    if (minutsLeft == 8) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT8], 0, 0, SRCCOPY); }
    if (minutsLeft == 9) { BitBlt(*memDC, 835, posT1SecY, 37, 73, memBig[memBitT9], 0, 0, SRCCOPY); }

    if (secondsLeft1 <= 0) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT0], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 1) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT1], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 2) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT2], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 3) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT3], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 4) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT4], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 5) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT5], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 6) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT6], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 7) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT7], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 8) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT8], 0, 0, SRCCOPY); }
    if (secondsLeft1 == 9) { BitBlt(*memDC, posT1SecX, posT1SecY, 37, 73, memBig[memBitT9], 0, 0, SRCCOPY); }

    if (secondsLeft2 <= 0) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT0], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 1) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT1], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 2) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT2], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 3) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT3], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 4) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT4], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 5) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT5], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 6) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT6], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 7) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT7], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 8) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT8], 0, 0, SRCCOPY); }
    if (secondsLeft2 == 9) { BitBlt(*memDC, posT1SecX + posyTRight, posT1SecY, 37, 73, memBig[memBitT9], 0, 0, SRCCOPY); }

}

void drawButton(HDC* memDC) {
    // ButtonBot
    if (StartB.Status == 1 && GameMod != -1 && botB.Status == 1) { BitBlt(*memDC, botB.posX, botB.posY, botB.sizeX, botB.sizeY, memBig[memBitBot], 0, 0, SRCCOPY); }
    if (botB.StasusModeGame == 1 && GameMod != -1) { BitBlt(*memDC, botB.posX + 10, botB.posY + 10, 28, 28, memBig[memBitX6], 0, 0, SRCCOPY); }

    // ButtonGameMod
    if (StartB.Status == 1 && GameMod != -1) { BitBlt(*memDC, StartB.posX, StartB.posY, StartB.sizeX, StartB.sizeY, memBig[memBitGameMod], 0, 0, SRCCOPY); }
    if (StartB.Status == 2 && GameMod != -1) { BitBlt(*memDC, StartB.posX, StartB.posY, StartB.sizeX, StartB.sizeY, memBig[memBitGameModV], 0, 0, SRCCOPY); }

    // ButtonRules 
    if (RulesB.Status == 0 && GameMod != -1) { BitBlt(*memDC, RulesB.posX, RulesB.posY, RulesB.sizeX, RulesB.sizeY, memBig[memBitRules0], 0, 0, SRCCOPY); }
    if (RulesB.Status == 1 && GameMod != -1) { BitBlt(*memDC, RulesB.posX, RulesB.posY, RulesB.sizeX, RulesB.sizeY, memBig[memBitRules1], 0, 0, SRCCOPY); }

    // ButtonAuthor 
    if (AuthorB.Status == 0 && GameMod != -1) { BitBlt(*memDC, AuthorB.posX, AuthorB.posY, AuthorB.sizeX, AuthorB.sizeY, memBig[memBitAuthor0], 0, 0, SRCCOPY); }
    if (AuthorB.Status == 1 && GameMod != -1) { BitBlt(*memDC, AuthorB.posX, AuthorB.posY, AuthorB.sizeX, AuthorB.sizeY, memBig[memBitAuthor1], 0, 0, SRCCOPY); }


    //opponent Level
    if (opponenLevelB.Status == 0 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, opponenLevelB.posX, opponenLevelB.posY, opponenLevelB.sizeX, opponenLevelB.sizeY, memBig[memBitOpponentLevel], 0, 0, SRCCOPY); }

    if (LeftOpB.Status == 0 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, LeftOpB.posX, LeftOpB.posY, LeftOpB.sizeX, LeftOpB.sizeY, memBig[memBitLeftOpB_0], 0, 0, SRCCOPY); }
    if (LeftOpB.Status == 1 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, LeftOpB.posX, LeftOpB.posY, LeftOpB.sizeX, LeftOpB.sizeY, memBig[memBitLeftOpB_1], 0, 0, SRCCOPY); }

    if (RightOpB.Status == 0 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, RightOpB.posX, RightOpB.posY, RightOpB.sizeX, RightOpB.sizeY, memBig[memBitRightOpB_0], 0, 0, SRCCOPY); }
    if (RightOpB.Status == 1 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, RightOpB.posX, RightOpB.posY, RightOpB.sizeX, RightOpB.sizeY, memBig[memBitRightOpB_1], 0, 0, SRCCOPY); }

    if (opponenLevelNumberB.Status == 1 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, 452, 632, 28, 64, memBig[memBitNumbO_1], 0, 0, SRCCOPY); }
    if (opponenLevelNumberB.Status == 2 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, 452, 632, 28, 64, memBig[memBitNumbO_2], 0, 0, SRCCOPY); }
    if (opponenLevelNumberB.Status == 3 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, 452, 632, 28, 64, memBig[memBitNumbO_3], 0, 0, SRCCOPY); }


    // Button Arrey Sovlanut
    if (LeftB.Status == 1 && GameMod != -1) { BitBlt(*memDC, LeftB.posX, LeftB.posY, LeftB.sizeX, LeftB.sizeY, memBig[memBitLeft], 0, 0, SRCCOPY); }
    if (RightB.Status == 1 && GameMod != -1) { BitBlt(*memDC, RightB.posX, RightB.posY, RightB.sizeX, RightB.sizeY, memBig[memBitRight], 0, 0, SRCCOPY); }

    if (TerpB.Status == 1 && GameMod != -1) { BitBlt(*memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBig[memBitTerp1], 0, 0, SRCCOPY); }
    if (TerpB.Status == 2 && GameMod != -1) { BitBlt(*memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBig[memBitTerp2], 0, 0, SRCCOPY); }
    if (TerpB.Status == 3 && GameMod != -1) { BitBlt(*memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBig[memBitTerp3], 0, 0, SRCCOPY); }
    if (TerpB.Status == 4 && GameMod != -1) { BitBlt(*memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBig[memBitTerp4], 0, 0, SRCCOPY); }
    if (TerpB.Status == 5 && GameMod != -1) { BitBlt(*memDC, TerpB.posX, TerpB.posY, TerpB.sizeX, TerpB.sizeY, memBig[memBitTerp5], 0, 0, SRCCOPY); }

    // ButtonSound
    if (SoundB.Status == 0 && GameMod != -1) { BitBlt(*memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBig[memBitSound0], 0, 0, SRCCOPY); }
    if (SoundB.Status == 1 && GameMod != -1) { BitBlt(*memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBig[memBitSound1], 0, 0, SRCCOPY); }
    if (SoundB.Status == 2 && GameMod != -1) { BitBlt(*memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBig[memBitSound2], 0, 0, SRCCOPY); }
    if (SoundB.Status == 3 && GameMod != -1) { BitBlt(*memDC, SoundB.posX, SoundB.posY, SoundB.sizeX, SoundB.sizeY, memBig[memBitSound3], 0, 0, SRCCOPY); }

    // ButtonExit
    if (ExitB.Status == 0 && GameMod != -1) { BitBlt(*memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBig[memBitExit0], 0, 0, SRCCOPY); }
    if (ExitB.Status == 1 && GameMod != -1) { BitBlt(*memDC, ExitB.posX, ExitB.posY, ExitB.sizeX, ExitB.sizeY, memBig[memBitExit1], 0, 0, SRCCOPY); }

    // ButtonStop
    if (StopB.Status == 0 && counter_start == -100)  BitBlt(*memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBig[memBitStop0], 0, 0, SRCCOPY);
    if (StopB.Status == 1 && counter_start == -100) BitBlt(*memDC, StopB.posX, StopB.posY, StopB.sizeX, StopB.sizeY, memBig[memBitStop1], 0, 0, SRCCOPY);

};

void drawRightPageBackground(HDC* memDC) {

    if (GameMod == 4 || counter_start == -100) { BitBlt(*memDC, Field.posX, Field.posY, Field.sizeX, Field.sizeY, memBig[memBitPole], 0, 0, SRCCOPY); } // drawField
    if (GameMod == 5) { BitBlt(*memDC, RulesI.posX, RulesI.posY, RulesI.sizeX, RulesI.sizeY, memBig[memBitRuls], 0, 0, SRCCOPY); }
    if (GameMod == 6) { BitBlt(*memDC, AuthorI.posX, AuthorI.posY, AuthorI.sizeX, AuthorI.sizeY, memBig[memBitAuthorPeople], 0, 0, SRCCOPY); }

};

void drawTips(HDC* memDC) {
    if (GameMod != -1) { BitBlt(*memDC, podskazkaB.posX, podskazkaB.posY, podskazkaB.sizeX, podskazkaB.sizeY, memBig[memBitPodskazka], 0, 0, SRCCOPY); }
};

void drawElementsXO(HDC* memDC) {
    for (int i = 1; i <= 100; i++) {
        if (s_Field.field[i] == pO && GameMod != -1 && (GameMod == 2 || GameMod == 4)) {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO6], 0, 0, SRCCOPY);

        }
        if (s_Field.field[i] == L"o5") {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO5], 0, 0, SRCAND); s_Field.field[i] = pO; s_Field.flag[i] = 1; SumÑompletedFields();
            compareArray(pO, &countLine1_O);
        }
        if (s_Field.field[i] == L"o4") {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO4], 0, 0, SRCAND); s_Field.field[i] = L"o5"; tik_tak = 10;
        }
        if (s_Field.field[i] == L"o3") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO3], 0, 0, SRCAND); s_Field.field[i] = L"o4"; }
        if (s_Field.field[i] == L"o2") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO2], 0, 0, SRCAND); s_Field.field[i] = L"o3"; }
        if (s_Field.field[i] == L"o1") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitO1], 0, 0, SRCAND); s_Field.field[i] = L"o2";    if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC); }

        if (s_Field.field[i] == pX && GameMod != -1 && (GameMod == 2 || GameMod == 4)) {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX6], 0, 0, SRCCOPY);

        }
        if (s_Field.field[i] == L"x5") {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX5], 0, 0, SRCAND); s_Field.field[i] = pX; s_Field.flag[i] = 1; SumÑompletedFields();
            compareArray(pX, &countLine1_X);
        }
        if (s_Field.field[i] == L"x4") {
            BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX4], 0, 0, SRCAND); s_Field.field[i] = L"x5"; tik_tak = 10;
        }
        if (s_Field.field[i] == L"x3") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX3], 0, 0, SRCAND); s_Field.field[i] = L"x4"; }
        if (s_Field.field[i] == L"x2") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX2], 0, 0, SRCAND); s_Field.field[i] = L"x3"; }
        if (s_Field.field[i] == L"x1") { BitBlt(*memDC, s_Field.coordinataX[i], s_Field.coordinataY[i], s_Field.sizeX_small, s_Field.sizeY_small, memBig[memBitX1], 0, 0, SRCAND); s_Field.field[i] = L"x2";    if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC); }

    }
}

void drawRedPancel(HDC* memDC) {
    if (counter_start == -100 && botB.StasusModeGame == 1) {
        { BitBlt(*memDC, s_Field.coordinataX[posPancel] + 10, s_Field.coordinataY[posPancel] - 2, 9, 23, memBig[memBitPancel], 0, 0, SRCCOPY); }
    }
};

void drawEnergy(HDC* memDC) {

    int addENX = 698;
    int addENY = 667;
    int addENNX = 35;
    int addENO = 909;
    int addENNO = 35;

    // energy x1 
    if (counter_start == -100 && energyX1 <= 0) { BitBlt(*memDC, 698, 667, 30, 64, memBig[memBitEnergyX0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 1) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 2) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 3) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 4) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 5) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 6) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 7) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 8) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 9) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX1 == 10) { BitBlt(*memDC, addENX, addENY, 30, 64, memBig[memBitEnergyX10], 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyX2 <= 0) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 1) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 2) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 3) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 4) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 5) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 6) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 7) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 8) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 9) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX2 == 10) { BitBlt(*memDC, addENX + addENNX, addENY, 30, 64, memBig[memBitEnergyX10], 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyX3 <= 0) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 1) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 2) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 3) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 4) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 5) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 6) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 7) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 8) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 9) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyX3 == 10) { BitBlt(*memDC, addENX + addENNX * 2, addENY, 30, 64, memBig[memBitEnergyX10], 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO3 <= 0) { BitBlt(*memDC, 909, 667, 30, 64, memBig[memBitEnergyO0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 1) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 2) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 3) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 4) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 5) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 6) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 7) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 8) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 9) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO3 == 10) { BitBlt(*memDC, addENO, addENY, 30, 64, memBig[memBitEnergyO10], 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO2 <= 0) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 1) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 2) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 3) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 4) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 5) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 6) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 7) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 8) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 9) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO2 == 10) { BitBlt(*memDC, addENO + addENNO, addENY, 30, 64, memBig[memBitEnergyO10], 0, 0, SRCCOPY); }

    if (counter_start == -100 && energyO1 <= 0) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO0], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 1) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO1], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 2) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO2], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 3) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO3], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 4) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO4], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 5) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO5], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 6) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO6], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 7) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO7], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 8) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO8], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 9) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO9], 0, 0, SRCCOPY); }
    if (counter_start == -100 && energyO1 == 10) { BitBlt(*memDC, addENO + addENNO * 2, addENY, 30, 64, memBig[memBitEnergyO10], 0, 0, SRCCOPY); }

};

void drawScore(HDC* memDC) {

    int posNumber1_X = 767;
    int addPosNumber = 35;

    if (numberX_1 == 0 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_0], 0, 0, SRCCOPY); }
    if (numberX_1 == 1 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_1], 0, 0, SRCCOPY); }
    if (numberX_1 == 2 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_2], 0, 0, SRCCOPY); }
    if (numberX_1 == 3 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_3], 0, 0, SRCCOPY); }
    if (numberX_1 == 4 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_4], 0, 0, SRCCOPY); }
    if (numberX_1 == 5 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_5], 0, 0, SRCCOPY); }
    if (numberX_1 == 6 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_6], 0, 0, SRCCOPY); }
    if (numberX_1 == 7 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_7], 0, 0, SRCCOPY); }
    if (numberX_1 == 8 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_8], 0, 0, SRCCOPY); }
    if (numberX_1 == 9 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X, 598, 28, 64, memBig[memBitNumbX_9], 0, 0, SRCCOPY); }

    if (numberX_2 == 0 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_0], 0, 0, SRCCOPY); }
    if (numberX_2 == 1 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_1], 0, 0, SRCCOPY); }
    if (numberX_2 == 2 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_2], 0, 0, SRCCOPY); }
    if (numberX_2 == 3 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_3], 0, 0, SRCCOPY); }
    if (numberX_2 == 4 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_4], 0, 0, SRCCOPY); }
    if (numberX_2 == 5 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_5], 0, 0, SRCCOPY); }
    if (numberX_2 == 6 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_6], 0, 0, SRCCOPY); }
    if (numberX_2 == 7 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_7], 0, 0, SRCCOPY); }
    if (numberX_2 == 8 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_8], 0, 0, SRCCOPY); }
    if (numberX_2 == 9 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_X - addPosNumber, 598, 28, 64, memBig[memBitNumbX_9], 0, 0, SRCCOPY); }

    int posNumber1_O = 980;

    if (numberO_1 == 0 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_0], 0, 0, SRCCOPY); }
    if (numberO_1 == 1 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_1], 0, 0, SRCCOPY); }
    if (numberO_1 == 2 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_2], 0, 0, SRCCOPY); }
    if (numberO_1 == 3 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_3], 0, 0, SRCCOPY); }
    if (numberO_1 == 4 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_4], 0, 0, SRCCOPY); }
    if (numberO_1 == 5 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_5], 0, 0, SRCCOPY); }
    if (numberO_1 == 6 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_6], 0, 0, SRCCOPY); }
    if (numberO_1 == 7 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_7], 0, 0, SRCCOPY); }
    if (numberO_1 == 8 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_8], 0, 0, SRCCOPY); }
    if (numberO_1 == 9 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O, 598, 28, 64, memBig[memBitNumbO_9], 0, 0, SRCCOPY); }

    if (numberO_2 == 0 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_0], 0, 0, SRCCOPY); }
    if (numberO_2 == 1 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_1], 0, 0, SRCCOPY); }
    if (numberO_2 == 2 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_2], 0, 0, SRCCOPY); }
    if (numberO_2 == 3 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_3], 0, 0, SRCCOPY); }
    if (numberO_2 == 4 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_4], 0, 0, SRCCOPY); }
    if (numberO_2 == 5 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_5], 0, 0, SRCCOPY); }
    if (numberO_2 == 6 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_6], 0, 0, SRCCOPY); }
    if (numberO_2 == 7 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_7], 0, 0, SRCCOPY); }
    if (numberO_2 == 8 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_8], 0, 0, SRCCOPY); }
    if (numberO_2 == 9 && (counter_start == -100 || GameMod == 4)) { BitBlt(*memDC, posNumber1_O - addPosNumber, 598, 28, 64, memBig[memBitNumbO_9], 0, 0, SRCCOPY); }
}

void drawWin(HDC* memDC) {
    // Victory inscription
    if (GameMod == 4 && countLine1_X > countLine1_O) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitX_Win], 0, 0, SRCCOPY);
    }
    if (GameMod == 4 && countLine1_X > countLine1_O) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitO_Win], 0, 0, SRCCOPY);
    }

    // dance men red
    if (GameMod == 4 && countLine1_O > countLine1_X) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitO_Win], 0, 0, SRCCOPY);
        if (tempm <= 4) {
            BitBlt(*memDC, 730, 801, 318, 69, memBig[memBitO_WinMensPO], 0, 0, SRCCOPY);
        }
        else {
            BitBlt(*memDC, 730, 801, 318, 69, memBig[memBitO_WinMensLO], 0, 0, SRCCOPY);
        }
        if (tempm == 9) {
            tempm = 0;
        }
        tempm = tempm + 1;
    }


    // dance men blue
    if (GameMod == 4 && countLine1_X > countLine1_O) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitX_Win], 0, 0, SRCCOPY);
        if (tempm <= 4) {
            BitBlt(*memDC, 730, 801, 318, 69, memBig[memBitO_WinMensPX], 0, 0, SRCCOPY);
        }
        else {
            BitBlt(*memDC, 730, 801, 318, 69, memBig[memBitO_WinMensLX], 0, 0, SRCCOPY);
        }
        if (tempm == 9) {
            tempm = 0;
        }
        tempm = tempm + 1;
    }
};