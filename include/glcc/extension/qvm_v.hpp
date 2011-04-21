/*
 * qvm_v.hpp
 *
 *  Created on: Apr 17, 2011
 *      Author: daniel
 */

#ifndef GLCC_EXTECSION_QVM_V_HPP
#define GLCC_EXTECSION_QVM_V_HPP

#include <glcc/vec.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace boost
{
namespace qvm
{

template<typename V>
struct v_traits;

template<typename T, int Dim>
struct v_traits<gl::detail::vec<T, Dim> >
{
	typedef gl::detail::vec<T, Dim> vector_type;
	typedef T scalar_type;

	static int const dim = Dim;

	template<int I>
	static scalar_type r(const vector_type& v)
	{
		BOOST_STATIC_ASSERT(I >= 0);
		BOOST_STATIC_ASSERT(I < Dim);

		return v.a[I];
	}

	template<int I>
	static scalar_type& w(vector_type& v)
	{
		BOOST_STATIC_ASSERT(I >= 0);
		BOOST_STATIC_ASSERT(I < Dim);

		return v.a[I];
	}

	static scalar_type ir(int i, const vector_type& v)
	{
		BOOST_ASSERT(i >= 0);
		BOOST_ASSERT(i < Dim);

		return v.a[i];
	}

	static scalar_type& iw(int i, vector_type& v)
	{
		BOOST_ASSERT(i >= 0);
		BOOST_ASSERT(i < Dim);

		return v.a[i];
	}
};

} // namespace qvm
} // namespace boost

#endif /* GLCC_EXTECSION_QVM_V_HPP */
