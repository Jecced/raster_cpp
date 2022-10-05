//
// Created by jecced on 2022/10/3.
//

#ifndef SOFTRASTER_WINDOWS_FORMS_H
#define SOFTRASTER_WINDOWS_FORMS_H

#include <string>
#include <windows.h>

class WindowsForms {
private:
    int width, height;
    std::string title;
    HWND screenHandle;      // 主窗口 HWND
    HDC screenDC;           // 配套的 HDC
    HBITMAP screenHB;       // DIB
    HBITMAP screenOB;       // 老的 BITMAP
    unsigned int *framebuffer;     // FrameBuffer

public:
    WindowsForms(int width, int height);

    ~WindowsForms();

    int getHeight();

    int getWidth();

private:
    int screenClose();

    int screenInit(int w, int h, const CHAR *title);

    LRESULT static screenEvents(HWND hWnd, UINT msg,
                                WPARAM wParam, LPARAM lParam);

public:
    int screenDispatch();

    void screenUpdate();

    unsigned int *getFrameBuffer();

};


#endif //SOFTRASTER_WINDOWS_FORMS_H
