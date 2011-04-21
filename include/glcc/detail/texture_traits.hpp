/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_TEXTURE_TRAITS_HPP
#define GLCC_DETAIL_TEXTURE_TRAITS_HPP

#include <boost/mpl/bool.hpp>

namespace gl
{
namespace detail
{

template<GLenum Target>
struct is_1d_texture: boost::mpl::false_
{
};

template<GLenum Target>
struct is_2d_texture: boost::mpl::false_
{
};

template<GLenum Target>
struct is_3d_texture: boost::mpl::false_
{
};

template<>
struct is_1d_texture<GL_TEXTURE_1D> : boost::mpl::true_
{
};

template<>
struct is_2d_texture<GL_TEXTURE_2D> : boost::mpl::true_
{
};

template<>
struct is_3d_texture<GL_TEXTURE_3D> : boost::mpl::true_
{
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_TEXTURE_TRAITS_HPP */
