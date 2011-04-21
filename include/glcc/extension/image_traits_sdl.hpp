/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_EXTENSION_IMAGE_TRAITS_SDL_HPP
#define GLCC_EXTENSION_IMAGE_TRAITS_SDL_HPP

#include <SDL/SDL_video.h>
#include <glcc/detail/image_traits.hpp>

namespace gl
{
namespace detail
{

template<>
struct image_traits<SDL_Surface*>
{
	static const int dim = 2;

	static GLsizei width(const SDL_Surface* surface)
	{
		return surface->w;
	}

	static GLsizei height(const SDL_Surface* surface)
	{
		return surface->h;
	}

	static GLenum format(const SDL_Surface* surface)
	{
		if (surface->format->BytesPerPixel == 4)
			return (surface->format->Rmask == 0x000000ff) ? GL_RGBA : GL_BGRA;

		if (surface->format->BytesPerPixel == 3)
			return (surface->format->Rmask == 0x000000ff) ? GL_RGB : GL_BGR;

		assert(!"unknown format");
		return 0;
	}

	static GLenum type(const SDL_Surface*)
	{
		return GL_UNSIGNED_BYTE;
	}

	static GLvoid* data(SDL_Surface* surface)
	{
		return surface->pixels;
	}

	static const GLvoid* data(const SDL_Surface* surface)
	{
		return surface->pixels;
	}
};

} // namespace detail
} // namespace gl

#endif /* GLCC_EXTENSION_IMAGE_TRAITS_SDL_HPP */
