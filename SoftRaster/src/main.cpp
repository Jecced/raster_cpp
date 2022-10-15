#include <iostream>
#include "matrix/matrix.h"
#include "devices/windows_forms.h"


#include "libs/stb_image.h"
#include "tex/texture.h"
#include "engine/comp/mesh.h"
#include "engine/pipeline/vertex_ctl.h"
#include "engine/util/mesh_util.h"
#include "engine/pipeline/pipeline.h"
#include "devices/time.h"
#include "engine/shader/shader_simple.h"
#include "engine/shader/shader_unlit.h"


int main() {

    int width = 800;
    int height = 600;

    Time *time = new Time();


    Mesh *mesh = MeshUtil::Obj2Mesh("../resources/african_head.obj");
//    Mesh *mesh = MeshUtil::Triangle();
    ShaderLab *shader = new ShaderUnlit("../resources/african_head_diffuse.png");


//    Mesh *mesh = MeshUtil::Obj2Mesh("../resources/diablo3_pose.obj");
////    Mesh *mesh = MeshUtil::Quad();
//    ShaderLab *shader = new ShaderUnlit("../resources/diablo3_pose_diffuse.png");


    WindowsForms *win = new WindowsForms(width, height);
    Pipeline *pipeline = new Pipeline(width, height, win->getFrameBuffer());


    Camera *camera = new Camera(width, height, -1, -20, 45);
    camera->usePerspective();
    camera->setPosition(*vec3(1, 0, 3));
    camera->lookAt(*vec3(0, 0, 0));

    while (win->screenDispatch()) {
        time->once();
//        std::cout << time->getDT() << std::endl;
        win->setTitle("SoftRaster " + std::to_string(time->getDT()) + "ms");


        pipeline->clear();

        pipeline->bindShader(*shader);
        pipeline->setupCamera(*camera);
        pipeline->drawMesh(*mesh);

        win->screenUpdate();
    }
    return 0;


//    WindowsForms *win = new WindowsForms(800, 600);
//    auto buff = win->getFrameBuffer();
//
//    CameraTarget* cameraTarget = new CameraTarget(width, height, buff);
//
//    while (win->screenDispatch()) {
//        time->once();
//
//        for (int x = 0; x < width; x++) {
//            for(int y = 0; y < height; y++){
//                cameraTarget->setColor(x, y, *vec4(sin(time->RunTime()) * 0.5 + 0.5, 0, 0, 1));
//            }
//        }
//        win->screenUpdate();
//        Sleep(1);
//    }
//
//    return 0;



//    WindowsForms *win = new WindowsForms(800, 600);
//    auto buff = win->getFrameBuffer();
//    for (int i = 0; i < 800 * 600; i++) {
//        unsigned short int r = 255;
//        unsigned short int g = 0;
//        unsigned short int b = 122;
//        unsigned int c = (unsigned int) ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
//        buff[i] = c;
//    }
//    while (win->screenDispatch()) {
//        win->screenUpdate();
//        Sleep(1);
//    }

//    int w, h, c;
//    stbi_uc *pixels = stbi_load("..\\resources\\container2_diffuse.png", &w, &h, &c, STBI_rgb_alpha);
//
//    if (!pixels) {
//        std::cout << "laod img error" << std::endl;
//    }
//
////    std::cout << pixels << std::endl;
//
//    std::cout << w << std::endl;
//    std::cout << h << std::endl;
//    std::cout << c << std::endl;
//
//    unsigned int *data = (unsigned int *) pixels;
//    int index = 500;
//    std::cout << data[index] << std::endl;
//
//    unsigned short int r = (data[index]) & 0xff;
//    unsigned short int g = (data[index] >> 8) & 0xff;
//    unsigned short int b = (data[index] >> 16) & 0xff;
//    unsigned short int a = (data[index] >> 24) & 0xff;
//    std::cout << r << std::endl;
//    std::cout << g << std::endl;
//    std::cout << b << std::endl;
//    std::cout << a << std::endl;
//
//
//    std::cout << "======================" << std::endl;
//    Texture *tex = new Texture("..\\resources\\container2_diffuse.png");
//    std::cout << tex->width << std::endl;
//    std::cout << tex->sample(*vec2(0))->toString() << std::endl;
//
//    Vec4 *cc = vec4(1);
//    std::cout << cc->toString() << std::endl;
//    tex->sample(*vec2(0), cc);
//    std::cout << cc->toString() << std::endl;
//
//    return 0;
}