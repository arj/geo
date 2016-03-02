#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

namespace geo {

class Vector3;

//! Matrix represents a classical 3x3 matrix.
//! The matrix is immutable.
class Matrix33
{
public:
    //! Creates an identity matrix.
    Matrix33();

    //! Creates a new matrix from values.
    Matrix33(double v11, double v12, double v13, double v21, double v22, double v23, double v31, double v32, double v33);
    
    //! Creates a new matrix from column vectors.
    Matrix33(const Vector3 v1, const Vector3 v2, const Vector3 v3);

    //! Returns the value at \f$(1,1) <= (i,j) <= (3,3)\f$.
    //!
    //! \throws std::invalid_argument if (i,j) is out of range.
    double get(int i, int j) const;
    
    //! \return Returns the determinant of the matrix.
    double determinant() const;
    
    Matrix33& operator*=(const double& scalar);
    Matrix33& operator/=(const double& scalar);
    
    friend std::ostream& operator<<(std::ostream& output, const Matrix33& matrix);
    friend const Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs);
    
private:
    std::vector<double> _values;
    double _det;
    void calculateDeterminant();
    void set(int i, int j, double v);
};

const Matrix33 operator*(const Matrix33& lhs, const double& rhs);
const Matrix33 operator/(const Matrix33& lhs, const double& rhs);

};

#endif