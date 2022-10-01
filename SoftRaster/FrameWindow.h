//
// Created by root on 2022/9/27.
//

#ifndef SOFTRASTER_FRAMEWINDOW_H
#define SOFTRASTER_FRAMEWINDOW_H

#include <windows.h>

class FrameWindow {
public:
    FrameWindow(int width, int height);
    ~FrameWindow();
public:
    int width;
    int height;

    int run(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow);
};


#endif //SOFTRASTER_FRAMEWINDOW_H
