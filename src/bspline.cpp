#include "bspline.h"

#include <stdexcept>

namespace geo {

BSpline::BSpline(unsigned int degree, const std::vector<double>& knots, const std::vector<Point3>& control_points)
    : m_knots(knots), m_control_points(control_points)
{
    if (knots.size() < 2) {
        throw std::invalid_argument("At least two knots are required");
    }

    if (control_points.size() < 2) {
        throw std::invalid_argument("At least two control points are required");
    }

    //m_degree = knots.size() - control_points.size() - 1;
}

unsigned int BSpline::degree() const
{
    return m_degree;
}

Point3 BSpline::getStart() const
{
    return m_control_points.front();
}

Point3 BSpline::getEnd() const
{
    return m_control_points.back();
}

Point3 BSpline::getMidpoint() const
{
    throw std::logic_error("Not implemented yet");
}

unsigned int BSpline::findSpan(int n, int p, double u) const
{
    if (u == m_knots[n+1]) {
        return n;
    }
    
    // TODO Binary search might be faster
    for (int i=p; i<=n+1; ++i) {
        double t_i = m_knots.at(i);
        double t_i_1 = m_knots.at(i+1);
        
        if (t_i <= u && u < t_i_1) {
            return i;
        }
    }
    
    throw std::logic_error("Error");
}

std::vector<double> BSpline::basisFuns(int i, double u, int p) const
{
    std::vector<double> result(p, 1.0);
    std::vector<double> left(p, 0.0);
    std::vector<double> right(p, 0.0);
    
    // for (int j=0; j<p; ++j) {
    //     left[j] = u-m_knots[i+j];
    //     right[j] = m_knots[i+j-1]-u;
        
    //     double saved = 0.0;
        
    //     for (int r=0;r<j+1)
    // }
    
    return result;
}

Point3 BSpline::getPoint(double t) const
{
    Point3 result = Point3::zero();

    size_t n = m_control_points.size();
    unsigned int p = m_degree;

    for (unsigned int i = 0; i < n; ++i) {
        Point3 p_i = m_control_points[i];

        result += p_i * basisFunction(i,p,t);
    }

    return result;
}

double BSpline::getLength() const
{
    throw std::logic_error("Not implemented yet");
}

Vector3 BSpline::firstDerivative(double parameter) const
{
    throw std::logic_error("Not implemented yet");
}

Vector3 BSpline::secondDerivative(double parameter) const
{
    throw std::logic_error("Not implemented yet");
}

double BSpline::basisFunction(unsigned int i, double t) const
{
    // Create a lookup-table for the N_{i,j} ?

    if (i+1 < m_knots.size()) { // TODO Internal knots?
        double t_i = m_knots[i];
        double t_i_1 = m_knots[i+1];

        if ((t_i <= t && t < t_i_1) && (t_i < t_i_1)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

double BSpline::basisFunction(unsigned int i, unsigned int j, double t) const
{
    // assert(j = 1,2,...,m_degree)

    if (j == 0) {
        return basisFunction(i, t);
    }

    double n1 = basisFunction(i,j-1,t);
    double n2 = basisFunction(i+1,j-1,t);

    double t_i = m_knots[i];
    double t_i_1 = m_knots[i+1];
    double t_i_j = m_knots[i+j];
    double t_i_j_1 = m_knots[i+j+1];

    double fst_part = (t - t_i) / (t_i_j - t_i) * basisFunction(i,j-1,t);
    double snd_part = (t_i_j_1 - t) / (t_i_j_1 - t_i_1) * basisFunction(i+1,j-1,t);

    return fst_part + snd_part;
}

}