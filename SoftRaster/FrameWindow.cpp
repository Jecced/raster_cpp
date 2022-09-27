//
// Created by root on 2022/9/27.
//

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include "FrameWindow.h"

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int FrameWidth;
int FrameHeight;

FrameWindow::FrameWindow(int w, int h) {
    width = w;
    height = h;
}

FrameWindow::~FrameWindow() {
    std::cout<<"~FrameWindow" <<std::endl;
}

int
FrameWindow::run(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

    FrameWidth = width;
    FrameHeight = height;

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("test");
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex)) {
        MessageBox(NULL,
                   _T("Call to RegisterClassEx failed!"),
                   _T("Windows Desktop Guided Tour"),
                   NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            _T("test"),
            _T("Soft Raster"),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            FrameWidth, FrameHeight,
            NULL, NULL,
            hInstance, NULL
    );

    if (!hWnd) {
        MessageBox(NULL,
                   _T("Call to CreateWindow failed!"),
                   _T("Windows Desktop Guided Tour"),
                   NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows desktop!");

    //双缓冲绘图
    static BITMAPINFO s_bitmapInfo;
    static HDC s_hdcBackbuffer;            //后缓冲设备句柄
    static HBITMAP s_hBitmap;
    static HBITMAP s_hOldBitmap;
    static void *s_pData;

    switch (message) {

        case WM_CREATE: {
            //初始化设备无关位图header
            BITMAPINFOHEADER bmphdr = {0};
            bmphdr.biSize = sizeof(BITMAPINFOHEADER);
            bmphdr.biWidth = FrameWidth;
            bmphdr.biHeight = -FrameHeight;
            bmphdr.biPlanes = 1;
            bmphdr.biBitCount = 32;
            bmphdr.biSizeImage = FrameWidth * FrameHeight * 4;
            //创建后缓冲区
            //先创建一个内存dc
            s_hdcBackbuffer = CreateCompatibleDC(nullptr);
            //获得前置缓冲区dc
            HDC hdc = GetDC(hWnd);
            if (!(s_hBitmap = CreateDIBSection(nullptr, (PBITMAPINFO) &bmphdr, DIB_RGB_COLORS,
//                                               reinterpret_cast<void **>(&g_pBoxDemo->GetDevice()->GetFrameBuffer()),
                                               nullptr,
                                               nullptr, 0))) {
                MessageBox(nullptr, "create dib section failed!", "error", MB_OK);
                return 0;
            }
            //将bitmap装入内存dc
            s_hOldBitmap = (HBITMAP) SelectObject(s_hdcBackbuffer, s_hBitmap);
            //释放dc
            ReleaseDC(hWnd, hdc);
            break;
        }
        case WM_PAINT: {
            hdc = BeginPaint(hWnd, &ps);
            //把backbuffer内容传到frontbuffer
            BitBlt(ps.hdc, 0, 0, FrameWidth, FrameHeight, s_hdcBackbuffer, 0, 0, SRCCOPY);
            EndPaint(hWnd, &ps);
            break;
        }
        case WM_DESTROY: {
            SelectObject(s_hdcBackbuffer, s_hOldBitmap);
            DeleteDC(s_hdcBackbuffer);
            DeleteObject(s_hOldBitmap);
            PostQuitMessage(0);
            break;
        }
        default: {
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
        }
    }

    return 0;
}