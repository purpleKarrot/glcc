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
bvec lessThan(vec x, vec y);
bvec lessThan(ivec x, ivec y);
bvec lessThan(uvec x, uvec y);

//! Returns the component-wise compare of x <= y.
bvec lessThanEqual(vec x, vec y);
bvec lessThanEqual(ivec x, ivec y);
bvec lessThanEqual(uvec x, uvec y);

//! Returns the component-wise compare of x > y.
bvec greaterThan(vec x, vec y);
bvec greaterThan(ivec x, ivec y);
bvec greaterThan(uvec x, uvec y);

//! Returns the component-wise compare of x >= y.
bvec greaterThanEqual(vec x, vec y);
bvec greaterThanEqual(ivec x, ivec y);
bvec greaterThanEqual(uvec x, uvec y);

//! Returns the component-wise compare of x == y.
bvec equal(vec x, vec y);
bvec equal(ivec x, ivec y);
bvec equal(uvec x, uvec y);
bvec equal(bvec x, bvec y);

//! Returns the component-wise compare of x != y.
bvec notEqual(vec x, vec y);
bvec notEqual(ivec x, ivec y);
bvec notEqual(uvec x, uvec y);
bvec notEqual(bvec x, bvec y);

//! Returns true if any component of x is true.
bool any(bvec2 x);

//! Returns true only if all components of x are true.
bool all(bvec x);

//! Returns the component-wise logical complement of x.
bvec operator not(bvec x);

/** \} */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_VECTOR_HPP */
