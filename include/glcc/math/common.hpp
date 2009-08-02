/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_COMMON_HPP
#define GLCC_MATH_COMMON_HPP

#include <cmath>
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

GLCC_COMPONENT_WISE(GLfloat, abs, x)
{
	return std::fabs(x);
}

GLCC_COMPONENT_WISE(GLint, abs, x)
{
	return std::abs(x);
}

genType sign(genType x);
genIType sign(genIType x);

genType floor(genType x); //std::floor

genType trunc(genType x);

genType round(genType x);

genType roundEven(genType x);

genType ceil(genType x); //std::ceil

genType fract(genType x);

genType mod(genType x, float y);
genType mod(genType x, genType y);

genType modf(genType x, genType i); //std::modf

genType min(genType x, genType y); //std::min
genType min(genType x, float y);
genIType min(genIType x, genIType y);
genIType min(genIType x, int y);
genUType min(genUType x, genUType y);
genUType min(genUType x, uint y);

genType max(genType x, genType y); //std::max
genType max(genType x, float y);
genIType max(genIType x, genIType y);
genIType max(genIType x, int y);
genUType max(genUType x, genUType y);
genUType max(genUType x, uint y);

genType clamp(genType x, genType minVal, genType maxVal);
genType clamp(genType x, float minVal, float maxVal);
genIType clamp(genIType x, genIType minVal, genIType maxVal);
genIType clamp(genIType x, int minVal, int maxVal);
genUType clamp(genUType x, genUType minVal, genUType maxVal);
genUType clamp(genUType x, uint minVal, uint maxVal);

genType mix(genType x, genType y, genType a);
genType mix(genType x, genType y, float a);
genType mix(genType x, genType y, bvec a);

genType step(genType edge, genType x);
genType step(float edge, genType x);

genType smoothstep(genType edge0, genType edge1, genType x);
genType smoothstep(float edge0, float edge1, genType x);

bvec isnan(genType x); //std::isnan

bvec isinf(genType x); //std::isinf

/**
 * \}
 */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_COMMON_HPP */
