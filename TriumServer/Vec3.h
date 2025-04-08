#pragma once
#include <cmath>

struct Vec3 {
    float x = 0, y = 0, z = 0;

    static const Vec3 Zero;
    static const Vec3 Up;
    static const Vec3 Right;
    static const Vec3 Forward;
    static const Vec3 Backward;

    Vec3() = default;
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    float Length() const {
        return sqrtf(x * x + y * y + z * z);
    }

    Vec3 GetNormalized() const {
        float len = Length();
        return len > 0 ? Vec3(x / len, y / len, z / len) : Vec3(0, 0, 0);
    }

    void Normalize() {
        float len = Length();
        if (len > 0) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    Vec3 Cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    Vec3 operator+(const Vec3& rhs) const {
        return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Vec3 operator-(const Vec3& rhs) const {
        return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    bool operator!=(const Vec3& rhs) const {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }

    Vec3& operator+=(const Vec3& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    Vec3& operator*=(float scalar) {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    Vec3& operator/=(float scalar) {
        x /= scalar; y /= scalar; z /= scalar;
        return *this;
    }
};