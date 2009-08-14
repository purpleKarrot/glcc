/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_ELEMENT_HPP
#define GLCC_DETAIL_VECTOR_ELEMENT_HPP

#define GLCC_VECTOR_ELEMENT(NAME, INDEX)      \
          T& NAME()       { (*this)[INDEX]; } \
    const T& NAME() const { (*this)[INDEX]; }

#define GLCC_SWIZZLE_2(X, Y)        \
	vector<T, 2> X##Y() const       \
	{                               \
		vector<T, 2> v;             \
		v[0] = X();                 \
		v[1] = Y();                 \
		return v;                   \
	}

#define GLCC_SWIZZLE_3(X, Y, Z)     \
	vector<T, 3> X##Y##Z() const    \
	{                               \
		vector<T, 3> v;             \
		v[0] = X();                 \
		v[1] = Y();                 \
		v[2] = Z();                 \
		return v;                   \
	}

#define GLCC_SWIZZLE_4(X, Y, Z, W)  \
	vector<T, 4> X##Y##Z##W() const \
	{                               \
		vector<T, 4> v;             \
		v[0] = X();                 \
		v[1] = Y();                 \
		v[2] = Z();                 \
		v[3] = W();                 \
		return v;                   \
	}

#endif /* GLCC_DETAIL_VECTOR_ELEMENT_HPP */
