#include <iostream>
#include <windows.h>
#include "FrameWindow.h"


int WINAPI
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

    FrameWindow w1 = *new FrameWindow(800, 600);

    std::cout << "hello world" << std::endl;

    return w1.run(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}