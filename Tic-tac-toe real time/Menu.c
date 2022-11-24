#include "Tic-tac-toe real time.h";

void botButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= botB.posX
        && mouse_y >= botB.posY
        && mouse_x <= botB.posX + botB.sizeX
        && mouse_y <= botB.posY + botB.sizeY
        && GameMod >= 0 && GameMod != 2)
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
        && (GameMod == 0 || GameMod == 4 || GameMod == 6 || GameMod == 5))
    {
        botB.Status = 1;
    }
    else { botB.Status = 0; }
};

void StartGameButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&StartB.posX, &StartB.posY, &StartB.sizeX, &StartB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6))
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GameMod = 2;
        SetTimer(hwnd, ID_TIMER_START, 1000, NULL);
        KillTimer(hwnd, ID_TIMER_BEFORE_START);
        CreateGameField(hdc);
        counter_start = 1;
        energyX = 2;
        energyO = 2;
        gameDuration = gameDurationBuf;
        sumPoint_X = sumPoint_O = 0;
        NumberO2.Status = NumberX2.Status = 0;
        ForTips = 1;
        posPancel = 45;
    }

    if (placeClick(&StartB.posX, &StartB.posY, &StartB.sizeX, &StartB.sizeY) == 1
        && (GameMod != 2) && GameMod >= 0) {
        StartB.Status = 2;

    }
    else { StartB.Status = 1; }

};

void RulesButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&RulesB.posX,&RulesB.posY,&RulesB.sizeX, &RulesB.sizeY) == 1
        && GameMod >= 0 && GameMod != 2 && GameMod != 5)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GameMod = 5;

    }
    if ((placeClick(&RulesB.posX, &RulesB.posY, &RulesB.sizeX, &RulesB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 6)) || GameMod == 5)
    {
        RulesB.Status = 1;
    }
    else { RulesB.Status = 0; }

};

void AuthorButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&AuthorB.posX, &AuthorB.posY, &AuthorB.sizeX, &AuthorB.sizeY) == 1
        && GameMod >= 0 && GameMod != 2 && GameMod != 6)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GameMod = 6;
    }

    if ((placeClick(&AuthorB.posX, &AuthorB.posY, &AuthorB.sizeX, &AuthorB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5)) || GameMod == 6)
    {
        AuthorB.Status = 1;
    }
    else { AuthorB.Status = 0; }
};

void LevelOpponentButton() {
    // Button Level opponent Left
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&LeftOpB.posX, &LeftOpB.posY, &LeftOpB.sizeX, &LeftOpB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status > 1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        speedBot = speedBot - 0.6;
        opponenLevelNumberB.Status = opponenLevelNumberB.Status - 1;
        Sleep(400);
    }


    if (placeClick(&LeftOpB.posX, &LeftOpB.posY, &LeftOpB.sizeX, &LeftOpB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status > 1)
    {

        LeftOpB.Status = 1;

    }
    else { LeftOpB.Status = 0; }


    // Button Level opponent Right
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&RightOpB.posX, &RightOpB.posY, &RightOpB.sizeX, &RightOpB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status < 3) {

        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);


        speedBot = speedBot + 0.6;
        opponenLevelNumberB.Status = opponenLevelNumberB.Status + 1;
        Sleep(300);
    }

    if (placeClick(&RightOpB.posX, &RightOpB.posY, &RightOpB.sizeX, &RightOpB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status < 3)
    {
        RightOpB.Status = 1;

    }
    else { RightOpB.Status = 0; }

};

void SpeedSovlanutButtons() {

    // button Arrey Left
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&LeftB.posX, &LeftB.posY, &LeftB.sizeX, &LeftB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed > 0.06 && TerpB.Status > 1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        speed = speed - 0.06;
        TerpB.Status = TerpB.Status - 1;
        Sleep(400);
    }
        if (placeClick(&LeftB.posX, &LeftB.posY, &LeftB.sizeX, &LeftB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed > 0.06 && TerpB.Status > 1)
    {
        LeftB.Status = 1;

    }
    else { LeftB.Status = 0; }

    // button Arrey Right
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&RightB.posX, &RightB.posY, &RightB.sizeX, &RightB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed != 0.30 && TerpB.Status != 5) {

        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);


        speed = speed + 0.06;
        TerpB.Status = TerpB.Status + 1;
        Sleep(300);
    }

    if (placeClick(&RightB.posX, &RightB.posY, &RightB.sizeX, &RightB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed != 0.30 && TerpB.Status != 5)
    {
        RightB.Status = 1;

    }
    else { RightB.Status = 0; }

};

