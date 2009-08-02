/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_TRIGONOMETRIC_HPP
#define GLCC_MATH_TRIGONOMETRIC_HPP

#include <cmath>
#include <glcc/math/detail/component_wise.hpp>

namespace gl
{
namespace math
{

/**
 * \defgroup trigonometry Angle and Trigonometry Functions (8.1)
 *
 * Function parameters specified as angle are assumed to be in units of radians.
 * In no case will any of these functions result in a divide by zero error.
 * If the divisor of a ratio is 0, then results will be undefined.
 *
 * These all operate component-wise. The description is per component.
 *
 * \{
 */

//! Converts degrees to radians, i.e. \f$ \frac{\pi}{180} * degrees \f$
GLCC_COMPONENT_WISE(float, radians, degrees)
{
	return M_PI / 180.0 * degrees; // TODO: portable solution
}

//! Converts radians to degrees, i.e. \f$ \frac{180}{\pi} * radians \f$
GLCC_COMPONENT_WISE(float, degrees, radians)
{
	180.0 / M_PI * radians; // TODO: portable solution
}

//! The standard trigonometric sine function.
GLCC_COMPONENT_WISE_STD(sin, angle)

//! The standard trigonometric cosine function.
GLCC_COMPONENT_WISE_STD(cos, angle)

//! The standard trigonometric tangent.
GLCC_COMPONENT_WISE_STD(tan, angle)

GLCC_COMPONENT_WISE_STD(asin, x)

GLCC_COMPONENT_WISE_STD(acos, x)

/// Arc tangent. Returns an angle whose tangent is y/x. The
/// signs of x and y are used to determine what quadrant the
/// angle is in. The range of values returned by this
/// function is [−, ]. Results are undefined if x and
/// y are both 0.
inline float atan(float y, float x)
{
	return std::atan2(y, x);
}

GLCC_COMPONENT_WISE_STD(atan, x)

GLCC_COMPONENT_WISE_STD(sinh, x)

GLCC_COMPONENT_WISE_STD(cosh, x)

GLCC_COMPONENT_WISE_STD(tanh, x)

GLCC_COMPONENT_WISE_T(asinh, x)
{
	return ::asinh(x);
}

GLCC_COMPONENT_WISE_T(acosh, x)
{
	return ::acosh(x);
}

GLCC_COMPONENT_WISE_T(atanh, x)
{
	return ::atanh(x);
}

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_TRIGONOMETRIC_HPP */
