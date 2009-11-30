//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_9B266FF0B03911DE88B2247D55D89593
#define UUID_9B266FF0B03911DE88B2247D55D89593

#include <boost/la/mat_traits.hpp>
#include <boost/la/deduce_scalar.hpp>
#include <boost/la/scalar.hpp>
#include <boost/la/matrix_assign.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class M,class S,int R,int C,
				class MS=typename matrix_traits<M>::scalar_type,
				int MR=matrix_traits<M>::rows,
				int MC=matrix_traits<M>::cols>
			struct
			deduce_matrix_default
				{
				typedef mat<S,R,C> type;
				};

			template <class M,class S,int R,int C>
			struct
			deduce_matrix_default<M,S,R,C,S,R,C>
				{
				typedef M type;
				};
			}

		template <class Matrix,int Rows=matrix_traits<Matrix>::rows,int Cols=matrix_traits<Matrix>::cols,class Scalar=typename matrix_traits<Matrix>::scalar_type>
		struct
		deduce_matrix
			{
			typedef typename la_detail::deduce_matrix_default<Matrix,Scalar,Rows,Cols>::type type;
			};

		namespace
		la_detail
			{
			template <class A,class B,int R,int C,
				bool VA=is_matrix<A>::value,
				bool VB=is_matrix<B>::value,
				int AR=matrix_traits<A>::rows,
				int AC=matrix_traits<A>::cols,
				int BR=matrix_traits<B>::rows,
				int BC=matrix_traits<B>::cols>
			struct
			deduce_matrix2_default
				{
				typedef mat<
					typename deduce_scalar<
						typename scalar<A>::type,
						typename scalar<B>::type>::type,
					R,C> type;
				};

			template <class M,int R,int C>
			struct
			deduce_matrix2_default<M,M,R,C,true,true,R,C,R,C>
				{
				typedef M type;
				};
			};

		template <class A,class B,int R,int C>
		struct
		deduce_matrix2
			{
			typedef typename la_detail::deduce_matrix2_default<A,B,R,C>::type type;
			};
		}
	}

#endif
