//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3DCF6B90AE0E11DE9A315BE555D89593
#define UUID_3DCF6B90AE0E11DE9A315BE555D89593

#include <boost/la/config.hpp>
#include <boost/la/array_matrix_traits.hpp>
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
			template <int N>
			struct
			det_size
				{
				};

			template <class M>
			BOOST_LA_INLINE_TRIVIAL
			typename matrix_traits<M>::scalar_type
			determinant_impl_( M const & a, det_size<2> )
				{
				return
					matrix_traits<M>::template r<0,0>(a) * matrix_traits<M>::template r<1,1>(a) -
					matrix_traits<M>::template r<1,0>(a) * matrix_traits<M>::template r<0,1>(a);
				}

			template <class M,int N>
			BOOST_LA_INLINE_RECURSION
			typename matrix_traits<M>::scalar_type
			determinant_impl_( M const & a, det_size<N> )
				{
				typedef typename matrix_traits<M>::scalar_type T;
				T m[N-1][N-1];
				T det=T(0);
				for( int j1=0; j1!=N; ++j1 )
					{
					for( int i=1; i!=N; ++i )
						{
						int j2 = 0;
						for( int j=0; j!=N; ++j )
							{
							if( j==j1 )
								continue;
							m[i-1][j2] = matrix_traits<M>::ir(i,j,a);
							++j2;
							}
						}
					T d=determinant_impl_(m,det_size<N-1>());
					if( j1&1 )
						d=-d;
					det += matrix_traits<M>::ir(0,j1,a) * d;
					}
				return det;
				}

			template <class M>
			BOOST_LA_INLINE_TRIVIAL
			typename matrix_traits<M>::scalar_type
			determinant_impl( M const & a )
				{
				BOOST_STATIC_ASSERT(matrix_traits<M>::rows==matrix_traits<M>::cols);
				return determinant_impl_(a,det_size<matrix_traits<M>::rows>());
				}
			}
		}
	}

#endif
