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
#include <glcc/math/detail/component_wise.hpp>

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

GLCC_COMPONENT_WISE(, GLfloat, abs, (GLfloat, x))
{
	return std::fabs(x);
}

GLCC_COMPONENT_WISE(, GLint, abs, (GLint, x))
{
	return std::abs(x);
}

GLCC_COMPONENT_WISE(, GLfloat, sign, (GLfloat, x))
{
	return x < 0.f ? -1.f : 1.f;
}

GLCC_COMPONENT_WISE(, GLint, sign, (GLint, x))
{
	return x < 0 ? -1 : 1;
}

GLCC_COMPONENT_WISE(, GLfloat, floor, (GLfloat, x))
{
	return std::floor(x);
}

GLCC_COMPONENT_WISE(, GLfloat, trunc, (GLfloat, x));

GLCC_COMPONENT_WISE(, GLfloat, round, (GLfloat, x));

GLCC_COMPONENT_WISE(, GLfloat, roundEven, (GLfloat, x));

GLCC_COMPONENT_WISE(, GLfloat, ceil, (GLfloat, x))
{
	return std::ceil(x);
}

GLCC_COMPONENT_WISE(, GLfloat, fract, (GLfloat, x));

GLCC_COMPONENT_WISE_2_M(template<typename T>, T, mod, T, x, T, y)
{
	return x % y;
}

genType modf(genType x, genType& i); //std::modf

GLCC_COMPONENT_WISE_2_M(template<typename T>, T, min, T, x, T, y)
{
	return std::min(x, y);
}

GLCC_COMPONENT_WISE_2_M(template<typename T>, T, max, T, x, T, y)
{
	return std::max(x, y);
}

genType clamp(genType x, genType minVal, genType maxVal);
genType clamp(genType x, float minVal, float maxVal);
genIType clamp(genIType x, genIType minVal, genIType maxVal);
genIType clamp(genIType x, int minVal, int maxVal);
genUType clamp(genUType x, genUType minVal, genUType maxVal);
genUType clamp(genUType x, uint minVal, uint maxVal);

genType mix(genType x, genType y, genType a);
genType mix(genType x, genType y, float a);

GLCC_COMPONENT_WISE(, GLfloat, mix, (GLfloat, x)(GLfloat, y)(GLboolean, a))
{
	return a ? x : y;
}

genType step(genType edge, genType x);
genType step(float edge, genType x);

genType smoothstep(genType edge0, genType edge1, genType x);
genType smoothstep(float edge0, float edge1, genType x);

GLCC_COMPONENT_WISE(, GLboolean, isnan, (GLfloat, x))
{
	return std::isnan(x);
}

GLCC_COMPONENT_WISE(, GLboolean, isinf, (GLfloat, x))
{
	return std::isinf(x);
}

/**
 * \}
 */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_COMMON_HPP */
