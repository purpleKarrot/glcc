/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_TEXTURE_HPP
#define GLCC_TEXTURE_HPP

#include <boost/scoped_array.hpp>
#include <GL3/gl3w.h>
#include <glcc/detail/scoped_bind_base.hpp>
#include <glcc/detail/color.hpp>
#include <glcc/detail/macros.hpp>

template<typename T> struct foo{ typedef T t; };
template<> struct foo<GLenum>{ typedef GLint t; };

#define GLCC_TEX_PARAMETER(type, name, suffix, pname)         \
    static inline void name(type param)                       \
    {                                                         \
        glTexParameter##suffix(Target, pname, param);         \
    }                                                         \
    static inline type name()                                 \
    {                                                         \
	    foo<type>::t value;                                   \
	    glGetTexParameter##suffix##v(Target, pname, &value);  \
	    return value;                                         \
    }                                                         \

#define GLCC_TEX_LEVEL_PARAMETER(type, name, suffix, pname)   \
    static inline type name(int level)                        \
    {                                                         \
	    foo<type>::t value;                                   \
        glGetTexLevelParameter##suffix##v(Target, level, pname, &value); \
        return value;                                         \
    }                                                         \

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
GLCC_TEX_PARAMETER(GLenum, wrap_s, i, GL_TEXTURE_WRAP_S)

// CLAMP, CLAMP_TO_EDGE, REPEAT, CLAMP_TO_BORDER, MIRRORED_REPEAT
GLCC_TEX_PARAMETER(GLenum, wrap_t, i, GL_TEXTURE_WRAP_T)

// CLAMP, CLAMP_TO_EDGE, REPEAT, CLAMP_TO_BORDER, MIRRORED_REPEAT
GLCC_TEX_PARAMETER(GLenum, wrap_r, i, GL_TEXTURE_WRAP_R)

// NEAREST, LINEAR, NEAREST_MIPMAP_NEAREST, NEAREST_MIPMAP_LINEAR,
// LINEAR_MIPMAP_NEAREST, LINEAR_MIPMAP_LINEAR
GLCC_TEX_PARAMETER(GLenum, min_filter, i, GL_TEXTURE_MIN_FILTER)

// NEAREST, LINEAR
GLCC_TEX_PARAMETER(GLenum, mag_filter, i, GL_TEXTURE_MAG_FILTER)

// any 4 values
static inline void border_color(const GLfloat color[4])
{
	glTexParameterfv(Target, GL_TEXTURE_BORDER_COLOR, color);
}

//// any value in [0, 1]
//static inline void priority(float param)
//{
//	glTexParameterf(Target, GL_TEXTURE_PRIORITY, param);
//}

// any value
GLCC_TEX_PARAMETER(GLfloat, min_lod, f, GL_TEXTURE_MIN_LOD)

// any value
GLCC_TEX_PARAMETER(GLfloat, max_lod, f, GL_TEXTURE_MAX_LOD)

// any non-negative integer
GLCC_TEX_PARAMETER(GLint, base_level, i, GL_TEXTURE_BASE_LEVEL)

// any non-negative integer
GLCC_TEX_PARAMETER(GLint, max_level, i, GL_TEXTURE_MAX_LEVEL)

// any value
GLCC_TEX_PARAMETER(GLfloat, lod_bias, f, GL_TEXTURE_LOD_BIAS)

//// RED, LUMINANCE, INTENSITY, ALPHA
//static inline void depth_mode(GLenum mode)
//{
//	glTexParameteri(Target, GL_DEPTH_TEXTURE_MODE, mode);
//}

// NONE, COMPARE_REF_TO_TEXTURE
GLCC_TEX_PARAMETER(GLenum, compare_mode, i, GL_TEXTURE_COMPARE_MODE)

// LEQUAL, GEQUAL, LESS, GREATER, EQUAL, NOTEQUAL, ALWAYS, NEVER
GLCC_TEX_PARAMETER(GLenum, compare_func, i, GL_TEXTURE_COMPARE_FUNC)

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

template<typename View>
static inline void get_image(int lod, View& view)
{
  	glGetTexImage(Target, lod, color_traits<View>::layout, //
				color_traits<View>::channel, &view[0]);
}

static inline void get_compressed_image();
//	void GetCompressedTexImage( enum target, int lod, void *img );

GLCC_TEX_LEVEL_PARAMETER(GLint, width, i, GL_TEXTURE_WIDTH)
GLCC_TEX_LEVEL_PARAMETER(GLint, height, i, GL_TEXTURE_HEIGHT)
};

} // namespace detail

typedef detail::texture_target<GL_TEXTURE_1D, GL_TEXTURE_BINDING_1D> texture_1d;

struct texture_2d: detail::texture_target<GL_TEXTURE_2D, GL_TEXTURE_BINDING_2D>
{
	template<typename View>
	static inline void image(GLint level, GLint internalformat, GLint border,
			const View& view)
	{
		glTexImage2D(target_type, level, internalformat, view.width(),
				view.height(), border, color_traits<View>::layout,
				color_traits<View>::channel, &view[0]);
	}

	template<typename View>
	static inline void get_image(int lod, View& view)
	{
		glGetTexImage(target_type, lod, color_traits<View>::layout, //
				color_traits<View>::channel, &view[0]);
	}
};

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

#undef GLCC_TEX_PARAMETER

#endif /* GLCC_TEXTURE_HPP */
