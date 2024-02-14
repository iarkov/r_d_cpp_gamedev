#include "HW26.h"

int Vector2d::vectors_count = 0;

Vector2d::Vector2d() { vectors_count++; };
Vector2d::Vector2d(float x, float y) : x(x), y(y) { vectors_count++; };
Vector2d::Vector2d(float x0, float y0, float x1, float y1) : x(x1 - x0), y(y1 - y0) { vectors_count++; };
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

float Vector2d::dotProduct(Vector2d& other) const {
    return x * other.x + y * other.y;
};

Vector2d Vector2d::negate() const {
    return Vector2d(-x, -y);
};

VectorRelativeState Vector2d::getRelativeState(Vector2d& other) const {
    float cos = this->dotProduct(other) / (std::sqrt(x * x + y * y) * other());
    
    if (static_cast<int>(cos) == 1) {
        if (std::sqrt(x * x + y * y) == other()) {
            return VectorRelativeState::Identical;
        }
        else {
            return VectorRelativeState::coDirected;
        }
    }
    else if (static_cast<int>(cos) == -1) {
        return VectorRelativeState::OppositeDirected;
    }
    else if (cos == 0) {
        return VectorRelativeState::RightAngle;
    }
    else if (cos > 0) {
        return VectorRelativeState::AcuteAngle;
    }
    else if (cos < 0) {
        return VectorRelativeState::ObtuseAngle;
    }
};

void Vector2d::scale(float factorX, float factorY) {
    x = x * factorX;
    y = y * factorY;
};

Vector3d Vector3d::crossProduct(const Vector3d& other) {
    float cx = y * other.z - z * other.y;
    float cy = z * other.x - x * other.z;
    float cz = x * other.y - y * other.x;
    return Vector3d(cx, cy, cz);
};

std::ostream& operator<< (std::ostream& out, const Vector3d& vector) {
    out << "{" << vector.x << "; " << vector.y << "; " << vector.z << "}";

    return out;
}

void operator>> (std::istream& in, Vector3d& vector) {
    float x;
    float y;
    float z;

    in >> x >> y >> z;

    vector = Vector3d(x, y, z);
};

VectorRelativeState Vector3d::getRelativeState(Vector3d& other) const {
    float cos = this->dotProduct(other) / (std::sqrt(x * x + y * y + z * z) * other());
    
    if (static_cast<int>(cos) == 1) {
        if (std::sqrt(x * x + y * y) == other()) {
            return VectorRelativeState::Identical;
        }
        else {
            return VectorRelativeState::coDirected;
        }
    }
    else if (static_cast<int>(cos) == -1) {
        return VectorRelativeState::OppositeDirected;
    }
    else if (cos == 0) {
        return VectorRelativeState::RightAngle;
    }
    else if (cos > 0) {
        return VectorRelativeState::AcuteAngle;
    }
    else if (cos < 0) {
        return VectorRelativeState::ObtuseAngle;
    }
};