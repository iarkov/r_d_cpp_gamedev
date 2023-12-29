#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
    m_length = 4.0;
    m_height = 2.0;

    std::cout << "New rectangle created with length of " << m_length << " and height of " << m_height << std::endl;
}

Rectangle::Rectangle(float length, float height) :
    m_length(length), m_height(height)
{
    std::cout << "New rectangle created with length of " << m_length << " and height of " << m_height << std::endl;
}