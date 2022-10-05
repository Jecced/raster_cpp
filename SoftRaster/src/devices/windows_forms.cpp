//
// Created by jecced on 2022/10/3.
//

#include "windows_forms.h"
#include "tchar.h"

int screenExitCode = 0;

WindowsForms::WindowsForms(int width, int height) {
    screenInit(width, height, _T("SoftRaster"));
    initFrameBuffer(width, height, this->screenBuffer);
}

WindowsForms::~WindowsForms(){
    screenClose();
}

int WindowsForms::screenInit(int w, int h, const CHAR *title) {
    WNDCLASS wc = {CS_BYTEALIGNCLIENT, (WNDPROC) screenEvents, 0, 0, 0,
                   NULL, NULL, NULL, NULL, "SCREEN3.1415926"};
    BITMAPINFO bi = {{sizeof(BITMAPINFOHEADER), w, -h, 1, 32, BI_RGB,
                      (unsigned long) w * h * 4, 0, 0, 0, 0}};
    RECT rect = {0, 0, w, h};
    int wx, wy, sx, sy;
    LPVOID ptr;
    HDC hDC;

    screenClose();

    wc.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    if (!RegisterClass(&wc)) return -1;

    screenHandle = CreateWindow(_T("SCREEN3.1415926"), title,
                                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                                0, 0, 0, 0, NULL, NULL, wc.hInstance, NULL);
    if (screenHandle == NULL) return -2;

    screenExitCode = 0;
    hDC = GetDC(screenHandle);
    screenDC = CreateCompatibleDC(hDC);
    ReleaseDC(screenHandle, hDC);

    screenHB = CreateDIBSection(screenDC, &bi, DIB_RGB_COLORS, &ptr, 0, 0);
    if (screenHB == NULL) return -3;

    screenOB = (HBITMAP) SelectObject(screenDC, screenHB);
    screenBuffer = (unsigned char *) ptr;
    width = w;
    height = h;
//    screenPitch = w * 4;

    AdjustWindowRect(&rect, GetWindowLong(screenHandle, GWL_STYLE), 0);
    wx = rect.right - rect.left;
    wy = rect.bottom - rect.top;
    sx = (GetSystemMetrics(SM_CXSCREEN) - wx) / 2;
    sy = (GetSystemMetrics(SM_CYSCREEN) - wy) / 2;
    if (sy < 0) sy = 0;
    SetWindowPos(screenHandle, NULL, sx, sy, wx, wy, (SWP_NOCOPYBITS | SWP_NOZORDER | SWP_SHOWWINDOW));
    SetForegroundWindow(screenHandle);

    ShowWindow(screenHandle, SW_NORMAL);
    screenDispatch();

//    memset(screenKeys, 0, sizeof(int) * 512);
    memset(screenBuffer, 0, w * h * 4);

    return 0;
}

LRESULT WindowsForms::screenEvents(HWND hWnd, UINT msg,
                                   WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE: screenExitCode = 1; break;
//        case WM_KEYDOWN: screen_keys[wParam & 511] = 1; break;
//        case WM_KEYUP: screen_keys[wParam & 511] = 0; break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

int WindowsForms::getHeight() {
    return height;
}

int WindowsForms::getWidth() {
    return width;
}

void WindowsForms::screenUpdate() {
    HDC hDC = GetDC(screenHandle);
    BitBlt(hDC, 0, 0, width, height, screenDC, 0, 0, SRCCOPY);
    ReleaseDC(screenHandle, hDC);
    screenDispatch();
}

int WindowsForms::screenClose() {
    if (screenDC) {
        if (screenOB) {
            SelectObject(screenDC, screenOB);
            screenOB = NULL;
        }
        DeleteDC(screenDC);
        screenDC = NULL;
    }
    if (screenHB) {
        DeleteObject(screenHB);
        screenHB = NULL;
    }
    if (screenHandle) {
        CloseWindow(screenHandle);
        screenHandle = NULL;
    }
    return 0;
}

int WindowsForms::screenDispatch() {
    MSG msg;
    while (1) {
        if (!PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) break;
        if (!GetMessage(&msg, NULL, 0, 0)) break;
        DispatchMessage(&msg);
    }

    return screenExitCode == 0;
}

void WindowsForms::initFrameBuffer(int width, int height, unsigned char *screenBuffer) {

    int need = sizeof(void*) * (height * 2 + 1024) + width * height * 8;
    char *ptr = (char*)malloc(need + 64);
    framebuffer = (unsigned int**)ptr;

    for (int i = 0, len = width * height; i < len; i++) {
        framebuffer[i] = (unsigned int *) (screenBuffer + 4 * i);
    }
}

unsigned int **WindowsForms::getFrameBuffer() {
    return framebuffer;
}

