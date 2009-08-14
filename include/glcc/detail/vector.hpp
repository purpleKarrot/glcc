/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_HPP
#define GLCC_DETAIL_VECTOR_HPP

#include <boost/array.hpp>
#include <glcc/detail/helper.hpp>

namespace gl
{
namespace detail
{

template<typename T, std::size_t N>
class vector: private boost::array<T, N>
{
	typedef typename boost::array<T, N> super;

public:

	using super::operator[];

	using super::operator=;

	vector& operator+=(const vector& other)
	{
		loop_op<N>::eval(plus_assign(), super::begin(), other.begin());
		return *this;
	}

	vector& operator-=(const vector& other)
	{
		loop_op<N>::eval(minus_assign(), super::begin(), other.begin());
		return *this;
	}

	vector& operator*=(T skalar)
	{
		loop_op<N>::eval(multiplies_assign(), super::begin(), skalar);
		return *this;
	}

	vector& operator/=(T skalar)
	{
		loop_op<N>::eval(divides_assign(), super::begin(), skalar);
		return *this;
	}

private:

	friend vector operator+(const vector& lhs, const vector& rhs)
	{
		vector nrv(lhs);
		nrv += rhs;
		return nrv;
	}

	friend vector operator-(const vector& lhs, const vector& rhs)
	{
		vector nrv(lhs);
		nrv -= rhs;
		return nrv;
	}

	friend vector operator*(const vector& lhs, T rhs)
	{
		vector nrv(lhs);
		nrv *= rhs;
		return nrv;
	}

	friend vector operator/(const vector& lhs, T rhs)
	{
		vector nrv(lhs);
		nrv /= rhs;
		return nrv;
	}

	friend std::ostream& operator<<(std::ostream&os, const vector& rhs)
	{
		os << "( ";
		std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T>(os, " "));
		return os << ")";
	}
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_HPP */
