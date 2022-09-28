#include <iostream>
#include <windows.h>
#include "FrameWindow.h"
#include "math/Vec2.h"


int WINAPI
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

    FrameWindow w1 = *new FrameWindow(800, 600);

    std::cout << "hello world" << std::endl;

    return w1.run(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

int main() {
    std::cout << "hello" << std::endl;

    Vec2 a = *new Vec2(1, 2);
    Vec2 b = *new Vec2(2, 5);
    a = a-b;
    a = b.clone();
    std::cout << a.x << std::endl;
    std::cout << a.y << std::endl;
    return 0;
}