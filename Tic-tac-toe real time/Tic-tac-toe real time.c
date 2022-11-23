#include "Tic-tac-toe real time.h"

LRESULT WINAPI WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow )
{  
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
    addBeforeStartedvalue();
    MSG  msg;
    WNDCLASSEXW wc = { 0 };
    wc.lpszClassName = L"HHHH";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(NULL_BRUSH);
    wc.lpfnWndProc = WndProc;
    wc.hIcon = LoadIcon(hInstance, IDI_ICON2);     // class icon
    wc.hIconSm = LoadIcon(hInstance, IDI_ICON2);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));

    LPPOINT pPnt;
    pPnt = malloc(sizeof(*pPnt));
    LPRECT rctt; // указатель на размер экрана
    rctt = malloc(sizeof(*pPnt));

    SetCursor(LoadCursorFromFile(TEXT(".\\image\\pen1.cur")));

    RegisterClassW(&wc);
    hwnd = CreateWindow(wc.lpszClassName, L"TIK-TAK SOVLANUT",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_EX_TOPMOST,
        0, 0, 1280, 1024, 0, 0, hInstance, 0);

    SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 1280, 1024, SWP_SHOWWINDOW);
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    changeDisplay();

    HDC hdc = GetDC(hwnd);

    while (1) {
        if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) { // check the messages queue
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            drawAll(hdc);
            createTimer(hdc);
            GetCursorPos(pPnt);
            ScreenToClient(hwnd, pPnt);
            mouse_x = pPnt[0].x;
            mouse_y = pPnt[0].y;
            MouseInput(hwnd);
            convertPointInCoolO(hwnd);
            convertWatch(hwnd);
            addEnergy(hwnd);
            changeMenu(hwnd);
            SetCursor(LoadCursorFromFile(TEXT(".\\image\\pen1.cur")));
           if (botB.StasusModeGame ==1) KeyboardInput(hwnd);
           else {BotMoves(hwnd); };
            Sleep(50);
        }
    }
       return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_SIZE:
        GetClientRect(hwnd, &rct); // размер экрана
    case WM_CREATE:
        PlaySoundW(TEXT(".\\sounds\\startSong.wav"), NULL, SND_FILENAME | SND_ASYNC);
        LoadImageDimaArr(path);
          if (hBitmap == NULL) {
        MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
        }
        ReleaseDC(hwnd, hdc);

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rct);
        drawAll(hdc);
         EndPaint(hdc, &ps);
        return 0;
    case WM_TIMER:

        if (counter_start != -100 && (GameMod == 2)) counter_start = counter_start - 1;
        if (counter_start == 0) {
            KillTimer(hwnd, ID_TIMER_START);
            counter_start = -100;
        }
        if (GameMod == 4) {
            SetTimer(hwnd, ID_TIMER_BEFORE_START, 100, NULL);
            KillTimer(hwnd, ID_TIMER_energy1);
            energyX = 2;
            energyO = 2;
            ForTips = 1;
        }
         break;
    case WM_DESTROY:
        DeleteObject(hBitmap);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}



