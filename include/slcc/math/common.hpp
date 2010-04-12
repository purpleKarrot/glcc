/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_COMMON_HPP
#define GLCC_MATH_COMMON_HPP

#include <cmath>
#include <algorithm>
#include <glcc/detail/gl.hpp>
#include "detail/component_wise.hpp"

namespace gl
{
namespace math
{

/**
 * \defgroup common Common Functions (8.3)
 *
 * These all operate component-wise. The description is per component.
 *
 * \{
 */

/// Returns x if x >= 0, otherwise it returns -x.
GLCC_COMPONENT_WISE(GLfloat, abs, (GLfloat, x))
{
	return std::fabs(x);
}

GLCC_COMPONENT_WISE(GLint, abs, (GLint, x))
{
	return std::abs(x);
}

/// Returns 1.0 if x > 0, 0.0 if x = 0, or –1.0 if x < 0.
GLCC_COMPONENT_WISE(GLfloat, sign, (GLfloat, x))
{
	return (x == 0.f) ? 0.f : (x < 0.f) ? -1.f : 1.f;
}

GLCC_COMPONENT_WISE(GLint, sign, (GLint, x))
{
	return (x == 0) ? 0 : (x < 0) ? -1 : 1;
}

/// Returns a value equal to the nearest integer that is less
/// than or equal to x.
GLCC_COMPONENT_WISE(GLfloat, floor, (GLfloat, x))
{
	return std::floor(x);
}

/// Returns a value equal to the nearest integer to x whose
/// absolute value is not larger than the absolute value of x.
GLCC_COMPONENT_WISE(GLfloat, trunc, (GLfloat, x)); //TODO

GLCC_COMPONENT_WISE(GLfloat, round, (GLfloat, x)); //TODO

/// Returns a value equal to the nearest integer to x. A
/// fractional part of 0.5 will round toward the nearest even
/// integer. (Both 3.5 and 4.5 for x will return 4.0.)
GLCC_COMPONENT_WISE(GLfloat, roundEven, (GLfloat, x)); //TODO

/// Returns a value equal to the nearest integer that is
/// greater than or equal to x.
GLCC_COMPONENT_WISE(GLfloat, ceil, (GLfloat, x))
{
	return std::ceil(x);
}

/// Returns x - floor (x).
GLCC_COMPONENT_WISE(GLfloat, fract, (GLfloat, x))
{
	return x - std::floor(x);
}

/// Modulus. Returns x - y * floor(x / y).
//TODO: genType mod (genType x, GLfloat y);

GLCC_COMPONENT_WISE(GLfloat, mod, (GLfloat, x)(GLfloat, y))
{
	return x - y * floor(x / y);
}

/// Returns the fractional part of x and sets i to the integer
/// part (as a whole number floating point value). Both the
/// return value and the output parameter will have the same
/// sign as x.
GLCC_COMPONENT_WISE(GLfloat, modf, (GLfloat, x)(GLfloat&, i))
{
	return std::modf(x, &i);
}

/// Returns y if y < x, otherwise it returns x.
GLCC_COMPONENT_WISE(GLfloat, min, (GLfloat, x)(GLfloat, y))
{
	return std::min(x, y);
}

//TODO: genType min (genType x, GLfloat y);

GLCC_COMPONENT_WISE(GLint, min, (GLint, x)(GLint, y))
{
	return std::min(x, y);
}

//TODO: genIType min (genIType x, GLint y);

GLCC_COMPONENT_WISE(GLuint, min, (GLuint, x)(GLuint, y))
{
	return std::min(x, y);
}

//TODO: genUType min (genUType x, GLuint y);

// Returns y if x < y, otherwise it returns x.
GLCC_COMPONENT_WISE(GLfloat, max, (GLfloat, x)(GLfloat, y))
{
	return std::max(x, y);
}

//TODO: genType max (genType x, float y);

GLCC_COMPONENT_WISE(GLint, max, (GLint, x)(GLint, y))
{
	return std::max(x, y);
}

//TODO: genIType max (genIType x, int y);

GLCC_COMPONENT_WISE(GLuint, max, (GLuint, x)(GLuint, y))
{
	return std::max(x, y);
}

//TODO: genUType max (genUType x, uint y);

/// Returns min (max (x, minVal), maxVal).
/// Results are undefined if minVal > maxVal.
GLCC_COMPONENT_WISE(GLfloat, clamp, (GLfloat, x)(GLfloat, minVal)(GLfloat, maxVal))
{
	return std::min(std::max(x, minVal), maxVal);
}

//TODO: genType clamp(genType x, float minVal, float maxVal);

GLCC_COMPONENT_WISE(GLint, clamp, (GLint, x)(GLint, minVal)(GLint, maxVal))
{
	return std::min(std::max(x, minVal), maxVal);
}

//TODO: genIType clamp(genIType x, GLint minVal, GLint maxVal);

GLCC_COMPONENT_WISE(GLuint, clamp, (GLuint, x)(GLuint, minVal)(GLuint, maxVal))
{
	return std::min(std::max(x, minVal), maxVal);
}

//TODO: genUType clamp(genUType x, GLuint minVal, GLuint maxVal);

/// Returns the linear blend of x and y.
GLCC_COMPONENT_WISE(GLfloat, mix, (GLfloat, x)(GLfloat, y)(GLfloat, a))
{
	return x * (1 - a) + y * a;
}

//TODO: genType mix(genType x, genType y, GLfloat a);

GLCC_COMPONENT_WISE(GLfloat, mix, (GLfloat, x)(GLfloat, y)(GLboolean, a))
{
	return a ? x : y;
}

/// Returns 0.0 if x < edge, otherwise it returns 1.0.
GLCC_COMPONENT_WISE(GLfloat, step, (GLfloat, edge)(GLfloat, x))
{
	return (x < edge) ? 0.f : 1.f;
}

//TODO: genType step(GLfloat edge, genType x);

GLCC_COMPONENT_WISE(GLfloat, smoothstep, (GLfloat, edge0)(GLfloat, edge1)(GLfloat, x))
{
	GLfloat t = clamp((x - edge0) / (edge1 - edge0), 0.f, 1.f);
	return t * t * (3 - 2 * t);
}

//TODO: genType smoothstep(GLfloat edge0, GLfloat edge1, genType x);

/// Returns true if x holds a NaN (not a number) representation.
GLCC_COMPONENT_WISE(GLboolean, isnan, (GLfloat, x))
{
	return std::isnan(x);
}

/// Returns true if x holds an infinity representation.
GLCC_COMPONENT_WISE(GLboolean, isinf, (GLfloat, x))
{
	return std::isinf(x);
}

/**
 * \}
 */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_COMMON_HPP */
