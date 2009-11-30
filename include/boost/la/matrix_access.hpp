//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_0B0AB514B91E11DEBCA23D3F56D89593
#define UUID_0B0AB514B91E11DEBCA23D3F56D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
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
			template <int R,int C>
			struct
			matrix_access_tag
				{
				};
			}

		template <class Matrix,int R,int C>
        BOOST_LA_INLINE_TRIVIAL
		typename matrix_traits<Matrix>::scalar_type &
		operator|( Matrix & a, la_detail::matrix_access_tag<R,C> (*)() )
			{
			BOOST_STATIC_ASSERT(R>=0);
			BOOST_STATIC_ASSERT(R<matrix_traits<Matrix>::rows);
			BOOST_STATIC_ASSERT(C>=0);
			BOOST_STATIC_ASSERT(C<matrix_traits<Matrix>::cols);
			return matrix_traits<Matrix>::template w<R,C>(a);
			}

		template <class Matrix,int R,int C>
        BOOST_LA_INLINE_TRIVIAL
		typename matrix_traits<Matrix>::scalar_type
		operator|( Matrix const & a, la_detail::matrix_access_tag<R,C> (*)() )
			{
			BOOST_STATIC_ASSERT(R>=0);
			BOOST_STATIC_ASSERT(R<matrix_traits<Matrix>::rows);
			BOOST_STATIC_ASSERT(C>=0);
			BOOST_STATIC_ASSERT(C<matrix_traits<Matrix>::cols);
			return matrix_traits<Matrix>::template r<R,C>(a);
			}

		template <class Matrix,int R,int C>
        BOOST_LA_INLINE_TRIVIAL
		typename matrix_traits<Matrix>::scalar_type &
		operator|( Matrix & a, la_detail::matrix_access_tag<R,C> )
			{
			BOOST_STATIC_ASSERT(R>=0);
			BOOST_STATIC_ASSERT(R<matrix_traits<Matrix>::rows);
			BOOST_STATIC_ASSERT(C>=0);
			BOOST_STATIC_ASSERT(C<matrix_traits<Matrix>::cols);
			return matrix_traits<Matrix>::template w<R,C>(a);
			}

		template <class Matrix,int R,int C>
        BOOST_LA_INLINE_TRIVIAL
		typename matrix_traits<Matrix>::scalar_type
		operator|( Matrix const & a, la_detail::matrix_access_tag<R,C> )
			{
			BOOST_STATIC_ASSERT(R>=0);
			BOOST_STATIC_ASSERT(R<matrix_traits<Matrix>::rows);
			BOOST_STATIC_ASSERT(C>=0);
			BOOST_STATIC_ASSERT(C<matrix_traits<Matrix>::cols);
			return matrix_traits<Matrix>::template r<R,C>(a);
			}

		template <int R,int C>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::matrix_access_tag<R,C>
		A()
			{
			return la_detail::matrix_access_tag<R,C>();
			}

		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,0> A00() { return la_detail::matrix_access_tag<0,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,1> A01() { return la_detail::matrix_access_tag<0,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,2> A02() { return la_detail::matrix_access_tag<0,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,3> A03() { return la_detail::matrix_access_tag<0,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,4> A04() { return la_detail::matrix_access_tag<0,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,5> A05() { return la_detail::matrix_access_tag<0,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,6> A06() { return la_detail::matrix_access_tag<0,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,7> A07() { return la_detail::matrix_access_tag<0,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,8> A08() { return la_detail::matrix_access_tag<0,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<0,9> A09() { return la_detail::matrix_access_tag<0,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,0> A10() { return la_detail::matrix_access_tag<1,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,1> A11() { return la_detail::matrix_access_tag<1,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,2> A12() { return la_detail::matrix_access_tag<1,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,3> A13() { return la_detail::matrix_access_tag<1,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,4> A14() { return la_detail::matrix_access_tag<1,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,5> A15() { return la_detail::matrix_access_tag<1,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,6> A16() { return la_detail::matrix_access_tag<1,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,7> A17() { return la_detail::matrix_access_tag<1,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,8> A18() { return la_detail::matrix_access_tag<1,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<1,9> A19() { return la_detail::matrix_access_tag<1,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,0> A20() { return la_detail::matrix_access_tag<2,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,1> A21() { return la_detail::matrix_access_tag<2,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,2> A22() { return la_detail::matrix_access_tag<2,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,3> A23() { return la_detail::matrix_access_tag<2,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,4> A24() { return la_detail::matrix_access_tag<2,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,5> A25() { return la_detail::matrix_access_tag<2,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,6> A26() { return la_detail::matrix_access_tag<2,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,7> A27() { return la_detail::matrix_access_tag<2,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,8> A28() { return la_detail::matrix_access_tag<2,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<2,9> A29() { return la_detail::matrix_access_tag<2,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,0> A30() { return la_detail::matrix_access_tag<3,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,1> A31() { return la_detail::matrix_access_tag<3,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,2> A32() { return la_detail::matrix_access_tag<3,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,3> A33() { return la_detail::matrix_access_tag<3,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,4> A34() { return la_detail::matrix_access_tag<3,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,5> A35() { return la_detail::matrix_access_tag<3,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,6> A36() { return la_detail::matrix_access_tag<3,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,7> A37() { return la_detail::matrix_access_tag<3,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,8> A38() { return la_detail::matrix_access_tag<3,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<3,9> A39() { return la_detail::matrix_access_tag<3,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,0> A40() { return la_detail::matrix_access_tag<4,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,1> A41() { return la_detail::matrix_access_tag<4,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,2> A42() { return la_detail::matrix_access_tag<4,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,3> A43() { return la_detail::matrix_access_tag<4,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,4> A44() { return la_detail::matrix_access_tag<4,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,5> A45() { return la_detail::matrix_access_tag<4,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,6> A46() { return la_detail::matrix_access_tag<4,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,7> A47() { return la_detail::matrix_access_tag<4,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,8> A48() { return la_detail::matrix_access_tag<4,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<4,9> A49() { return la_detail::matrix_access_tag<4,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,0> A50() { return la_detail::matrix_access_tag<5,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,1> A51() { return la_detail::matrix_access_tag<5,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,2> A52() { return la_detail::matrix_access_tag<5,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,3> A53() { return la_detail::matrix_access_tag<5,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,4> A54() { return la_detail::matrix_access_tag<5,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,5> A55() { return la_detail::matrix_access_tag<5,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,6> A56() { return la_detail::matrix_access_tag<5,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,7> A57() { return la_detail::matrix_access_tag<5,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,8> A58() { return la_detail::matrix_access_tag<5,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<5,9> A59() { return la_detail::matrix_access_tag<5,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,0> A60() { return la_detail::matrix_access_tag<6,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,1> A61() { return la_detail::matrix_access_tag<6,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,2> A62() { return la_detail::matrix_access_tag<6,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,3> A63() { return la_detail::matrix_access_tag<6,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,4> A64() { return la_detail::matrix_access_tag<6,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,5> A65() { return la_detail::matrix_access_tag<6,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,6> A66() { return la_detail::matrix_access_tag<6,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,7> A67() { return la_detail::matrix_access_tag<6,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,8> A68() { return la_detail::matrix_access_tag<6,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<6,9> A69() { return la_detail::matrix_access_tag<6,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,0> A70() { return la_detail::matrix_access_tag<7,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,1> A71() { return la_detail::matrix_access_tag<7,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,2> A72() { return la_detail::matrix_access_tag<7,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,3> A73() { return la_detail::matrix_access_tag<7,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,4> A74() { return la_detail::matrix_access_tag<7,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,5> A75() { return la_detail::matrix_access_tag<7,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,6> A76() { return la_detail::matrix_access_tag<7,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,7> A77() { return la_detail::matrix_access_tag<7,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,8> A78() { return la_detail::matrix_access_tag<7,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<7,9> A79() { return la_detail::matrix_access_tag<7,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,0> A80() { return la_detail::matrix_access_tag<8,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,1> A81() { return la_detail::matrix_access_tag<8,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,2> A82() { return la_detail::matrix_access_tag<8,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,3> A83() { return la_detail::matrix_access_tag<8,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,4> A84() { return la_detail::matrix_access_tag<8,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,5> A85() { return la_detail::matrix_access_tag<8,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,6> A86() { return la_detail::matrix_access_tag<8,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,7> A87() { return la_detail::matrix_access_tag<8,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,8> A88() { return la_detail::matrix_access_tag<8,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<8,9> A89() { return la_detail::matrix_access_tag<8,9>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,0> A90() { return la_detail::matrix_access_tag<9,0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,1> A91() { return la_detail::matrix_access_tag<9,1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,2> A92() { return la_detail::matrix_access_tag<9,2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,3> A93() { return la_detail::matrix_access_tag<9,3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,4> A94() { return la_detail::matrix_access_tag<9,4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,5> A95() { return la_detail::matrix_access_tag<9,5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,6> A96() { return la_detail::matrix_access_tag<9,6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,7> A97() { return la_detail::matrix_access_tag<9,7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,8> A98() { return la_detail::matrix_access_tag<9,8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::matrix_access_tag<9,9> A99() { return la_detail::matrix_access_tag<9,9>(); }
		}
    }

#endif
