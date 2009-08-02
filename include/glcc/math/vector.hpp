/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_VECTOR_HPP
#define GLCC_MATH_VECTOR_HPP

namespace gl
{
namespace math
{

/**
 * \defgroup vector Vector Relational Functions (8.6)
 *
 * Relational and equality operators (<, <=, >, >=, ==, !=)
 * are defined to produce scalar Boolean results.
 * For vector results, use the following functions.
 *
 * \{
 */

//! Returns the component-wise compare of x < y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, lessThan, (T, x)(T, y))
{
	return x < y;
}

//! Returns the component-wise compare of x <= y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, lessThanEqual, (T, x)(T, y))
{
	return x <= y;
}

//! Returns the component-wise compare of x > y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, greaterThan, (T, x)(T, y))
{
	return x > y;
}

//! Returns the component-wise compare of x >= y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, greaterThanEqual, (T, x)(T, y))
{
	return x >= y;
}

//! Returns the component-wise compare of x == y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, equal, (T, x)(T, y))
{
	return x == y;
}

//! Returns the component-wise compare of x != y.
GLCC_COMPONENT_WISE(template<typename T>,
		GLboolean, notEqual, (T, x)(T, y))
{
	return x != y;
}

//! Returns true if any component of x is true.
inline bool any(const bvec2& x)
{
	return x.x() || x.y();
}

inline bool any(const bvec3& x)
{
	return x.x() || x.y() || x.z();
}

inline bool any(const bvec4& x)
{
	return x.x() || x.y() || x.z() || x.w();
}

//! Returns true only if all components of x are true.
inline bool all(const bvec2& x)
{
	return x.x() && x.y();
}

inline bool all(const bvec3& x)
{
	return x.x() && x.y() && x.z();
}

inline bool all(const bvec4& x)
{
	return x.x() && x.y() && x.z() && x.w();
}

//! Returns the component-wise logical complement of x.
GLCC_COMPONENT_WISE(, GLboolean, not_, (GLboolean, x))
{
	return x == GL_FALSE;
}

/** \} */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_VECTOR_HPP */
