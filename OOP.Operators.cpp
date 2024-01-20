#include "HW17.h"
#include <iostream>
#include <cmath>

int main()
{
    Vector2d v1{ 0.1f, 0.2f };
    Vector2d v2{ 0.3f, 0.2f };
    Vector2d v3 = v1 + v2 - (v2 - v1);
    std::cout << "Vector's coordinates and length: " << v3 << ", " << v3() << std::endl;
    std::cout << "Sum of vector's coordinates and length: " << v3[0] + v3[1] << std::endl;
    //std::cout << v3[2];

    Vector2d testVec{ 1.2, 5.6 };
    std::cout << testVec << std::endl;

    std::cout << "Enter vector's coordinates: ";
    std::cin >> testVec;
    std::cout << testVec << std::endl;

    create_dummy_vector(); // shows how many vectors were created in all scopes till now
    std::cout << Vector2d::vectors_count << std::endl; // shows how many vectors were created in all scopes till now
}