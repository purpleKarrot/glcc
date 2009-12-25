//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_MINUS_1_3_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_MINUS_1_3_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/utility/enable_if.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A>
        BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            matrix_traits<A>::rows==1 && matrix_traits<A>::cols==3,
            deduce_matrix<A> >::type
        operator-( A const & a )
            {
            typedef typename deduce_matrix<A>::type R;
            R r;
            matrix_traits<R>::template w<0,0>(r)=-matrix_traits<A>::template r<0,0>(a);
            matrix_traits<R>::template w<0,1>(r)=-matrix_traits<A>::template r<0,1>(a);
            matrix_traits<R>::template w<0,2>(r)=-matrix_traits<A>::template r<0,2>(a);
            return r;
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct matrix_minus_defined;

            template <>
            struct
            matrix_minus_defined<1,3>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif