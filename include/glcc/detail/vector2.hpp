/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_2_HPP
#define GLCC_DETAIL_VECTOR_2_HPP

#include <boost/assert.hpp>
//#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
//#include <boost/type_traits/is_same.hpp>
//#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector2
{
	typedef vector2<typename boost::add_reference<T>::type> vector2_ref_t;
	typedef vector2<typename boost::remove_reference<T>::type> vector2_nref_t;

	//	template<typename U>
	//	struct refonly: boost::mpl::and_<boost::is_reference<T>, //
	//	        boost::is_same<boost::remove_reference<T>, U> >::type
	//	{
	//	};
	//
	//	template<typename U>
	//	struct enable_ref: boost::enable_if<refonly<U> >
	//	{
	//	};
	//
	//	template<typename U>
	//	struct disable_ref: boost::disable_if<refonly<U> >
	//	{
	//	};

public:
	vector2()
	{
	}

	vector2(T val) :
		x_(val), y_(val)
	{
	}

	vector2(T x, T y) :
		x_(x), y_(y)
	{
	}

	//typename boost::enable_if<boost::is_reference<T> >::type* dummy = 0
	vector2(vector2<typename boost::remove_reference<T>::type>& other) :
		x_(other.x()), y_(other.y())
	{
	}

	template<typename U>
	vector2(const vector2<U>& other) :
		x_(other.x()), y_(other.y())
	{
	}

	template<typename U>
	vector2& operator=(const vector2<U>& other)
	{
		x_ = other.x();
		y_ = other.y();
		return *this;
	}

	template<typename U>
	vector2& operator+=(const vector2<U>& other)
	{
		x_ += other.x();
		y_ += other.y();
		return *this;
	}

	template<typename U>
	vector2& operator-=(const vector2<U>& other)
	{
		x_ -= other.x();
		y_ -= other.y();
		return *this;
	}

	template<typename U>
	vector2& operator*=(U skalar)
	{
		x_ *= skalar;
		y_ *= skalar;
		return *this;
	}

	template<typename U>
	vector2& operator/=(U skalar)
	{
		x_ /= skalar;
		y_ /= skalar;
		return *this;
	}

	typename boost::add_reference<T>::type x()
	{
		return x_;
	}

	typename boost::add_reference<T>::type y()
	{
		return y_;
	}

	typename boost::remove_reference<T>::type x() const
	{
		return x_;
	}

	typename boost::remove_reference<T>::type y() const
	{
		return y_;
	}

	typename boost::add_reference<T>::type operator[](std::size_t idx)
	{
		BOOST_ASSERT(idx < 2);
		return (idx == 0) ? x_ : y_;
	}

	typename boost::remove_reference<T>::type operator[](std::size_t idx) const
	{
		BOOST_ASSERT(idx < 2);
		return (idx == 0) ? x_ : y_;
	}

	vector2_ref_t xy()
	{
		return vector2_ref_t(x(), y());
	}

	vector2_ref_t yx()
	{
		return vector2_ref_t(y(), x());
	}

	vector2_nref_t xy() const
	{
		return vector2_nref_t(x(), y());
	}

	vector2_nref_t yx() const
	{
		return vector2_nref_t(y(), x());
	}

private:
	T x_;
	T y_;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_2_HPP */
