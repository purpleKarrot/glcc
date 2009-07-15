/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef BOOST_GL_COLOR_HPP
#define BOOST_GL_COLOR_HPP

#include <glcc/detail/gl.hpp>
#include <boost/gil/pixel.hpp>
#include <boost/gil/typedefs.hpp>

#define GLCC_TRAITS_BASE(TYPE, NAME) \
	template<typename T> struct NAME##_traits {}; \
	template<TYPE VAL> struct NAME##_traits_base \
	{ BOOST_STATIC_CONSTANT(TYPE, NAME = VAL); };

#define GLCC_TRAITS(NAME, CC, GL) \
	template<> struct NAME##_traits<CC> : NAME##_traits_base<GL> {};

namespace gl
{

typedef boost::gil::rgb32f_pixel_t rgb32f_color_t;
typedef boost::gil::rgba32f_pixel_t rgba32f_color_t;

typedef boost::gil::bgr32f_pixel_t bgr32f_color_t;
typedef boost::gil::bgra32f_pixel_t bgra32f_color_t;

GLCC_TRAITS_BASE(unsigned int, layout)
//GLCC_TRAITS(layout, ???, GL_RED)
//GLCC_TRAITS(layout, ???, GL_GREEN)
//GLCC_TRAITS(layout, ???, GL_BLUE)
//GLCC_TRAITS(layout, ???, GL_ALPHA)
GLCC_TRAITS(layout, boost::gil::rgb_layout_t, GL_RGB)
GLCC_TRAITS(layout, boost::gil::rgba_layout_t, GL_RGBA)
GLCC_TRAITS(layout, boost::gil::bgr_layout_t, GL_BGR)
GLCC_TRAITS(layout, boost::gil::bgra_layout_t, GL_BGRA)
//GLCC_TRAITS(layout, boost::gil::gray_layout_t, GL_LUMINANCE)
//GLCC_TRAITS(layout, ???, GL_LUMINANCE_ALPHA)

GLCC_TRAITS_BASE(unsigned int, channel)
GLCC_TRAITS(channel, boost::gil::bits8, GL_UNSIGNED_BYTE)
GLCC_TRAITS(channel, boost::gil::bits8s, GL_BYTE)
GLCC_TRAITS(channel, boost::gil::bits16, GL_UNSIGNED_SHORT)
GLCC_TRAITS(channel, boost::gil::bits16s, GL_SHORT)
GLCC_TRAITS(channel, boost::gil::bits32, GL_UNSIGNED_INT)
GLCC_TRAITS(channel, boost::gil::bits32s, GL_INT)
GLCC_TRAITS(channel, boost::gil::bits32f, GL_FLOAT)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_BYTE_3_3_2)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_BYTE_2_3_3_REV)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_5_6_5)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_5_6_5_REV)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_4_4_4_4)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_4_4_4_4_REV)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_5_5_5_1)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_SHORT_1_5_5_5_REV)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_INT_8_8_8_8)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_INT_8_8_8_8_REV)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_INT_10_10_10_2)
//GLCC_TRAITS(channel, ???, GL_UNSIGNED_INT_2_10_10_10_REV)

template<typename T>
struct color_traits: layout_traits<boost::gil::layout<
		typename boost::gil::color_space_type<T>::type,
		typename boost::gil::channel_mapping_type<T>::type> > , //
		channel_traits<typename boost::gil::channel_type<T>::type>
{
};

} // end namespace gl

#undef GLCC_TRAITS
#undef GLCC_TRAITS_BASE

#endif /* BOOST_GL_COLOR_HPP */
