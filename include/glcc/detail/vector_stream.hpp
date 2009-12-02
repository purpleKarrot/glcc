/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_STREAM_HPP
#define GLCC_DETAIL_VECTOR_STREAM_HPP

#include <glcc/detail/vector.hpp>

namespace gl
{
namespace detail
{

template<typename T>
inline std::ostream& operator<<(std::ostream&os,
		const gl::detail::vector<T, 2>& v)
{
	typedef typename gl::detail::vector<T, 2> this_vector;
	typedef boost::la::vector_traits<this_vector> vector_traits;

	return os << "( "//
			<< vector_traits::template r<0>(v) << " "
			<< vector_traits::template r<1>(v) << " )";
}

template<typename T>
inline std::ostream& operator<<(std::ostream&os,
		const gl::detail::vector<T, 3>& v)
{
	typedef typename gl::detail::vector<T, 3> this_vector;
	typedef boost::la::vector_traits<this_vector> vector_traits;

	return os << "( "//
			<< vector_traits::template r<0>(v) << " "
			<< vector_traits::template r<1>(v) << " "
			<< vector_traits::template r<2>(v) << " )";
}

template<typename T>
inline std::ostream& operator<<(std::ostream&os,
		const gl::detail::vector<T, 4>& v)
{
	typedef typename gl::detail::vector<T, 4> this_vector;
	typedef boost::la::vector_traits<this_vector> vector_traits;

	return os << "( "//
			<< vector_traits::template r<0>(v) << " "
			<< vector_traits::template r<1>(v) << " "
			<< vector_traits::template r<2>(v) << " "
			<< vector_traits::template r<3>(v) << " )";
}

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_STREAM_HPP */
