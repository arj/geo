#ifndef FLOAT_UTILS_H
#define FLOAT_UTILS_H

#include <cmath>
#include <limits>

//! Nearly equal check for floating point numbers.
//!
//! \see http://floating-point-gui.de/errors/comparison/
//!
//! \param a,b     the numbers to check for equality
//! \param espilon the allowed tolerance
//!
//! \return true if a and b are nearly equal.
template <typename FloatT>
bool nearlyEqual(FloatT a, FloatT b, FloatT epsilon) {
    FloatT absA = std::abs(a);
    FloatT absB = std::abs(b);
    FloatT diff = std::abs(a-b);

    if (a == b) { // shortcut, handles infinities
        return true;
    } else if (a == 0 || b == 0 || diff < std::numeric_limits<FloatT>::min()) {
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < (epsilon * std::numeric_limits<FloatT>::min());
    } else { // use relative error
        return diff / (absA + absB) < epsilon;
    }
}

#endif // FLOAT_UTILS_H
