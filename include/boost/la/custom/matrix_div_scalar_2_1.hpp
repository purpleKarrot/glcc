//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_DIV_SCALAR_2_1_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_DIV_SCALAR_2_1_HPP_INCLUDED

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
            matrix_traits<A>::rows==2 && matrix_traits<A>::cols==1,
            deduce_matrix<A> >::type
        operator/( A const & a, typename matrix_traits<A>::scalar_type b )
            {
            typedef typename deduce_matrix<A>::type R;
            R r;
            matrix_traits<R>::template w<0,0>(r)=matrix_traits<A>::template r<0,0>(a)/b;
            matrix_traits<R>::template w<1,0>(r)=matrix_traits<A>::template r<1,0>(a)/b;
            return r;
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct matrix_div_scalar_defined;

            template <>
            struct
            matrix_div_scalar_defined<2,1>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
