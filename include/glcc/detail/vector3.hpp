/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_3_HPP
#define GLCC_DETAIL_VECTOR_3_HPP

namespace gl
{
namespace detail
{

template<typename T>
class vector3
{
public:
	vector3()
	{
	}

	vector3(T x, T y, T z) :
		x_(x), y_(y), z_(z)
	{
	}

	typename boost::add_reference<T>::type x()
	{
		return x_;
	}

	typename boost::add_reference<T>::type y()
	{
		return y_;
	}

	typename boost::add_reference<T>::type z()
	{
		return z_;
	}

	typename boost::remove_reference<T>::type x() const
	{
		return x_;
	}

	typename boost::remove_reference<T>::type y() const
	{
		return y_;
	}

	typename boost::remove_reference<T>::type z() const
	{
		return z_;
	}

private:
	T x_;
	T y_;
	T z_;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_3_HPP */
