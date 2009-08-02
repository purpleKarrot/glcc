/*
 * vector.hpp
 *
 *  Created on: Jun 6, 2009
 *      Author: daniel
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

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


#endif /* VECTOR_HPP_ */
