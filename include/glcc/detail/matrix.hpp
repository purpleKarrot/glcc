/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_TYPES_MATRIX_HPP
#define GLCC_MATH_TYPES_MATRIX_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/helper.hpp>
#include <boost/utility/enable_if.hpp>

namespace gl
{
namespace detail
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
		detail::loop_op<Size>::eval(detail::plus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizensubtraktion
	matrix& operator-=(const matrix& other)
	{
		detail::loop_op<Size>::eval(detail::minus_assign(), elems, other.elems);
		return *this;
	}

	/// Matrizenmultiplikation
	template<std::size_t S>
	typename boost::enable_if_c<M == S && N == S, matrix&>::type //
	operator*=(const matrix<T, S, S>& other)
	{
		//		Matrix<T> temp(*this);
		//		set_product(temp, other);
		return *this;
	}

	/// Skalarmultiplikation
	matrix& operator*=(T skalar)
	{
		detail::loop_op<Size>::eval(detail::multiplies_assign(), elems, skalar);
		return *this;
	}

	/// Skalardivision
	matrix& operator/=(T skalar)
	{
		detail::loop_op<Size>::eval(detail::divides_assign(), elems, skalar);
		return *this;
	}

	typename vector<T, Rows>::type operator[](std::size_t idx) const
	{
		return get_col<Rows> ();
	}

	typename vector<T&, Rows>::type operator[](std::size_t idx)
	{
		return get_col<Rows> ();
	}

	//	boost::enable_if_c<Rows == 2, vector2_ref_t>::type //
	//	operator[](std::size_t idx)
	//	{
	//		vector2_ref_t(0, 0);
	//	}

	//private:
	T elems[Size];

private:

	template<std::size_t S>
	typename boost::enable_if_c<S == 2, vector2<T> >::type //
	get_col(std::size_t idx) const
	{
	}

	template<std::size_t S>
	typename boost::enable_if_c<S == 3, vector3<T> >::type //
	get_col(std::size_t idx) const
	{
	}

	template<std::size_t S>
	typename boost::enable_if_c<S == 4, vector4<T> >::type //
	get_col(std::size_t idx) const
	{
	}

	template<std::size_t S>
	typename boost::enable_if_c<S == 2, vector2<T&> >::type //
	get_col(std::size_t idx)
	{
	}

	template<std::size_t S>
	typename boost::enable_if_c<S == 3, vector3<T&> >::type //
	get_col(std::size_t idx)
	{
	}

	template<std::size_t S>
	typename boost::enable_if_c<S == 4, vector4<T&> >::type //
	get_col(std::size_t idx)
	{
	}
};

} // namespace detail
} // namespace gl

#endif /* GLCC_MATH_TYPES_MATRIX_HPP */