void ExitButton() {
    // button Exit
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&ExitB.posX, &ExitB.posY, &ExitB.sizeX, &ExitB.sizeY) == 1
         )
    {
        PostQuitMessage(0);
    }

    if (placeClick(&ExitB.posX, &ExitB.posY, &ExitB.sizeX, &ExitB.sizeY) == 1
        ) {
        ExitB.Status = 1;
    }
    else { ExitB.Status = 0; }
};

void SoundButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&SoundB.posX, &SoundB.posY, &SoundB.sizeX, &SoundB.sizeY) == 1
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

    if (placeClick(&SoundB.posX, &SoundB.posY, &SoundB.sizeX, &SoundB.sizeY) == 1
        )
    {
        if (SoundB.Status == 0)
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
};

void SwitchLight() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&LightB.posX, &LightB.posY, &LightB.sizeX, &LightB.sizeY) == 1
        && (GameMod == -1 || GameMod == 5 || GameMod == 6) && LightB.Status == 0
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        GameMod = -2;
        LightB.Status = 1;
    }

    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&LightB.posX, &LightB.posY, &LightB.sizeX, &LightB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && LightB.Status == 1
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        GameMod = -1;
        LightB.Status = 0;
    }

};

void SwitchWatch() {
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&WatchB.posX, &WatchB.posY, &WatchB.sizeX, &WatchB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6))
            {
        changeLeftClic[0] = 1;
            }

    if (GetKeyState(VK_LBUTTON) >= 0
        && placeClick(&WatchB.posX, &WatchB.posY, &WatchB.sizeX, &WatchB.sizeY) == 1
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && changeLeftClic[0] == 1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\zavod.wav"), NULL, SND_FILENAME | SND_ASYNC);
        changeLeftClic[0] = 0;

        if (gameDurationBuf == 540) {
            gameDurationBuf = 60;
        }
        else { gameDurationBuf = gameDurationBuf + 30; }

        gameDuration = gameDurationBuf;
    }
};

void StopButton() {
    // Button Stop
    if (GetKeyState(VK_LBUTTON) < 0
        && placeClick(&StopB.posX, &StopB.posY, &StopB.sizeX, &StopB.sizeY) == 1
        && (counter_start == -100)
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\otriv.wav"), NULL, SND_FILENAME | SND_ASYNC);
        /*CreateGameField(hwnd);*/
        GameMod = 0;
        counter_start = 1;
        energyX = 2;
        energyO = 2;
        sums_Field = 0;
        gameDuration = gameDurationBuf;
    }

    if (placeClick(&StopB.posX, &StopB.posY, &StopB.sizeX, &StopB.sizeY) == 1
        && (counter_start == -100))
    {
        StopB.Status = 1;

    }
    else { StopB.Status = 0; }
};

void TipsClick() {

    if (ForTips == 1) {
        if (podskazkaB.Status == 0 && podskazkaB.posX > 1080) {

            podskazkaB.posX = podskazkaB.posX - 5;
        }
        if (podskazkaB.Status == 1 && podskazkaB.posX < 1260) {

            podskazkaB.posX = podskazkaB.posX + 5;
        }
    }

    if (GetKeyState(VK_LBUTTON) < 0

        && placeClick(&podskazkaB.posX, &podskazkaB.posY, &podskazkaB.sizeX, &podskazkaB.sizeY) == 1
        && podskazkaB.Status == 1 && ForTips == 1)
    {
        podskazkaB.Status = 0;
        Sleep(200);
        if (podskazkaB.posX > 1080) {

            podskazkaB.posX = podskazkaB.posX - 5;
        }
    }
    else {

        if (GetKeyState(VK_LBUTTON) < 0
            && placeClick(&podskazkaB.posX, &podskazkaB.posY, &podskazkaB.sizeX, &podskazkaB.sizeY) == 1
            && podskazkaB.Status == 0 && ForTips == 1)
        {
            podskazkaB.Status = 1;
            Sleep(200);
            if (counter_start == -100 && podskazkaB.posX > 1260) {

                podskazkaB.posX = podskazkaB.posX + 5;
            }
        }
    }
};