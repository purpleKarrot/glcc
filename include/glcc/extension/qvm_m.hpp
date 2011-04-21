/*
 * qvm_m.hpp
 *
 *  Created on: Apr 17, 2011
 *      Author: daniel
 */

#ifndef GLCC_EXTECSION_QVM_M_HPP
#define GLCC_EXTECSION_QVM_M_HPP

#include <glcc/mat.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace boost
{
namespace qvm
{

template<typename M>
struct m_traits;

template<typename T, int Cols, int Rows>
struct m_traits<gl::detail::mat<T, Cols, Rows> >
{
	typedef gl::detail::mat<T, Cols, Rows> matrix_type;
	typedef T scalar_type;

	static int const rows = Rows;
	static int const cols = Cols;

	template<int Row, int Col>
	static scalar_type r(const matrix_type& m)
	{
		BOOST_STATIC_ASSERT(Row >= 0);
		BOOST_STATIC_ASSERT(Row < Rows);
		BOOST_STATIC_ASSERT(Col >= 0);
		BOOST_STATIC_ASSERT(Col < Cols);

		return m.a[Col][Row];
	}

	template<int Row, int Col>
	static scalar_type& w(matrix_type& m)
	{
		BOOST_STATIC_ASSERT(Row >= 0);
		BOOST_STATIC_ASSERT(Row < Rows);
		BOOST_STATIC_ASSERT(Col >= 0);
		BOOST_STATIC_ASSERT(Col < Cols);

		return m.a[Col][Row];
	}

	static scalar_type ir(int row, int col, const matrix_type& m)
	{
		BOOST_ASSERT(row >= 0);
		BOOST_ASSERT(row < Rows);
		BOOST_ASSERT(col >= 0);
		BOOST_ASSERT(col < Cols);

		return m.a[col][row];
	}

	static scalar_type& iw(int row, int col, matrix_type& m)
	{
		BOOST_ASSERT(row >= 0);
		BOOST_ASSERT(row < Rows);
		BOOST_ASSERT(col >= 0);
		BOOST_ASSERT(col < Cols);

		return m.a[col][row];
	}
};

} // namespace qvm
} // namespace boost

#endif /* GLCC_EXTECSION_QVM_M_HPP */
