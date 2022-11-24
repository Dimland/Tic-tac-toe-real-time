#include "Tic-tac-toe real time.h";

void drawhLight(HDC* memDC) {

    if (GameMod == -1) BitBlt(*memDC, 0, 0, 1280, 1024, memBig[memBitBlack], 0, 0, SRCCOPY);
    if (GameMod != -1) BitBlt(*memDC, 0, 0, 1280, 1024, memBig[memBit3], 0, 0, SRCCOPY);
};

void drawNumberWatch(HDC* memDC) {
 
    BitBlt(*memDC, MinutL.posX, MinutL.posY, MinutL.sizeX, MinutL.sizeY, MemWatchNumber.array[0], 0, 0, SRCCOPY);

    for (int i = 0; i < 10; i++) {
        if(MinutR.Status == i){BitBlt(*memDC, MinutR.posX, MinutR.posY, MinutR.sizeX, MinutR.sizeY, MemWatchNumber.array[i], 0, 0, SRCCOPY);}
    }
   
    for (int i = 0; i < 10; i++) {
        if (SecondL.Status == i) { BitBlt(*memDC, SecondL.posX, SecondL.posY, SecondL.sizeX, SecondL.sizeY, MemWatchNumber.array[i], 0, 0, SRCCOPY); }
    }
    
    for (int i = 0; i < 10; i++) {
        if (SecondR.Status == i) { BitBlt(*memDC, SecondR.posX, SecondR.posY, SecondR.sizeX, SecondR.sizeY, MemWatchNumber.array[i], 0, 0, SRCCOPY); }
    }
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

    if (opponenLevelNumberB.Status == 1 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, opponenLevelNumberB.posX, opponenLevelNumberB.posY, opponenLevelNumberB.sizeX, opponenLevelNumberB.sizeY, MemONumber.array[1], 0, 0, SRCCOPY); }
    if (opponenLevelNumberB.Status == 2 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, opponenLevelNumberB.posX, opponenLevelNumberB.posY, opponenLevelNumberB.sizeX, opponenLevelNumberB.sizeY, MemONumber.array[2], 0, 0, SRCCOPY); }
    if (opponenLevelNumberB.Status == 3 && GameMod != -1 && botB.StasusModeGame == 0) { BitBlt(*memDC, opponenLevelNumberB.posX, opponenLevelNumberB.posY, opponenLevelNumberB.sizeX, opponenLevelNumberB.sizeY, MemONumber.array[3], 0, 0, SRCCOPY); }


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
            sumPoint(pO, &sumPoint_O);
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
            sumPoint(pX, &sumPoint_X);
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

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyX1.Status <= i) 
        { BitBlt(*memDC, EnergyX1.posX, EnergyX1.posY, EnergyX1.sizeX, EnergyX1.sizeY, MemEnergyX.array[i], 0, 0, SRCCOPY); }
    }

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyX2.Status <= i) 
        { BitBlt(*memDC, EnergyX2.posX, EnergyX2.posY, EnergyX2.sizeX, EnergyX2.sizeY, MemEnergyX.array[i], 0, 0, SRCCOPY); }
    }

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyX3.Status <= i) 
        { BitBlt(*memDC, EnergyX3.posX, EnergyX3.posY, EnergyX3.sizeX, EnergyX3.sizeY, MemEnergyX.array[i], 0, 0, SRCCOPY); }
    }

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyO1.Status <= i) 
        { BitBlt(*memDC, EnergyO1.posX, EnergyO1.posY, EnergyO1.sizeX, EnergyO1.sizeY, MemEnergyO.array[i], 0, 0, SRCCOPY); }
    }

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyO2.Status <= i) 
        { BitBlt(*memDC, EnergyO2.posX, EnergyO2.posY, EnergyO2.sizeX, EnergyO2.sizeY, MemEnergyO.array[i], 0, 0, SRCCOPY); }
    }

    for (int i = 10; i > -1; i--) {
        if (counter_start == -100 && EnergyO3.Status <= i) 
        { BitBlt(*memDC, EnergyO3.posX, EnergyO3.posY, EnergyO3.sizeX, EnergyO3.sizeY, MemEnergyO.array[i], 0, 0, SRCCOPY); }
    }


};

void drawScore(HDC* memDC) {

    for (int i = 0; i < 10; i++) {
        if (NumberX1.Status == i && (counter_start == -100 || GameMod == 4))
        {
            BitBlt(*memDC, NumberX1.posX, NumberX1.posY, NumberX1.sizeX, NumberX1.sizeY, MemXNumber.array[i], 0, 0, SRCCOPY);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (NumberX2.Status == i && (counter_start == -100 || GameMod == 4)) 
        {
            BitBlt(*memDC, NumberX2.posX, NumberX2.posY, NumberX2.sizeX, NumberX2.sizeY, MemXNumber.array[i], 0, 0, SRCCOPY);
        }
    }


  

    for (int i = 0; i < 10; i++) 
    {
        if (NumberO1.Status == i && (counter_start == -100 || GameMod == 4)) 
        { 
            BitBlt(*memDC, NumberO1.posX, NumberO1.posY, NumberO1.sizeX, NumberO1.sizeY, MemONumber.array[i], 0, 0, SRCCOPY);
        }
    }

   
    for (int i = 0; i < 10; i++) 
    {
        if (NumberO2.Status == i && (counter_start == -100 || GameMod == 4)) 
        { 
            BitBlt(*memDC, NumberO2.posX, NumberO2.posY, NumberO2.sizeX, NumberO2.sizeY, MemONumber.array[i], 0, 0, SRCCOPY);
        }
    }
}

void drawWin(HDC* memDC) {
    // Victory inscription
    if (GameMod == 4 && sumPoint_X > sumPoint_O) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitX_Win], 0, 0, SRCCOPY);
    }
    if (GameMod == 4 && sumPoint_X > sumPoint_O) {
        BitBlt(*memDC, 686, 541, 328, 59, memBig[memBitO_Win], 0, 0, SRCCOPY);
    }

    // dance men red
    if (GameMod == 4 && sumPoint_O > sumPoint_X) {
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
    if (GameMod == 4 && sumPoint_X > sumPoint_O) {
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