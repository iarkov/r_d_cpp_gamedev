#pragma once

enum class Direction {
    Forward = 1,
    Backward = -1
};

struct LineParameters {
    float length = 500.f;
    float rotationAngle = 0.f;
};

struct Coordinates {
    float x = 0.f;
    float y = 0.f;
};

struct BoundParams {
    float width = 0.f;
    float height = 0.f;
};