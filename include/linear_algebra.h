#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <iostream>

namespace geo {

//! A vector only gives a direction and thus does not move when translated.
//! It can only change its length and be rotated.
class Vector3 {
public:
    Vector3(double x, double y, double z);
    
    //! \return Returns the length of the vector.
    double length() const;

    //! \return Returns the squared length of the vector.
    double lengthSquared() const;
    
    //! Normalizes the vector. The zero vector is unchanged.
    void normalize();
    
    //! \return Returns a normalized copy of the vector.
    Vector3 normalized() const;
    
    //! \return Returns the cross product of this and another vector.
    Vector3 crossed(const Vector3& other_vector) const;
    
    //! In-place cross product.
    void cross(const Vector3& other_vector);

    Vector3& operator+=(const Vector3& other_vector);
    Vector3& operator-=(const Vector3& other_vector);
    Vector3& operator*=(const double& scalar);
    bool operator==(const Vector3 &other) const;

    bool equal(const Vector3& other, double tolerance) const;

public:
    //! Checks if the vector is the zero vector.
    //!
    //! \param tolerance optional tolerance for comparison with zero
    //!
    //! \return true if it is.
    bool isZero(double tolerance = 0.0) const;

    //! \return the zero vector
    static Vector3 zero();

    //! \return the unit vector (1,0,0)
    static Vector3 xAxis();

    //! \return the unit vector (0,1,0)
    static Vector3 yAxis();

    //! \return the unit vector (0,0,1)
    static Vector3 zAxis();

    friend std::ostream& operator<<(std::ostream& output, const Vector3& vector);

public:
    double x;
    double y;
    double z;
};

const Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
const Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
const Vector3 operator*(const Vector3& lhs, const double rhs);
const Vector3 operator*(const double lhs, const Vector3& rhs);

//! Simplification. Normally a point moves when translated, a vector doesn't.
typedef Vector3 Point3;

};

#endif
