//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_995547FAAE0E11DE8CF511E755D89593
#define UUID_995547FAAE0E11DE8CF511E755D89593

#include <boost/la/detail/determinant_impl.hpp>
#include <boost/la/deduce_matrix.hpp>
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
			template <class A>
			BOOST_LA_INLINE_OPERATIONS
			typename deduce_matrix<A>::type
			cofactor_impl( A const & a )
				{
				BOOST_STATIC_ASSERT(matrix_traits<A>::rows==matrix_traits<A>::cols);
				int const N=matrix_traits<A>::rows;
				typedef typename matrix_traits<A>::scalar_type T;
				T c[N-1][N-1];
				typedef typename deduce_matrix<A>::type R;
				R b;
				for( int j=0; j!=N; ++j )
					{
					for( int i=0; i!=N; ++i )
						{
						int i1=0;
						for( int ii=0; ii!=N; ++ii )
							{
							if( ii==i )
								continue;
							int j1=0;
							for( int jj=0; jj!=N; ++jj )
								{
								if( jj==j )
									continue;
								c[i1][j1] = matrix_traits<A>::ir(ii,jj,a);
								++j1;
								}
							++i1;
							}
						T det = determinant_impl(c);
						if( (i+j)&1 )
							det=-det;
						matrix_traits<R>::iw(i,j,b) = det;
						}
					}
				return b;
				}
			}
		}
	}

#endif
