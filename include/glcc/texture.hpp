/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_TEXTURE_HPP
#define GLCC_TEXTURE_HPP

#include <boost/scoped_array.hpp>
#include <glcc/detail/gl.hpp>
#include <glcc/detail/scoped_bind_base.hpp>
#include <glcc/detail/color.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace detail
{

class texture_base
{
GLCC_BASE(texture_base, Texture, Textures)
};

template<GLenum Target, GLenum Binding>
struct texture_target
{
BOOST_STATIC_CONSTANT(GLenum, target_type = Target);
typedef texture_base value_type;
typedef scoped_bind_base<texture_target, Binding> scoped_bind;

static inline void bind(const texture_base& tex)
{
	glBindTexture(Target, tex.name);
}

static inline void generate_mipmap()
{
	glGenerateMipmap(Target);
}

// CLAMP, CLAMP_TO_EDGE, REPEAT, CLAMP_TO_BORDER, MIRRORED_REPEAT
static inline void wrap_s(GLenum wrap)
{
	glTexParameteri(Target, GL_TEXTURE_WRAP_S, wrap);
}

// CLAMP, CLAMP_TO_EDGE, REPEAT, CLAMP_TO_BORDER, MIRRORED_REPEAT
static inline void wrap_t(GLenum wrap)
{
	glTexParameteri(Target, GL_TEXTURE_WRAP_T, wrap);
}

// CLAMP, CLAMP_TO_EDGE, REPEAT, CLAMP_TO_BORDER, MIRRORED_REPEAT
static inline void wrap_r(GLenum wrap)
{
	glTexParameteri(Target, GL_TEXTURE_WRAP_R, wrap);
}

// NEAREST, LINEAR, NEAREST_MIPMAP_NEAREST, NEAREST_MIPMAP_LINEAR,
// LINEAR_MIPMAP_NEAREST, LINEAR_MIPMAP_LINEAR
static inline void min_filter(GLenum filter)
{
	glTexParameteri(Target, GL_TEXTURE_MIN_FILTER, filter);
}

// NEAREST, LINEAR
static inline void mag_filter(GLenum filter)
{
	glTexParameteri(Target, GL_TEXTURE_MAG_FILTER, filter);
}

// any 4 values
static inline void border_color(float color[4])
{
	glTexParameterfv(Target, GL_TEXTURE_BORDER_COLOR, color);
}

//// any value in [0, 1]
//static inline void priority(float param)
//{
//	glTexParameterf(Target, GL_TEXTURE_PRIORITY, param);
//}

// any value
static inline void min_lod(float param)
{
	glTexParameterf(Target, GL_TEXTURE_MIN_LOD, param);
}

// any value
static inline void max_lod(float param)
{
	glTexParameterf(Target, GL_TEXTURE_MAX_LOD, param);
}

// any non-negative integer
static inline void base_level(int param)
{
	glTexParameteri(Target, GL_TEXTURE_BASE_LEVEL, param);
}

// any non-negative integer
static inline void max_level(int param)
{
	glTexParameteri(Target, GL_TEXTURE_MAX_LEVEL, param);
}

// any value
static inline void lod_bias(float param)
{
	glTexParameterf(Target, GL_TEXTURE_LOD_BIAS, param);
}

//// RED, LUMINANCE, INTENSITY, ALPHA
//static inline void depth_mode(GLenum mode)
//{
//	glTexParameteri(Target, GL_DEPTH_TEXTURE_MODE, mode);
//}

// NONE, COMPARE_REF_TO_TEXTURE
static inline void compare_mode(GLenum mode)
{
	glTexParameteri(Target, GL_TEXTURE_COMPARE_MODE, mode);
}

// LEQUAL, GEQUAL, LESS, GREATER, EQUAL, NOTEQUAL, ALWAYS, NEVER
static inline void compare_func(GLenum func)
{
	glTexParameteri(Target, GL_TEXTURE_COMPARE_FUNC, func);
}

template<typename View>
static inline void image(GLint level, GLint internalformat, GLint border,
		const View& view)
{
	glTexImage2D(Target, level, internalformat, view.width(),
			view.height(), border, color_traits<View>::layout,
			color_traits<View>::channel, &view[0]);
}

//	void TexImage1D( enum target, int level,
//	   int internalformat, sizei width, int border,
//	   enum format, enum type, void *data );
//	void TexImage2D( enum target, int level,
//	   int internalformat, sizei width, sizei height,
//	   int border, enum format, enum type, void *data );
//	void TexImage3D( enum target, int level, int internalformat,
//	   sizei width, sizei height, sizei depth, int border,
//	   enum format, enum type, void *data );

static inline void sub_image();
//	void TexSubImage1D( enum target, int level, int xoffset,
//	   sizei width, enum format, enum type, void *data );
//	void TexSubImage2D( enum target, int level, int xoffset,
//	   int yoffset, sizei width, sizei height, enum format,
//	   enum type, void *data );
//	void TexSubImage3D( enum target, int level, int xoffset,
//	   int yoffset, int zoffset, sizei width, sizei height,
//	   sizei depth, enum format, enum type, void *data );

static inline void copy_image();
//	void CopyTexImage1D( enum target, int level,
//	   enum internalformat, int x, int y, sizei width,
//	   int border );
//	void CopyTexImage2D( enum target, int level,
//	   enum internalformat, int x, int y, sizei width,
//	   sizei height, int border );


static inline void copy_sub_image();
//	void CopyTexSubImage1D( enum target, int level,
//	   int xoffset, int x, int y, sizei width );
//	void CopyTexSubImage2D( enum target, int level,
//	   int xoffset, int yoffset, int x, int y, sizei width,
//	   sizei height );
//	void CopyTexSubImage3D( enum target, int level,
//	   int xoffset, int yoffset, int zoffset, int x, int y,
//	   sizei width, sizei height );


static inline void compressed_image();
//	void CompressedTexImage1D( enum target, int level,
//	   enum internalformat, sizei width, int border,
//	   sizei imageSize, void *data );
//	void CompressedTexImage2D( enum target, int level,
//	   enum internalformat, sizei width, sizei height,
//	   int border, sizei imageSize, void *data );
//	void CompressedTexImage3D( enum target, int level,
//	   enum internalformat, sizei width, sizei height,
//	   sizei depth, int border, sizei imageSize, void *data );

static inline void compressed_sub_image();
//	void CompressedTexSubImage1D( enum target, int level,
//	   int xoffset, sizei width, enum format, sizei imageSize,
//	   void *data );
//	void CompressedTexSubImage2D( enum target, int level,
//	   int xoffset, int yoffset, sizei width, sizei height,
//	   enum format, sizei imageSize, void *data );
//	void CompressedTexSubImage3D( enum target, int level,
//	   int xoffset, int yoffset, int zoffset, sizei width,
//	   sizei height, sizei depth, enum format,
//	   sizei imageSize, void *data );


static inline void get_image();
//	void glGetTexImage( enum tex, int lod, enum format, enum type, void *img );

static inline void get_compressed_image();
//	void GetCompressedTexImage( enum target, int lod, void *img );
};

} // namespace detail

typedef detail::texture_target<GL_TEXTURE_1D, GL_TEXTURE_BINDING_1D> texture_1d;
typedef detail::texture_target<GL_TEXTURE_2D, GL_TEXTURE_BINDING_2D> texture_2d;
typedef detail::texture_target<GL_TEXTURE_3D, GL_TEXTURE_BINDING_3D> texture_3d;

typedef detail::texture_target<GL_TEXTURE_1D_ARRAY, //
GL_TEXTURE_BINDING_1D_ARRAY> texture_1d_array;

typedef detail::texture_target<GL_TEXTURE_2D_ARRAY, //
GL_TEXTURE_BINDING_2D_ARRAY> texture_2d_array;

typedef detail::texture_target<GL_TEXTURE_CUBE_MAP, //
GL_TEXTURE_BINDING_CUBE_MAP> texture_cube_map;

GLCC_OBJECT(texture)

template<typename Texture>
void bind(GLenum unit, Texture const& texture)
{
	glBindMultiTextureEXT (unit, Texture::target, texture.name);
}

} // namespace gl

#endif /* GLCC_TEXTURE_HPP */
