/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_EXTENSION_IMAGE_TRAITS_GIL_HPP
#define GLCC_EXTENSION_IMAGE_TRAITS_GIL_HPP

#include <glcc/detail/image_traits.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/pixel.hpp>
#include <boost/gil/typedefs.hpp>

namespace gl
{
namespace detail
{

#define GLCC_TRAITS_BASE(TYPE, NAME) \
	template<typename T> struct NAME##_traits {}; \
	template<TYPE VAL> struct NAME##_traits_base \
	{ BOOST_STATIC_CONSTANT(TYPE, NAME = VAL); };

#define GLCC_TRAITS(NAME, CC, GL) \
	template<> struct NAME##_traits<CC> : NAME##_traits_base<GL> {};

GLCC_TRAITS_BASE(unsigned int, layout)
GLCC_TRAITS(layout, boost::gil::rgb_layout_t, GL_RGB)
GLCC_TRAITS(layout, boost::gil::rgba_layout_t, GL_RGBA)
GLCC_TRAITS(layout, boost::gil::bgr_layout_t, GL_BGR)
GLCC_TRAITS(layout, boost::gil::bgra_layout_t, GL_BGRA)

GLCC_TRAITS_BASE(unsigned int, channel)
GLCC_TRAITS(channel, boost::gil::bits8, GL_UNSIGNED_BYTE)
GLCC_TRAITS(channel, boost::gil::bits8s, GL_BYTE)
GLCC_TRAITS(channel, boost::gil::bits16, GL_UNSIGNED_SHORT)
GLCC_TRAITS(channel, boost::gil::bits16s, GL_SHORT)
GLCC_TRAITS(channel, boost::gil::bits32, GL_UNSIGNED_INT)
GLCC_TRAITS(channel, boost::gil::bits32s, GL_INT)
GLCC_TRAITS(channel, boost::gil::bits32f, GL_FLOAT)

#undef GLCC_TRAITS
#undef GLCC_TRAITS_BASE

template<typename Pixel, typename Alloc>
struct image_traits<boost::gil::image<Pixel, false, Alloc> >
{
	static const int dim = 2;
	typedef boost::gil::image<Pixel, false, Alloc> image_type;

	static GLsizei width(const image_type& image)
	{
		return image.width();
	}

	static GLsizei height(const image_type& image)
	{
		return image.height();
	}

	static GLenum format(const image_type&)
	{
		return layout_traits<boost::gil::layout<
				typename boost::gil::color_space_type<Pixel>::type,
				typename boost::gil::channel_mapping_type<Pixel>::type> >::layout;
	}

	static GLenum type(const image_type&)
	{
		return channel_traits<typename boost::gil::channel_type<Pixel>::type>::channel;
	}

	static GLvoid* data(image_type& image)
	{
		return reinterpret_cast<GLvoid*> (&image._view[0]);
	}

	static const GLvoid* data(const image_type& image)
	{
		return reinterpret_cast<const GLvoid*> (&image._view[0]);
	}
};

} // namespace detail
} // namespace gl

#endif /* GLCC_EXTENSION_IMAGE_TRAITS_GIL_HPP */
