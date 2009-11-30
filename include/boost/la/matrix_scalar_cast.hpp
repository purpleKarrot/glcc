//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_2F8DF088B96C11DE95B095C955D89593
#define UUID_2F8DF088B96C11DE95B095C955D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/la/deduce_matrix.hpp>
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
			template <class OriginalType,class Scalar>
			class
			matrix_scalar_cast_
				{
				matrix_scalar_cast_( matrix_scalar_cast_ const & );
				matrix_scalar_cast_ & operator=( matrix_scalar_cast_ const & );
				~matrix_scalar_cast_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				matrix_scalar_cast_ &
				operator=( T const & x )
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

			template <bool> struct scalar_cast_matrix_filter { };
			template <> struct scalar_cast_matrix_filter<true> { typedef int type; };
			}

		template <class OriginalType,class Scalar>
		struct
		matrix_traits< la_detail::matrix_scalar_cast_<OriginalType,Scalar> >
			{
			typedef Scalar scalar_type;
			typedef la_detail::matrix_scalar_cast_<OriginalType,Scalar> this_matrix;
			static int const rows=matrix_traits<OriginalType>::rows;
			static int const cols=matrix_traits<OriginalType>::cols;

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
				return scalar_type(matrix_traits<OriginalType>::template r<Row,Col>(reinterpret_cast<OriginalType const &>(x)));
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
				return scalar_type(matrix_traits<OriginalType>::ir(col,row,reinterpret_cast<OriginalType const &>(x)));
				}
			};

		template <class OriginalType,class Scalar,int R,int C,class S>
		struct
		deduce_matrix<la_detail::matrix_scalar_cast_<OriginalType,Scalar>,R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		template <class Scalar,class T>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::matrix_scalar_cast_<T,Scalar> const &
		scalar_cast( T const & x, typename la_detail::scalar_cast_matrix_filter<is_matrix<T>::value>::type=0 )
			{
			return reinterpret_cast<la_detail::matrix_scalar_cast_<T,Scalar> const &>(x);
			}
		}
	}

#endif
