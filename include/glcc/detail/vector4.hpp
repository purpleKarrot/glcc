/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_4_HPP
#define GLCC_DETAIL_VECTOR_4_HPP

namespace gl
{
namespace detail
{

template<typename T>
class vector4
{
public:
	vector4()
	{
	}

	vector4(T x, T y, T z, T w) :
		x_(x), y_(y), z_(z), w_(w)
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

	typename boost::add_reference<T>::type w()
	{
		return w_;
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

	typename boost::remove_reference<T>::type w() const
	{
		return w_;
	}

private:
	T x_;
	T y_;
	T z_;
	T w_;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_4_HPP */
