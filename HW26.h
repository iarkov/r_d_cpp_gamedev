#pragma once
#include <iostream>

enum class VectorRelativeState { Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle };

class Vector2d {
public:
    Vector2d();
    Vector2d(float x, float y);
    Vector2d(float x0, float y0, float x1, float y1);
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

    float dotProduct(Vector2d& other) const;
    Vector2d negate() const;
    VectorRelativeState getRelativeState(Vector2d& other) const;
    void scale(float factorX, float factorY);

    static int vectors_count;
private:
    float x = 0.0f;
    float y = 0.0f;
};

class Vector3d {
public:
    Vector3d() {};
    Vector3d(float x, float y, float z) : x(x), y(y), z(z) {};
    Vector3d(float x0, float y0, float z0, float x1, float y1, float z1) :
        x(x1 - x0), y(y1 - y0), z(z1 - z0) {};
    ~Vector3d() {};

    float operator()() {
        return std::sqrt(x * x + y * y + z * z);
    };

    float& operator[](int i) {
        if (i == 0) { return x; }
        else if (i == 1) { return y; }
        else if (i == 2) { return z; }
    };

    float dotProduct(Vector3d& other) const {
        return x * other.x + y * other.y + z * other.z;
    };

    VectorRelativeState getRelativeState(Vector3d& other) const;

    friend std::ostream& operator<< (std::ostream& out, const Vector3d& vector);
    friend void operator>> (std::istream& in, Vector3d& vector);

    Vector3d crossProduct(const Vector3d& other);
private:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

void create_dummy_vector();