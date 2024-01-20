#pragma once
#include <iostream>

class Vector2d {
public:
    Vector2d();
    Vector2d(float x, float y);
    ~Vector2d();

    void operator=(const Vector2d& vector);
    bool operator==(const Vector2d& vector);

    Vector2d operator+(const Vector2d& secondVector);
    Vector2d operator-(const Vector2d& secondVector);

    friend Vector2d& operator+ (const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d& operator- (const Vector2d& leftVector, const Vector2d& rightVector);

    float operator()();

    float& operator[](int i);

    friend std::ostream& operator<< (std::ostream& out, const Vector2d& vector);
    friend void operator>> (std::istream& in, Vector2d& vector);

    static int vectors_count;
private:
    float x = 0.0f;
    float y = 0.0f;
};

void create_dummy_vector();