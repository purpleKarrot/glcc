/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PIXEL_HPP
#define GLCC_PIXEL_HPP

#include <GL3/gl3w.h>
#include <glcc/detail/get.hpp>
#include <glcc/detail/color.hpp>

namespace gl
{
namespace pixel
{

namespace detail
{

template<GLenum SwapBytes, GLenum LsbFirst, GLenum RowLength,
		GLenum ImageHeight, GLenum SkipRows, GLenum SkipPixels,
		GLenum SkipImages, GLenum Alignment>
struct pixel_store
{
	static inline void swap_bytes(bool param)
	{
		glPixelStorei(SwapBytes, param);
	}

	static inline bool swap_bytes()
	{
		return gl::detail::get<bool>(SwapBytes);
	}

	static inline void lsb_first(bool param)
	{
		glPixelStorei(LsbFirst, param);
	}

	static inline bool lsb_first()
	{
		return gl::detail::get<bool>(LsbFirst);
	}

	static inline void row_length(int param)
	{
		glPixelStorei(RowLength, param);
	}

	static inline int row_length()
	{
		return gl::detail::get<int>(RowLength);
	}

	static inline void image_height(int param)
	{
		glPixelStorei(ImageHeight, param);
	}

	static inline int image_height()
	{
		return gl::detail::get<int>(ImageHeight);
	}

	static inline void skip_rows(int param)
	{
		glPixelStorei(SkipRows, param);
	}

	static inline int skip_rows()
	{
		return gl::detail::get<int>(SkipRows);
	}

	static inline void skip_pixels(int param)
	{
		glPixelStorei(SkipPixels, param);
	}

	static inline int skip_pixels()
	{
		return gl::detail::get<int>(SkipPixels);
	}

	static inline void skip_images(int param)
	{
		glPixelStorei(SkipImages, param);
	}

	static inline int skip_images()
	{
		return gl::detail::get<int>(SkipImages);
	}

	static inline void alignment(int param)
	{
		glPixelStorei(Alignment, param);
	}

	static inline int alignment()
	{
		return gl::detail::get<int>(Alignment);
	}
};

} // namespace detail

typedef detail::pixel_store<GL_PACK_SWAP_BYTES, GL_PACK_LSB_FIRST,
		GL_PACK_ROW_LENGTH, GL_PACK_IMAGE_HEIGHT, GL_PACK_SKIP_ROWS,
		GL_PACK_SKIP_PIXELS, GL_PACK_SKIP_IMAGES, GL_PACK_ALIGNMENT> pack;

typedef detail::pixel_store<GL_UNPACK_SWAP_BYTES, GL_UNPACK_LSB_FIRST,
		GL_UNPACK_ROW_LENGTH, GL_UNPACK_IMAGE_HEIGHT, GL_UNPACK_SKIP_ROWS,
		GL_UNPACK_SKIP_PIXELS, GL_UNPACK_SKIP_IMAGES, GL_UNPACK_ALIGNMENT>
		unpack;

/// select a color buffer source for pixels
inline void read_buffer(GLenum mode)
{
	glReadBuffer(mode);
}

inline GLenum read_buffer()
{
	return gl::detail::get<GLenum>(GL_READ_BUFFER);
}

template<typename View>
inline void read(int x, int y, const View& view)
{
	glReadPixels(x, y, view.width(), view.height(), color_traits<View>::layout,
			color_traits<View>::channel, &view[0]);
}

} // namespace pixel
} // namespace gl

#endif /* GLCC_PIXEL_HPP */
