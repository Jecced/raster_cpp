#include <iostream>
#include "matrix/matrix.h"

int main() {
//    std::cout << "hello" << std::endl;
//
//    Vec2 *a = new Vec2(1, 2);
//    Vec2 *b = new Vec2(2, 5);
//    a = *a - *b;
//    *a = b->clone();
//    std::cout << a->x << std::endl;
//    std::cout << a->y << std::endl;
//
//    // 解引用
//    Mat2 *m = new Mat2();
//    std::cout << m->toString() << std::endl;
//
//
//    printf("0x%x\n", &a);
//    printf("0x%x\n", a);
//    printf("0x%x\n", &b);
//    printf("0x%x\n", b);
//
//    Vec4 *v = new Vec4(2, 3, 4, 5);
//    std::cout << v->x << std::endl;
//    std::cout << v->toString() << std::endl;
//    std::cout << a->toString() << std::endl;
//    std::cout << v->toString() << std::endl;
//
//    float d = dot(*a, *b);
//
//    std::cout << d << std::endl;
//
//    delete m;
//    delete a;
//    delete b;



    Mat2 *a = mat2(3, 1, 0, 1);
    Mat2 *b = mat2(2, 2, 0, 1);
    Mat2 *c = *a * *b;
    std::cout << c->toString() << std::endl;

    Vec2 *v2 = vec2(1, 2);
    std::cout << v2->toString() << std::endl;
    v2 = normalize(*v2);
    std::cout << v2->toString() << std::endl;

    return 0;
}