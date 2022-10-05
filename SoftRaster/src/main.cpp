#include <iostream>
#include "matrix/matrix.h"
#include "devices/windows_forms.h"

#define STB_IMAGE_IMPLEMENTATION

#include "tex/stb_image.h"
#include "tex/texture.h"

int main() {

//    WindowsForms *w = new WindowsForms(800, 600);
//    auto buff = w->getFrameBuffer();
//    for (int i = 0; i < 800 * 600; i++) {
//        unsigned short int r = 255;
//        unsigned short int g = 0;
//        unsigned short int b = 122;
//        unsigned int c = (unsigned int) ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
//        *buff[i] = c;
//    }
//    while (w->screenDispatch()) {
//        w->screenUpdate();
//        Sleep(1);
//    }

    int w, h, c;
    stbi_uc *pixels = stbi_load("..\\resources\\container2_diffuse.png", &w, &h, &c, STBI_rgb_alpha);

    if (!pixels) {
        std::cout << "laod img error" << std::endl;
    }

//    std::cout << pixels << std::endl;

    std::cout << w << std::endl;
    std::cout << h << std::endl;
    std::cout << c << std::endl;

    unsigned int *data = (unsigned int *) pixels;
    int index = 500;
    std::cout << data[index] << std::endl;

    unsigned short int r = (data[index]) & 0xff;
    unsigned short int g = (data[index] >> 8) & 0xff;
    unsigned short int b = (data[index] >> 16) & 0xff;
    unsigned short int a = (data[index] >> 24) & 0xff;
    std::cout << r << std::endl;
    std::cout << g << std::endl;
    std::cout << b << std::endl;
    std::cout << a << std::endl;


    std::cout << "======================" << std::endl;
    Texture *tex = new Texture("..\\resources\\container2_diffuse.png");
    std::cout << tex->width << std::endl;
    std::cout << tex->sample(*vec2(0))->toString() << std::endl;

    Vec4* cc = vec4(1);
    std::cout << cc->toString() << std::endl;
    tex->sample(*vec2(0), cc);
    std::cout << cc->toString() << std::endl;

    return 0;
}