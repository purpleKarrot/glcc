//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_DETERMINANT_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_DETERMINANT_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A>
        BOOST_LA_INLINE_OPERATIONS
        typename enable_if_c<
            matrix_traits<A>::rows==4 && matrix_traits<A>::cols==4,
            typename matrix_traits<A>::scalar_type>::type
        determinant( A const & a )
            {
            typedef typename matrix_traits<A>::scalar_type T;
            T const a00=matrix_traits<A>::template r<0,0>(a);
            T const a01=matrix_traits<A>::template r<0,1>(a);
            T const a02=matrix_traits<A>::template r<0,2>(a);
            T const a03=matrix_traits<A>::template r<0,3>(a);
            T const a10=matrix_traits<A>::template r<1,0>(a);
            T const a11=matrix_traits<A>::template r<1,1>(a);
            T const a12=matrix_traits<A>::template r<1,2>(a);
            T const a13=matrix_traits<A>::template r<1,3>(a);
            T const a20=matrix_traits<A>::template r<2,0>(a);
            T const a21=matrix_traits<A>::template r<2,1>(a);
            T const a22=matrix_traits<A>::template r<2,2>(a);
            T const a23=matrix_traits<A>::template r<2,3>(a);
            T const a30=matrix_traits<A>::template r<3,0>(a);
            T const a31=matrix_traits<A>::template r<3,1>(a);
            T const a32=matrix_traits<A>::template r<3,2>(a);
            T const a33=matrix_traits<A>::template r<3,3>(a);
            T det=(a00*(a11*(a22*a33-a23*a32)-a12*(a21*a33-a23*a31)+a13*(a21*a32-a22*a31))-a01*(a10*(a22*a33-a23*a32)-a12*(a20*a33-a23*a30)+a13*(a20*a32-a22*a30))+a02*(a10*(a21*a33-a23*a31)-a11*(a20*a33-a23*a30)+a13*(a20*a31-a21*a30))-a03*(a10*(a21*a32-a22*a31)-a11*(a20*a32-a22*a30)+a12*(a20*a31-a21*a30)));
            return det;
            }

        namespace
        la_detail
            {
            template <int D>
            struct matrix_determinant_defined;

            template <>
            struct
            matrix_determinant_defined<4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif