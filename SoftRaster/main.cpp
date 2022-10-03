#include <iostream>
#include "matrix/matrix.h"
#include "devices/windows_forms.h"

int main() {
    WindowsForms* w = new WindowsForms(800, 600);
    auto buff = w->getFrameBuffer();
    for(int i = 0; i < 800 * 600; i++){
        unsigned short int r = 255;
        unsigned short int g = 0;
        unsigned short int b = 122;
        unsigned int c = (unsigned int) ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
        *buff[i] = c;
    }
    while (w->screenDispatch()){
        w->screenUpdate();
        Sleep(1);
    }



    return 0;
}