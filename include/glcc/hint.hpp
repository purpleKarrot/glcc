/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_HINT_HPP
#define GLCC_HINT_HPP

#include <GL3/gl3w.h>
#include <glcc/detail/get.hpp>

namespace gl
{

enum hint_type
{
#ifdef GENERATING_DOCUMENTATION
	fastest, ///< The most efficient option should be chosen.
	nicest, ///< The most correct, or highest quality, option should be chosen.
	dont_care ///< No preference.
#else
	dont_care = GL_DONT_CARE, fastest = GL_FASTEST, nicest = GL_NICEST
#endif
};

/**
 * @defgroup line_smooth_hint gl::line_smooth_hint
 *
 * @brief Indicates the sampling quality of antialiased lines.
 *
 * If a larger filter function is applied, hinting GL_NICEST can
 * result in more pixel fragments being generated during rasterization.
 */
/*@{*/
inline void line_smooth_hint(hint_type hint)
{
	glHint(GL_LINE_SMOOTH_HINT, hint);
}

inline hint_type line_smooth_hint()
{
	return detail::get<hint_type>(GL_LINE_SMOOTH_HINT);
}
/*@}*/

//! Polygon sampling quality
inline void polygon_smooth_hint(hint_type hint)
{
	glHint(GL_POLYGON_SMOOTH_HINT, hint);
}

inline hint_type polygon_smooth_hint()
{
	return detail::get<hint_type>(GL_POLYGON_SMOOTH_HINT);
}

//! Quality and performance of texture image compression
inline void texture_compression_hint(hint_type hint)
{
	glHint(GL_TEXTURE_COMPRESSION_HINT, hint);
}

inline hint_type texture_compression_hint()
{
	return detail::get<hint_type>(GL_TEXTURE_COMPRESSION_HINT);
}

//! Indicates the accuracy of the derivative calculation for the GL shading language fragment processing built-in functions: dFdx, dFdy, and fwidth.
inline void fragment_shader_derivative_hint(hint_type hint)
{
	glHint(GL_FRAGMENT_SHADER_DERIVATIVE_HINT, hint);
}

inline hint_type fragment_shader_derivative_hint()
{
	return detail::get<hint_type>(GL_FRAGMENT_SHADER_DERIVATIVE_HINT);
}

} // namespace gl

#endif /* GLCC_HINT_HPP */
