/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_TYPES_MATRIX_HPP
#define GLCC_MATH_TYPES_MATRIX_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/helper.hpp>

namespace gl
{
namespace math
{

template<typename T, std::size_t M, std::size_t N>
class matrix //: public boost::additive<matrix<T, M, N> , //
// boost::multiplicative<matrix<T, M, N> , T> >
{
	enum
	{
		Rows = M, Cols = N, Size = M * N
	};

public:
	matrix()
	{
	}

	~matrix()
	{
	}

	matrix(T a)
	{
	}

	matrix(const matrix& other) :
		elems(other.elems)
	{
	}

	/// Matrizenaddition
	matrix& operator+=(const matrix& other)
	{
		geo::loop_op<Size>::eval(geo::plus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizensubtraktion
	matrix& operator-=(const matrix& other)
	{
		geo::loop_op<Size>::eval(geo::minus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizenmultiplikation
	matrix& operator*=(const matrix& other)
	{
		//		Matrix<T> temp(*this);
		//		set_product(temp, other);
		return *this;
	}

	/// Skalarmultiplikation
	matrix& operator*=(T skalar)
	{
		geo::loop_op<Size>::eval(geo::multiplies_assign(), elems, skalar);
		return *this;
	}

	/// Skalardivision
	matrix& operator/=(T skalar)
	{
		geo::loop_op<Size>::eval(geo::divides_assign(), elems, skalar);
		return *this;
	}

//	boost::enable_if_c<Rows == 2, vector2_ref_t>::type //
//	operator[](std::size_t idx)
//	{
//		vector2_ref_t(0, 0);
//	}

	//private:
	T elems[Size];
};

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_TYPES_MATRIX_HPP */
