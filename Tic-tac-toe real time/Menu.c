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
        && mouse_x >= StartB.posX
        && mouse_y >= StartB.posY
        && mouse_x <= StartB.posX + StartB.sizeX
        && mouse_y <= StartB.posY + StartB.sizeY
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
        countLine1_X = 0;
        countLine1_O = 0;
        ForTips = 1;
        posPancel = 45;
    }

    if (mouse_x >= StartB.posX
        && mouse_y >= StartB.posY
        && mouse_x <= StartB.posX + StartB.sizeX
        && mouse_y <= StartB.posY + StartB.sizeY
        && (GameMod != 2) && GameMod >= 0) {
        StartB.Status = 2;

    }
    else { StartB.Status = 1; }

};

void RulesButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= RulesB.posX
        && mouse_y >= RulesB.posY
        && mouse_x <= RulesB.posX + RulesB.sizeX
        && mouse_y <= RulesB.posY + RulesB.sizeY
        && GameMod >= 0 && GameMod != 2 && GameMod != 5)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1)  PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GameMod = 5;

    }
    if ((mouse_x >= RulesB.posX
        && mouse_y >= RulesB.posY
        && mouse_x <= RulesB.posX + RulesB.sizeX
        && mouse_y <= RulesB.posY + RulesB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 6)) || GameMod == 5)
    {
        RulesB.Status = 1;

    }
    else { RulesB.Status = 0; }

};

void AuthorButton() {
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= AuthorB.posX
        && mouse_y >= AuthorB.posY
        && mouse_x <= AuthorB.posX + AuthorB.sizeX
        && mouse_y <= AuthorB.posY + AuthorB.sizeY
        && GameMod >= 0 && GameMod != 2 && GameMod != 6)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\perelist.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GameMod = 6;
    }

    if ((mouse_x >= AuthorB.posX
        && mouse_y >= AuthorB.posY
        && mouse_x <= AuthorB.posX + AuthorB.sizeX
        && mouse_y <= AuthorB.posY + AuthorB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5)) || GameMod == 6)
    {
        AuthorB.Status = 1;
    }
    else { AuthorB.Status = 0; }
};

void LevelOpponentButton() {
    // Button Level opponent Left
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= LeftOpB.posX
        && mouse_y >= LeftOpB.posY
        && mouse_x <= LeftOpB.posX + LeftOpB.sizeX
        && mouse_y <= LeftOpB.posY + LeftOpB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status > 1)
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        speedBot = speedBot - 0.6;
        opponenLevelNumberB.Status = opponenLevelNumberB.Status - 1;
        Sleep(400);
    }


    if (mouse_x >= LeftOpB.posX
        && mouse_y >= LeftOpB.posY
        && mouse_x <= LeftOpB.posX + LeftOpB.sizeX
        && mouse_y <= LeftOpB.posY + LeftOpB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status > 1)
    {

        LeftOpB.Status = 1;

    }
    else { LeftOpB.Status = 0; }


    // Button Level opponent Right
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= RightOpB.posX
        && mouse_y >= RightOpB.posY
        && mouse_x <= RightOpB.posX + RightB.sizeX
        && mouse_y <= RightOpB.posY + RightB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status < 3) {

        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);


        speedBot = speedBot + 0.6;
        opponenLevelNumberB.Status = opponenLevelNumberB.Status + 1;
        Sleep(300);
    }

    if (mouse_x >= RightOpB.posX
        && mouse_y >= RightOpB.posY
        && mouse_x <= RightOpB.posX + RightOpB.sizeX
        && mouse_y <= RightOpB.posY + RightOpB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && opponenLevelNumberB.Status < 3)
    {
        RightOpB.Status = 1;

    }
    else { RightOpB.Status = 0; }

};

void SpeedSovlanutButtons() {

    // button Arrey Left
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= LeftB.posX
        && mouse_y >= LeftB.posY
        && mouse_x <= LeftB.posX + LeftB.sizeX
        && mouse_y <= LeftB.posY + LeftB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed > 0.06 && TerpB.Status > 1)
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
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed > 0.06 && TerpB.Status > 1)
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
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed != 0.30 && TerpB.Status != 5) {

        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\ris.wav"), NULL, SND_FILENAME | SND_ASYNC);


        speed = speed + 0.06;
        TerpB.Status = TerpB.Status + 1;
        Sleep(300);
    }

    if (mouse_x >= RightB.posX
        && mouse_y >= RightB.posY
        && mouse_x <= RightB.posX + RightB.sizeX
        && mouse_y <= RightB.posY + RightB.sizeY
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && speed != 0.30 && TerpB.Status != 5)
    {
        RightB.Status = 1;

    }
    else { RightB.Status = 0; }

};

void ExitButton() {
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
};

void SoundButton() {
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
        && mouse_x >= 90
        && mouse_y >= 26
        && mouse_x <= 151
        && mouse_y <= 90
        && (GameMod == -1 || GameMod == 5 || GameMod == 6) && OnOffLeight == 0
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        GameMod = -2;
        OnOffLeight = 1;
    }

    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 90
        && mouse_y >= 26
        && mouse_x <= 151
        && mouse_y <= 90
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6) && OnOffLeight == 1
        )
    {
        if (SoundB.Status == 0 || SoundB.Status == 1) PlaySoundW(TEXT(".\\sounds\\onLamp.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(350);
        GameMod = -1;
        OnOffLeight = 0;
    }

};

void SwitchWatch() {
    if (GetKeyState(VK_LBUTTON) < 0
        && mouse_x >= 770
        && mouse_y >= 10
        && mouse_x <= 1000
        && mouse_y <= 100
        && (GameMod == 0 || GameMod == 4 || GameMod == 5 || GameMod == 6))
            {
        changeLeftClic[0] = 1;
            }

    if (GetKeyState(VK_LBUTTON) >= 0
        && mouse_x >= 770
        && mouse_y >= 10
        && mouse_x <= 1000
        && mouse_y <= 100
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
        && mouse_x >= StopB.posX
        && mouse_y >= StopB.posY
        && mouse_x <= StopB.posX + StopB.sizeX
        && mouse_y <= StopB.posY + StopB.sizeY
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

    if (mouse_x >= StopB.posX
        && mouse_y >= StopB.posY
        && mouse_x <= StopB.posX + StopB.sizeX
        && mouse_y <= StopB.posY + StopB.sizeY
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
        && mouse_x >= podskazkaB.posX
        && mouse_y >= podskazkaB.posY
        && mouse_x <= podskazkaB.posX + podskazkaB.sizeX
        && mouse_y <= podskazkaB.posY + podskazkaB.sizeY
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
            && mouse_x >= podskazkaB.posX
            && mouse_y >= podskazkaB.posY
            && mouse_x <= podskazkaB.posX + podskazkaB.sizeX
            && mouse_y <= podskazkaB.posY + podskazkaB.sizeY
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