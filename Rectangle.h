#pragma once

// ----------------- TASK 1 -----------------
class Rectangle {
public:
    // ----------------- TASK 2 -----------------
    Rectangle();
    Rectangle(float length, float height);

    float getArea() {
        return m_length * m_height;
    }

    float getPerimeter() {
        return 2 * m_length + 2 * m_height;
    }

private:
    float m_length, m_height;
};