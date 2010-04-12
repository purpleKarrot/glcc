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
GLCC_COMPONENT_WISE(GLfloat, radians, (GLfloat, degrees))
{
	return M_PI / 180.0 * degrees;
}

//! Converts radians to degrees, i.e. \f$ \frac{180}{\pi} * radians \f$
GLCC_COMPONENT_WISE(GLfloat, degrees, (GLfloat, radians))
{
	180.0 / M_PI * radians;
}

//! The standard trigonometric sine function.
GLCC_COMPONENT_WISE(GLfloat, sin, (GLfloat, angle))
{
	return std::sin(angle);
}

//! The standard trigonometric cosine function.
GLCC_COMPONENT_WISE(GLfloat, cos, (GLfloat, angle))
{
	return std::cos(angle);
}

//! The standard trigonometric tangent.
GLCC_COMPONENT_WISE(GLfloat, tan, (GLfloat, angle))
{
	return std::tan(angle);
}

GLCC_COMPONENT_WISE(GLfloat, asin, (GLfloat, angle))
{
	return std::asin(angle);
}

GLCC_COMPONENT_WISE(GLfloat, acos, (GLfloat, angle))
{
	return std::acos(angle);
}

/// Arc tangent. Returns an angle whose tangent is y/x. The
/// signs of x and y are used to determine what quadrant the
/// angle is in. The range of values returned by this
/// function is [−, ]. Results are undefined if x and
/// y are both 0.
GLCC_COMPONENT_WISE(GLfloat, atan, (GLfloat, y)(GLfloat, x))
{
	return std::atan2(y, x);
}

GLCC_COMPONENT_WISE(GLfloat, atan, (GLfloat, angle))
{
	return std::atan(angle);
}

GLCC_COMPONENT_WISE(GLfloat, sinh, (GLfloat, angle))
{
	return std::sinh(angle);
}

GLCC_COMPONENT_WISE(GLfloat, cosh, (GLfloat, angle))
{
	return std::cosh(angle);
}

GLCC_COMPONENT_WISE(GLfloat, tanh, (GLfloat, angle))
{
	return std::tanh(angle);
}

GLCC_COMPONENT_WISE(GLfloat, asinh, (GLfloat, x))
{
	return ::asinh(x);
}

GLCC_COMPONENT_WISE(GLfloat, acosh, (GLfloat, x))
{
	return ::acosh(x);
}

GLCC_COMPONENT_WISE(GLfloat, atanh, (GLfloat, x))
{
	return ::atanh(x);
}

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_TRIGONOMETRIC_HPP */
