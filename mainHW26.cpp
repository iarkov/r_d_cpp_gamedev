#include "HW26.h"
#include <iostream>
#include <cmath>

int main()
{
    Vector2d v1{ 0.1f, 0.2f };
    Vector2d v2{ 0.3f, 0.2f };
    Vector2d v3 = v1 + v2 - (v2 - v1);
    std::cout << "Vector's coordinates and length: " << v3 << ", " << v3() << std::endl;
    std::cout << "Sum of vector's coordinates: " << v3[0] + v3[1] << std::endl;
    //std::cout << v3[2];

    Vector2d testVec{ 1.2, 5.6 };
    std::cout << testVec << std::endl;

    //std::cout << "Enter vector's coordinates: ";
    //std::cin >> testVec;
    //std::cout << testVec << std::endl;

    //create_dummy_vector(); // shows how many vectors were created in all scopes till now
    //std::cout << Vector2d::vectors_count << std::endl; // shows how many vectors were created in all scopes till now

    std::cout << "Inverse vector for " << v1 << " is " << v1.negate() << std::endl;
    Vector2d v4{ 1,2,3,4 };
    std::cout << "Dot product of vector " << v4 << " and vector " << v1 << " is " << v4.dotProduct(v1) << std::endl;
    Vector2d v5{ 2,2 };
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl;
    v5 = Vector2d(4,4);
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl;
    v5 = Vector2d(-2, -2);
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl;
    v5 = Vector2d(2, 3);
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl;
    v5 = Vector2d(-2, -3);
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl;
    v5 = Vector2d(2, -2);
    std::cout << "Relative state of vector " << v5 << " to vector " << v4 << " is " << static_cast<int>(v5.getRelativeState(v4)) << std::endl << std::endl;

    Vector3d v6{ 1,2,3 };
    Vector3d v7{ 3,2,1 };
    Vector3d crossProd = v6.crossProduct(v7);

    std::cout << "Cross product of vectors " << v6 << " and " << v7 << " is " << crossProd << std::endl;
    std::cout << "Relative state of vector " << v6 << " to vector " << crossProd << " is "
        << static_cast<int>(v6.getRelativeState(crossProd)) << std::endl;
    std::cout << "Relative state of vector " << v7 << " to vector " << crossProd << " is "
        << static_cast<int>(v7.getRelativeState(crossProd)) << std::endl;
}