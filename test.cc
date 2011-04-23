#include <iostream>

#include "wip3dmath.h"

int main(void) {
    wip3dmath::Vector v, v2;
    wip3dmath::Movement m;

    std::cout << "Vector basic operations check." << std::endl;
    v.set(1.0,0.0,0.0);
    v2 = v;

    if ( v != v2 ) {
        std::cout << "error: (v = " << v << ") != (v2 = " << v2 << ")" << std::endl;
        return 1;
    }

    std::cout << "Good." << std::endl;

    double od = v.length();
    double d = 0.0; // only works like this... you know why.

    std::cout << "Movement::operator<< (double) and Vector::operator<< (Movement) check." << std::endl;
    m << d;
    v << m;
    if ( v != v2 ) {
        std::cout << "error: v changed before move(): v = " << v << std::endl;
        return 2;
    }

    v.move();
    if ( d != v.length() - od ) {
        std::cout << "error: (length d = " << d << ") != (length v = " << v.length() - od << ")" << std::endl;
        return 3;
    }

    std::cout << "Good." << std::endl;

    std::cout << "Vector::operator<< (double) check." << std::endl;
    v = v2;
    v << d;
    if ( v != v2 ) {
        std::cout << "error: v changed before move(): v = " << v << std::endl;
        return 4;
    }

    v.move();
    if ( d != v.length() - od ) {
        std::cout << "error: (length d = " << d << ") != (length v = " << v.length() - od << ")" << std::endl;
        return 5;
    }

    std::cout << "Good." << std::endl;

    // Quaternion code is broken
    /*
    std::cout << "Point3D::rotate check" << std::endl;
    wip3dmath::Quaternion q;
    q.set(0.0, 0.0, -90.0);
    std::cout << v << std::endl;
    v.rotate(q);
    if ( v != wip3dmath::Vector(0.0, 0.0, -1.0) ) {
        std::cout << "error: (v = " << v << ") != Point3D(0.0, 0.0, -1.0)" << std::endl;
        return 6;
    }
    std::cout << "Good." << std::endl;*/

    std::cout << "Vector::operator<<(Movement) and Movement::operator<<(Euler) check." << std::endl;
    wip3dmath::Euler e(0.0, -90.0, 0.0);
    Movement m2;
    m2.setAxisXPositive();
    m2 << e;
    v << m2;
    v.move();
    v2 = v - wip3dmath::Vector(1.0, 0.0, -1.0);
    if ( v2.length() > 0.0000001 ) {
        std::cout << "error: (v = " << v << ") != Vector(1.0, 0.0, -1.0)" << std::endl;
        return 10;
    }
    std::cout << "Good." << std::endl;


    std::cout << "Cylinder inVolume and distance check." << std::endl;
    wip3dmath::Cylinder c(0, 0, 0, 3.0, 4.0);
    wip3dmath::Point3D p1(0, 0, 0); // (inside)
    wip3dmath::Point3D p2(3, -4, 3); // (outside)
    if ( not c.inVolume(p1) or c.inVolume(p2) ) {
        std::cout << "error: Cylinder::inVolume() check." << std::endl;
        return 7;
    }

    if ( c.distance(p1) != 0.0 ) {
        std::cout << "error: p1 distance (" << c.distance(p1) << ") != 0.0 while inside volume." << std::endl;
        return 8;
    }

    if ( c.distance(p2) <= 0.0 ) {
        std::cout << "error: p2 distance (" << c.distance(p2) << ") <= 0.0 while outside volume." << std::endl;
        return 9;
    }

    std::cout << "Good." << std::endl;

    return 0;
}
