/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_MATRIX_HPP
#define GLCC_DETAIL_MATRIX_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/helper.hpp>

namespace gl
{
namespace detail
{

template<typename T, std::size_t M, std::size_t N>
class matrix: private boost::array<gl::detail::vector<T, M>, N>
{
	typedef typename boost::array<gl::detail::vector<T, M>, N> super;
	typedef typename gl::detail::vector<T, M> vector_t;

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

	//	matrix(const matrix& other) :
	//		elems(other.elems)
	//	{
	//	}

	using super::operator[];

	using super::operator=;

	/// Matrizenaddition
	matrix& operator+=(const matrix& other)
	{
		loop_op<N>::eval(plus_assign(), super::begin(), other.begin());
		return *this;
	}

	/// Matrizensubtraktion
	matrix& operator-=(const matrix& other)
	{
		loop_op<N>::eval(minus_assign(), super::begin(), other.begin());
		return *this;
	}

	/// Matrizenmultiplikation
	//	template<std::size_t S>
	//	typename boost::enable_if_c<M == S && N == S, matrix&>::type //
	//	operator*=(const matrix<T, S, S>& other)
	//	{
	//		//		Matrix<T> temp(*this);
	//		//		set_product(temp, other);
	//		return *this;
	//	}

	/// Skalarmultiplikation
	matrix& operator*=(T skalar)
	{
		loop_op<M * N>::eval(multiplies_assign(), //
		        reinterpret_cast<T*> (this), skalar);
		return *this;
	}

	/// Skalardivision
	matrix& operator/=(T skalar)
	{
		loop_op<M * N>::eval(divides_assign(), //
		        reinterpret_cast<T*> (this), skalar);
		return *this;
	}

private:

	friend matrix operator+(const matrix& lhs, const matrix& rhs)
	{
		matrix nrv(lhs);
		nrv += rhs;
		return nrv;
	}

	friend matrix operator-(const matrix& lhs, const matrix& rhs)
	{
		matrix nrv(lhs);
		nrv -= rhs;
		return nrv;
	}

	friend matrix operator*(const matrix& lhs, T rhs)
	{
		matrix nrv(lhs);
		nrv *= rhs;
		return nrv;
	}

	friend matrix operator/(const matrix& lhs, T rhs)
	{
		matrix nrv(lhs);
		nrv /= rhs;
		return nrv;
	}

	friend std::ostream& operator<<(std::ostream&os, const matrix& rhs)
	{
		os << "[\n";
		std::copy(rhs.begin(), rhs.end(), //
		        std::ostream_iterator<vector_t>(os, "\n"));
		return os << "]";
	}
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_MATRIX_HPP */
