/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_HPP
#define GLCC_DETAIL_VECTOR_HPP

#include <boost/la/vec_traits.hpp>
#include <boost/la/vector_assign.hpp>

namespace gl
{
namespace detail
{

template<typename T, std::size_t D>
class vector
{
public:
	template<class R>
	operator R() const
	{
		R r;
		boost::la::assign(r, *this);
		return r;
	}

public:
	T operator[](std::size_t i) const
	{
		return data[i];
	}

	T& operator[](std::size_t i)
	{
		return data[i];
	}

private:
	T data[D];
};

} // namespace detail
} // namespace gl


namespace boost
{
namespace la
{

template<typename T, std::size_t D>
struct vector_traits<gl::detail::vector<T, D> >
{
	typedef gl::detail::vector<T, D> this_vector;
	typedef T scalar_type;
	static int const dim = D;

	template<int I>
	static BOOST_LA_INLINE_CRITICAL scalar_type r(this_vector const& x)
	{
		BOOST_STATIC_ASSERT(I>=0);
		BOOST_STATIC_ASSERT(I<dim);
		return x[I];
	}

	template<int I>
	static BOOST_LA_INLINE_CRITICAL scalar_type& w(this_vector& x)
	{
		BOOST_STATIC_ASSERT(I>=0);
		BOOST_STATIC_ASSERT(I<dim);
		return x[I];
	}

	static BOOST_LA_INLINE_CRITICAL scalar_type ir(int i, this_vector const& x)
	{
		BOOST_ASSERT(i>=0);
		BOOST_ASSERT(i<dim);
		return x[i];
	}

	static BOOST_LA_INLINE_CRITICAL scalar_type& iw(int i, this_vector& x)
	{
		BOOST_ASSERT(i>=0);
		BOOST_ASSERT(i<dim);
		return x[i];
	}
};

} // namespace la
} // namespace boost

#endif /* GLCC_DETAIL_VECTOR_HPP */
