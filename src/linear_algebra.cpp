#include "linear_algebra.h"

#include "float_utils.h"

#include <cmath>

namespace geo {

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z)
{
    
}

Vector3& Vector3::operator*=(const double& scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& other_vector)
{
    this->x += other_vector.x;
    this->y += other_vector.y;
    this->z += other_vector.z;
    
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other_vector)
{
    this->x -= other_vector.x;
    this->y -= other_vector.y;
    this->z -= other_vector.z;
    
    return *this;
}

const Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    Vector3 tmp(lhs);
    tmp += rhs;
    return tmp;
}

const Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    Vector3 tmp(lhs);
    tmp -= rhs;
    return tmp;
}

const Vector3 operator*(const Vector3& lhs, const double rhs)
{
    Vector3 tmp(lhs);
    tmp *= rhs;
    return tmp;
}

const Vector3 operator*(const double lhs, const Vector3& rhs)
{
    Vector3 tmp(rhs);
    tmp *= lhs;
    return tmp;
}

bool Vector3::operator==(const Vector3 &other) const
{
    return this->x == other.x
        && this->y == other.y
        && this->z == other.z;
}

bool Vector3::equal(const Vector3& other, double tolerance) const
{
    return nearlyEqual(this->x, other.x, tolerance)
        && nearlyEqual(this->y, other.y, tolerance)
        && nearlyEqual(this->z, other.z, tolerance);
}

Vector3 Vector3::origin()
{
    return Vector3(0,0,0);
}

Vector3 Vector3::zero()
{
    return Vector3(0,0,0);
}

Vector3 Vector3::xAxis()
{
    return Vector3(1,0,0);
}

Vector3 Vector3::yAxis()
{
    return Vector3(0,1,0);    
}

Vector3 Vector3::zAxis()
{
    return Vector3(0,0,1);
}

double Vector3::length() const
{
    return std::sqrt(x*x + y*y + z*z);
}    

void Vector3::normalize()
{
    const int len = length();
    if (len != 0)
    {
        this->x /= len;
        this->y /= len;
        this->z /= len;
    }
}

Vector3 Vector3::normalized() const
{
    Vector3 tmp(*this);
    tmp.normalize();
    return tmp;
}

void Vector3::cross(const Vector3& v)
{
    double xx = this->y*v.z - this->z*v.y;
    double yy = this->z*v.x - this->x*v.z;
    double zz = this->x*v.y - this->y*v.x;
    
    this->x = xx;
    this->y = yy;
    this->z = zz;
}

Vector3 Vector3::crossed(const Vector3& v) const
{
    Vector3 tmp(*this);
    tmp.cross(v);
    return tmp;
}

bool Vector3::isZero(double tolerance /*= 0.0*/) const
{
    return nearlyEqual(0.0, x, tolerance)
        && nearlyEqual(0.0, y, tolerance)
        && nearlyEqual(0.0, z, tolerance);
}

std::ostream& operator<<(std::ostream& output, const Vector3& vector)
{
    output << "V(";
    output << vector.x << ",";
    output << vector.y << ",";
    output << vector.z;
    output << ")";
}

};
