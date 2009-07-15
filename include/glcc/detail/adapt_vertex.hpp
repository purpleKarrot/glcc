/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_ADAPT_VERTEX_HPP
#define GLCC_ADAPT_VERTEX_HPP

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/mpl/int.hpp>
#include <boost/config/no_tr1/utility.hpp>

namespace gl
{
namespace detail
{

template<typename T>
struct vertex_size
{
};

template<typename T, std::size_t I>
struct vertex_member
{
};

} // namespace detail
} // namespace gl

#define GLCC_ADAPT_VERTEX(name, bseq)                                           \
    GLCC_ADAPT_VERTEX_I(name, BOOST_PP_CAT(GLCC_ADAPT_VERTEX_X bseq, 0))        \

#define GLCC_ADAPT_VERTEX_X(x, y, z) ((x, y, z)) GLCC_ADAPT_VERTEX_Y
#define GLCC_ADAPT_VERTEX_Y(x, y, z) ((x, y, z)) GLCC_ADAPT_VERTEX_X
#define GLCC_ADAPT_VERTEX_X0
#define GLCC_ADAPT_VERTEX_Y0

#define GLCC_ADAPT_VERTEX_I(name, seq)                                          \
    namespace gl { namespace detail                                             \
    {                                                                           \
        template <>                                                             \
        struct vertex_size<name> : boost::mpl::int_<BOOST_PP_SEQ_SIZE(seq)> {}; \
        BOOST_PP_SEQ_FOR_EACH_I(GLCC_ADAPT_VERTEX_C, name, seq)                 \
    }}                                                                          \

#define GLCC_ADAPT_VERTEX_C(r, name, i, xyz)                                      \
    template <>                                                                   \
    struct vertex_member<name, i>                                                 \
    {                                                                             \
        typedef BOOST_PP_TUPLE_ELEM(3, 0, xyz) type;  \
        BOOST_STATIC_CONSTANT(GLint, size = 0); \
        BOOST_STATIC_CONSTANT(GLenum, gltype = 0); \
        BOOST_STATIC_CONSTANT(GLboolean, normalized = BOOST_PP_TUPLE_ELEM(3, 2, xyz)); \
        BOOST_STATIC_CONSTANT(GLsizei, stride = sizeof(name) - sizeof(type)); \
        static type* pointer(name* vertex_)                                       \
        {                                                                         \
            return &vertex_->BOOST_PP_TUPLE_ELEM(3, 1, xyz);                       \
        }                                                                         \
        static const type* pointer(const name* vertex_)                           \
        {                                                                         \
            return &vertex_->BOOST_PP_TUPLE_ELEM(3, 1, xyz);                       \
        }                                                                         \
    };                                                                            \

#endif /* GLCC_ADAPT_VERTEX_HPP */
