/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_MATRIX_HPP
#define GLCC_DETAIL_MATRIX_HPP

#include <boost/la/mat_traits.hpp>
#include <boost/la/matrix_assign.hpp>

namespace sl
{
namespace detail
{

template<typename T, std::size_t Cols, std::size_t Rows>
class matrix
{
public:
	matrix()
	{
	}

	~matrix()
	{
	}

private:

public:
	T data[Cols][Rows];
};

} // namespace detail
} // namespace sl

/*
 * OpenGL matrices are 16-value arrays with base vectors laid out
 * contiguously in memory. The translation components occupy the
 * 13th, 14th, and 15th elements of the 16-element matrix, where
 * indices are numbered from 1 to 16.
 */

namespace boost
{
namespace la
{

template<typename T, std::size_t Cols, std::size_t Rows>
struct matrix_traits<sl::detail::matrix<T, Cols, Rows> >
{
	typedef gl::detail::matrix<Cols, Rows> this_matrix;
	typedef T scalar_type;
	static std::size_t const cols = Cols;
	static std::size_t const rows = Rows;

	template<int Row, int Col>
	static BOOST_LA_INLINE_CRITICAL
	scalar_type r(this_matrix const& x)
	{
		BOOST_STATIC_ASSERT(Row>=0);
		BOOST_STATIC_ASSERT(Row<Rows);
		BOOST_STATIC_ASSERT(Col>=0);
		BOOST_STATIC_ASSERT(Col<Cols);
		return x.data[Col][Row];
	}

	template<int Row, int Col>
	static BOOST_LA_INLINE_CRITICAL
	scalar_type& w(this_matrix& x)
	{
		BOOST_STATIC_ASSERT(Row>=0);
		BOOST_STATIC_ASSERT(Row<Rows);
		BOOST_STATIC_ASSERT(Col>=0);
		BOOST_STATIC_ASSERT(Col<Cols);
		return x.data[Col][Row];
	}

	static BOOST_LA_INLINE_CRITICAL
	scalar_type ir(int row, int col, this_matrix const& x)
	{
		BOOST_ASSERT(row>=0);
		BOOST_ASSERT(row<Rows);
		BOOST_ASSERT(col>=0);
		BOOST_ASSERT(col<Cols);
		return x.data[col][row];
	}

	static BOOST_LA_INLINE_CRITICAL
	scalar_type& iw(int row, int col, this_matrix& x)
	{
		BOOST_ASSERT(row>=0);
		BOOST_ASSERT(row<Rows);
		BOOST_ASSERT(col>=0);
		BOOST_ASSERT(col<Cols);
		return x.data[col][row];
	}
};

} // namespace la
} // namespace boost

#endif /* GLCC_DETAIL_MATRIX_HPP */
