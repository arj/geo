#ifndef BSPLINE_H
#define BSPLINE_H

#include "curve.h"
#include "linear_algebra.h"
#include <vector>

namespace geo {

//! An implementation of a B-Spline.
//!
//! \see http://mathworld.wolfram.com/B-Spline.html
//! \see http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-ex-1.html
//!
//! \see http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-basis.html
//! \see http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-derv.html
//!
class BSpline : public Curve
{
    friend class BSplineTest;
    
public:
    //! Create a new B-Spline.
    //!
    //! \pre knots is a nondecreasing list
    //! \pre |control_points| >= 1
    //! \pre p = |knots| - |control_points| - 1 > 0
    //!
    //! \param degree         the degree of the bspline curve
    //! \param knots          nondecreasing list of knots [0..1] // TODO Really?
    //! \param control_points list of control_points
    //!
    BSpline(unsigned int degree, const std::vector<double>& knots, const std::vector<Point3>& control_points);


    //! Create a new B-Spline with explicit multiplicities.
    //!
    //! \pre knots is a nondecreasing list with non-zero multiplicities
    //! \pre |control_points| >= 1
    //! \pre p = |knots| - |control_points| - 1 > 0
    //!
    //! \param knots          nondecreasing list of knots with multiplicities [0..1] // TODO Really?
    //! \param control_points list of control_points
    //!
    BSpline(unsigned int degree, const std::vector<std::pair<double,unsigned int>>& knots, const std::vector<Point3>& control_points);

    //! \return the degree of the bspline
    unsigned int degree() const;

    // inherited from Curve
public:
    Point3 getStart() const override;
    Point3 getEnd() const override;
    Point3 getMidpoint() const override;
    Point3 getPoint(double t) const override;
    double getLength() const override;
    Vector3 firstDerivative(double parameter) const override;
    Vector3 secondDerivative(double parameter) const override;

    unsigned int findSpan(int n, int p, double u) const;
    std::vector<double> basisFuns(int i, double u, int p) const;

private:
    std::vector<double> m_knots;
    std::vector<Point3> m_control_points;
    unsigned int m_degree;

    // TODO This could be precalculated in a map of i,j -> double
    double basisFunction(unsigned int i, double t) const;
    double basisFunction(unsigned int i, unsigned int j, double t) const;
};

}

#endif // BSPLINE_H
