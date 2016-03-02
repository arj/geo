#include "matrix.h"
#include "linear_algebra.h"

#include <algorithm>

namespace geo {

Matrix33::Matrix33()
: Matrix33(1,0,0,0,1,0,0,0,1)
{
    
}

Matrix33::Matrix33(double v11, double v12, double v13, double v21, double v22, double v23, double v31, double v32, double v33)
: _values(12)
{
    set(1,1,v11);
    set(1,2,v12);
    set(1,3,v13);
    set(2,1,v21);
    set(2,2,v22);
    set(2,3,v23);
    set(3,1,v31);
    set(3,2,v32);
    set(3,3,v33);
    
    calculateDeterminant();
}

Matrix33::Matrix33(const Vector3 v1, const Vector3 v2, const Vector3 v3)
: Matrix33(v1.x, v2.x, v3.x, v1.y, v2.y, v3.y, v1.z, v2.z , v3.z)
{
    
}

void Matrix33::set(int i, int j, double v)
{
    _values[i*3 + j] = v;
}

double Matrix33::get(int i, int j) const
{
    return _values[i*3 + j];
}

void Matrix33::calculateDeterminant()
{
    const double pos = get(1,1)*get(2,2)*get(3,3) + get(1,2)*get(2,3)*get(3,1) + get(1,3)*get(2,1)*get(3,2);
    const double neg = get(1,3)*get(2,2)*get(3,1) + get(1,2)*get(2,1)*get(3,3) + get(1,1)*get(2,3)*get(3,2);
    
    _det = pos - neg;
}

const Matrix33 operator*(const Matrix33& lhs, const double& rhs)
{
    Matrix33 tmp(lhs);
    tmp *= rhs;
    return tmp;
}

Matrix33& Matrix33::operator*=(const double& scalar)
{
    std::transform(_values.begin(), _values.end(), _values.begin(), [&] (const double& v) { return v*scalar; });
    
    return *this;
}

const Matrix33 operator/(const Matrix33& lhs, const double& rhs)
{
    Matrix33 tmp(lhs);
    tmp /= rhs;
    return tmp;
}

Matrix33& Matrix33::operator/=(const double& scalar)
{
    std::transform(_values.begin(), _values.end(), _values.begin(), [&] (const double& v) { return v/scalar; });
    
    return *this;
}

double Matrix33::determinant() const
{
    return _det;
}

const Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs)
{
    Matrix33 m;
    
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++) {
            m.set(i,j, lhs.get(i,j) + rhs.get(i,j));
        }
    }
    
    m.calculateDeterminant();
    return m;
}

std::ostream& operator<<(std::ostream& output, const Matrix33& matrix)
{
    output << "| " << matrix.get(1,1) << ", " << matrix.get(1,2) << ", " << matrix.get(1,3) << " |" << std::endl;
    output << "| " << matrix.get(2,1) << ", " << matrix.get(2,2) << ", " << matrix.get(2,3) << " |" << std::endl;
    output << "| " << matrix.get(3,1) << ", " << matrix.get(3,2) << ", " << matrix.get(3,3) << " |" << std::endl;
    
    return output;
}

};