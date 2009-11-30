//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_C66C1B82B03A11DE946F878455D89593
#define UUID_C66C1B82B03A11DE946F878455D89593

#include <boost/la/vec_traits.hpp>
#include <boost/la/deduce_scalar.hpp>
#include <boost/la/scalar.hpp>
#include <boost/la/vector_assign.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class V,class S,int D,
				class VS=typename vector_traits<V>::scalar_type,
				int VD=vector_traits<V>::dim>
			struct
			deduce_vector_default
				{
				typedef vec<S,D> type;
				};

			template <class V,class S,int D>
			struct
			deduce_vector_default<V,S,D,S,D>
				{
				typedef V type;
				};
			}

		template <class Vector,int Dim=vector_traits<Vector>::dim,class Scalar=typename vector_traits<Vector>::scalar_type>
		struct
		deduce_vector
			{
			typedef typename la_detail::deduce_vector_default<Vector,Scalar,Dim>::type type;
			};

		namespace
		la_detail
			{
			template <class A,class B,int D,
				bool VA=is_vector<A>::value,
				bool VB=is_vector<B>::value,
				int AD=vector_traits<A>::dim,
				int BD=vector_traits<B>::dim>
			struct
			deduce_vector2_default
				{
				typedef vec<
					typename deduce_scalar<
						typename scalar<A>::type,
						typename scalar<B>::type>::type,
					D> type;
				};

			template <class V,int D>
			struct
			deduce_vector2_default<V,V,D,true,true,D,D>
				{
				typedef V type;
				};
			};

		template <class A,class B,int D>
		struct
		deduce_vector2
			{
			typedef typename la_detail::deduce_vector2_default<A,B,D>::type type;
			};
		}
	}

#endif
