/*
 * vector.hpp
 *
 *  Created on: 28.02.2009
 *      Author: daniel
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <boost/array.hpp>
#include <boost/assert.hpp>
#include <boost/operators.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/min_max.hpp>
#include <boost/mpl/size_t.hpp>
#include "detail/helper.hpp"

namespace geo
{

template<typename T, std::size_t N>
class vector: public boost::additive<vector<T, N> , boost::multiplicative<
		vector<T, N> , T> >
{
	enum
	{
		min_2 = boost::mpl::min<boost::mpl::size_t<2>,
				typename boost::mpl::size_t<N> >::type::value,
		min_3 = boost::mpl::min<boost::mpl::size_t<3>,
				typename boost::mpl::size_t<N> >::type::value,
		min_4 = boost::mpl::min<boost::mpl::size_t<4>,
				typename boost::mpl::size_t<N> >::type::value
	};

public:
	vector()
	{
	}

	~vector()
	{
	}

	vector(const T a)
	{
		loop_op<N>::eval(assign(), this->elems, a);
	}

	vector(const T x, const T y)
	{
		BOOST_STATIC_ASSERT(N == 2);
		this->elems[0] = x;
		this->elems[1] = y;
	}

	vector(const T x, const T y, const T z)
	{
		BOOST_STATIC_ASSERT(N == 3);
		this->elems[0] = x;
		this->elems[1] = y;
		this->elems[2] = z;
	}

	vector(const T x, const T y, const T z, const T w)
	{
		BOOST_STATIC_ASSERT(N == 4);
		this->elems[0] = x;
		this->elems[1] = y;
		this->elems[2] = z;
		this->elems[3] = w;
	}

	T& operator[](std::size_t i)
	{
		BOOST_ASSERT( i < N && "out of range" );
		return elems[i];
	}

	const T& operator[](std::size_t i) const
	{
		BOOST_ASSERT( i < N && "out of range" );
		return elems[i];
	}

	vector(const vector<T, 2>& xy)
	{
		loop_op<min_2>::eval(assign(), this->elems, xy.elems);
	}

	vector(const vector<T, 3>& xyz)
	{
		loop_op<min_3>::eval(assign(), this->elems, xyz.elems);
	}

	vector(const vector<T, 4>& xyzw)
	{
		loop_op<min_4>::eval(assign(), this->elems, xyzw.elems);
	}

	vector& operator=(const vector& other)
	{
		loop_op<N>::eval(assign(), this->elems, other.elems);
		return *this;
	}

	vector& operator+=(const vector& other)
	{
		loop_op<N>::eval(plus_assign(), this->elems, other.elems);
		return *this;
	}

	vector& operator-=(const vector& other)
	{
		loop_op<N>::eval(minus_assign(), this->elems, other.elems);
		return *this;
	}

	vector& operator*=(T skalar)
	{
		loop_op<N>::eval(multiplies_assign(), this->elems, skalar);
		return *this;
	}

	vector& operator/=(T skalar)
	{
		loop_op<N>::eval(divides_assign(), this->elems, skalar);
		return *this;
	}

	T x() const
	{
		this->elems[0];
	}

	T& x()
	{
		this->elems[0];
	}

private:
	T elems[N];
};

} // namespace geo

#endif /* VECTOR_HPP_ */
