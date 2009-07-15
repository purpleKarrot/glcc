/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_BLEND_HPP
#define GLCC_BLEND_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/detail/get.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace blend
{

//! Control whether blending is enabled
GLCC_ENABLE(GL_BLEND)

inline void color(const vec4& value)
{
	//glBlendColor(value.r, value.g, value.b, value.a);
	glBlendColor(value[0], value[1], value[2], value[3]);
}

inline vec4 color()
{
	return detail::get<vec4>(GL_BLEND_COLOR);
}

enum equation_type
{
	func_add = GL_FUNC_ADD,
	func_substract = GL_FUNC_SUBTRACT,
	func_reverse_substract = GL_FUNC_REVERSE_SUBTRACT,
	func_min = GL_MIN,
	func_max = GL_MAX
};

inline void equation(equation_type mode_rgb, equation_type mode_alpha)
{
	glBlendEquationSeparate(mode_rgb, mode_alpha);
}

inline void equation(equation_type mode)
{
	glBlendEquation(mode);
}

inline equation_type equation_rgb()
{
	return detail::get<equation_type>(GL_BLEND_EQUATION_RGB);
}

inline equation_type equation_alpha()
{
	return detail::get<equation_type>(GL_BLEND_EQUATION_ALPHA);
}

inline void equation_rgb(equation_type mode_rgb)
{
	equation(mode_rgb, equation_alpha());
}

inline void equation_alpha(equation_type mode_alpha)
{
	equation(equation_rgb(), mode_alpha);
}

enum function_type
{
	zero = GL_ZERO,
	one = GL_ONE,
	src_color = GL_SRC_COLOR,
	one_minus_src_color = GL_ONE_MINUS_SRC_COLOR,
	dst_color = GL_DST_COLOR,
	one_minus_dst_color = GL_ONE_MINUS_DST_COLOR,
	src_alpha = GL_SRC_ALPHA,
	one_minus_src_alpha = GL_ONE_MINUS_SRC_ALPHA,
	dst_alpha = GL_DST_ALPHA,
	one_minus_dst_alpha = GL_ONE_MINUS_DST_ALPHA,
	constant_color = GL_CONSTANT_COLOR,
	one_minus_constant_color = GL_ONE_MINUS_CONSTANT_COLOR,
	constant_apha = GL_CONSTANT_ALPHA,
	one_minus_constant_alpha = GL_ONE_MINUS_CONSTANT_ALPHA,
	src_alpha_saturate = GL_SRC_ALPHA_SATURATE
};

inline void function(GLenum src_rgb, GLenum dst_rgb, GLenum src_alpha,
		GLenum dst_alpha)
{
	glBlendFuncSeparate(src_rgb, dst_rgb, src_alpha, dst_alpha);
}

inline void function(GLenum src, GLenum dst)
{
	glBlendFunc(src, dst);
}

inline function_type function_src()
{
	return detail::get<function_type>(GL_BLEND_SRC);
}

inline function_type function_dst()
{
	return detail::get<function_type>(GL_BLEND_DST);
}

inline void function_src(GLenum src)
{
	function(src, function_dst());
}

inline void function_dst(GLenum dst)
{
	function(function_src(), dst);
}

inline function_type function_src_rgb()
{
	return detail::get<function_type>(GL_BLEND_SRC_RGB);
}

inline function_type function_src_alpha()
{
	return detail::get<function_type>(GL_BLEND_SRC_ALPHA);
}

inline function_type function_dst_rgb()
{
	return detail::get<function_type>(GL_BLEND_DST_RGB);
}

inline function_type function_dst_alpha()
{
	return detail::get<function_type>(GL_BLEND_DST_ALPHA);
}

} // namespace blend
} // namespace gl

#endif /* GLCC_BLEND_HPP */
