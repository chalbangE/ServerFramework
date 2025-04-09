#pragma once
#include <cmath>

struct SVec3 {
    float x = 0, y = 0, z = 0;

    static const SVec3 Zero;
    static const SVec3 Up;
    static const SVec3 Right;
    static const SVec3 Forward;
    static const SVec3 Backward;

    SVec3() = default;
    SVec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    float Length() const {
        return sqrtf(x * x + y * y + z * z);
    }

    SVec3 GetNormalized() const {
        float len = Length();
        return len > 0 ? SVec3(x / len, y / len, z / len) : SVec3(0, 0, 0);
    }

    void Normalize() {
        float len = Length();
        if (len > 0) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    SVec3 Cross(const SVec3& other) const {
        return SVec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    SVec3 operator+(const SVec3& rhs) const {
        return SVec3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    SVec3 operator-(const SVec3& rhs) const {
        return SVec3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    SVec3 operator*(float scalar) const {
        return SVec3(x * scalar, y * scalar, z * scalar);
    }

    SVec3 operator/(float scalar) const {
        return SVec3(x / scalar, y / scalar, z / scalar);
    }

    bool operator!=(const SVec3& rhs) const {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }

    SVec3& operator+=(const SVec3& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    SVec3& operator-=(const SVec3& v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    SVec3& operator*=(float scalar) {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    SVec3& operator/=(float scalar) {
        x /= scalar; y /= scalar; z /= scalar;
        return *this;
    }
};