//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_0ABE4A38A30911DEAB79DFF855D89593
#define UUID_0ABE4A38A30911DEAB79DFF855D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class T>
			class
			mref_
				{
				mref_( mref_ const & );
				mref_ & operator=( mref_ const & );
				~mref_();

				public:

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				mref_ &
				operator=( R const & x )
					{
					assign(*this,x);
					return *this;
					}

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				operator R() const
					{
					R r;
					assign(r,*this);
					return r;
					}
				};
			}

		template <class Matrix>
		struct
		matrix_traits< la_detail::mref_<Matrix> >
			{
			typedef typename matrix_traits<Matrix>::scalar_type scalar_type;
			typedef la_detail::mref_<Matrix> this_matrix;
			static int const rows=matrix_traits<Matrix>::rows;
			static int const cols=matrix_traits<Matrix>::cols;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return matrix_traits<Matrix>::template r<Row,Col>(reinterpret_cast<Matrix const &>(x));
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return matrix_traits<Matrix>::template w<Row,Col>(reinterpret_cast<Matrix &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return matrix_traits<Matrix>::ir(row,col,reinterpret_cast<Matrix const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return matrix_traits<Matrix>::iw(row,col,reinterpret_cast<Matrix &>(x));
				}
			};

		template <class Matrix,int R,int C,class S>
		struct
		deduce_matrix<la_detail::mref_<Matrix>,R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		template <class Matrix>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_matrix<Matrix>::value,
			la_detail::mref_<Matrix> const &>::type
		mref( Matrix const & a )
			{
			return reinterpret_cast<la_detail::mref_<Matrix> const &>(a);
			}

		template <class Matrix>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_matrix<Matrix>::value,
			la_detail::mref_<Matrix> &>::type
		mref( Matrix & a )
			{
			return reinterpret_cast<la_detail::mref_<Matrix> &>(a);
			}
		}
	}

#endif
