//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_9A7B4598AFBD11DE83607A9A55D89593
#define UUID_9A7B4598AFBD11DE83607A9A55D89593

#include <boost/la/config.hpp>
#include <boost/la/mat.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class Matrix>
		struct matrix_traits;

		template <class T,int Rows,int Cols>
		struct
		matrix_traits< mat<T,Rows,Cols> >
			{
			typedef mat<T,Rows,Cols> this_matrix;
			typedef T scalar_type;
			static int const rows=Rows;
			static int const cols=Cols;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<Rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<Cols);
				return x.a[Row][Col];
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<Rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<Cols);
				return x.a[Row][Col];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<Rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<Cols);
				return x.a[row][col];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<Rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<Cols);
				return x.a[row][col];
				}
			};
		}
	}

#endif
