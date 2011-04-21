/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_IMAGE_TRAITS_HPP
#define GLCC_DETAIL_IMAGE_TRAITS_HPP

namespace gl
{
namespace detail
{

template<typename Image>
struct image_traits
{
	static const int dim = 0;

	static GLsizei width(const Image& image);
	static GLsizei height(const Image& image);
	static GLsizei depth(const Image& image);

	static GLenum format(const Image& image);
	static GLenum type(const Image& image);

	static GLvoid *data(Image& image);
	static const GLvoid *data(const Image& image);
};

template<typename Image>
struct is_1d_image
{
	static const bool value = image_traits<Image>::dim == 1;
};

template<typename Image>
struct is_2d_image
{
	static const bool value = image_traits<Image>::dim == 2;
};

template<typename Image>
struct is_3d_image
{
	static const bool value = image_traits<Image>::dim == 3;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_IMAGE_TRAITS_HPP */
