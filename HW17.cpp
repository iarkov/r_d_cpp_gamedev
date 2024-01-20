#include "HW17.h"

int Vector2d::vectors_count = 0;

Vector2d::Vector2d() { vectors_count++; };
Vector2d::Vector2d(float x, float y) : x(x), y(y) { vectors_count++; };
Vector2d::~Vector2d() {
    vectors_count--;
};

void create_dummy_vector() {
    Vector2d testVec2;
    std::cout << Vector2d::vectors_count << std::endl;
}

void Vector2d::operator=(const Vector2d& vector) {
    x = vector.x;
    y = vector.y;
}

bool Vector2d::operator==(const Vector2d& vector) {
    if (x == vector.x && y == vector.y) {
        return true;
    }
    else {
        return false;
    }
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) {
    Vector2d vector(x + secondVector.x, y + secondVector.y);

    return vector;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) {
    Vector2d vector(x - secondVector.x, y - secondVector.y);

    return vector;
}

Vector2d& operator+ (const Vector2d& leftVector, const Vector2d& rightVector) {
    return leftVector + rightVector;
}

Vector2d& operator- (const Vector2d& leftVector, const Vector2d& rightVector) {
    return leftVector - rightVector;
}

float Vector2d::operator()() {
    return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](int i) {
    try {
        if (i == 0) {
            return x;
        }
        else if (i == 1) {
            return y;
        }
        else {
            throw(i);
        }
    }
    catch (int i) {
        std::cout << "Index [" << i << "] is not valid. Vector's index must by [0] or [1]." << std::endl;
    }
};

std::ostream& operator<< (std::ostream& out, const Vector2d& vector) {
    out << "{" << vector.x << "; " << vector.y << "}";

    return out;
}

void operator>> (std::istream& in, Vector2d& vector) {
    float x;
    float y;

    in >> x >> y;

    vector = Vector2d(x, y);
}