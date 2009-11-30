//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_FA3ED0DCA17911DEA6BBA09955D89593
#define UUID_FA3ED0DCA17911DEA6BBA09955D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/la/scalar.hpp>
#include <boost/la/detail/remove_const.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class T,int Rows,int Cols>
		struct
		matrix_traits<T[Rows][Cols]>
			{
			typedef T this_matrix[Rows][Cols];
			typedef typename la_detail::remove_const<T>::type scalar_type;
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
				return x[Row][Col];
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
				return x[Row][Col];
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
				return x[row][col];
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
				return x[row][col];
				}
			};

		template <class T,int Rows,int Cols,int R,int C,class S>
		struct
		deduce_matrix<T[Rows][Cols],R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		template <class T1,class T2,int Rows,int Cols,int R,int C>
		struct
		deduce_matrix2<T1[Rows][Cols],T2[Rows][Cols],R,C>
			{
			typedef mat<typename deduce_scalar<T1,T2>::type,R,C> type;
			};
		}
	}

#endif
