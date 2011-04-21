/**************************************************************/
/* Copyright (c) 2008-2011 Daniel Pfeifer                     */
/*                                                            */
/* Distributed under the Boost Software License, Version 1.0. */
/**************************************************************/

#ifndef GLCC_TEXTURE_HPP
#define GLCC_TEXTURE_HPP

#include <GL/gl.h>
#include <glcc/vec.hpp>
#include <boost/utility/enable_if.hpp>
#include <glcc/detail/image_traits.hpp>
#include <glcc/detail/texture_traits.hpp>

#define GLCC_TEX_PARAMETER(type, function, suffix, pname)                      \
    void function(type param)                                                  \
    {                                                                          \
        glBindTexture(Target, name);                                           \
        glTexParameter##suffix(Target, pname, param);                          \
     /* glTextureParameter##suffix##EXT(name, Target, pname, param); */        \
    }                                                                          \
    type function()                                                            \
    {                                                                          \
        type value;                                                            \
        glBindTexture(Target, name);                                           \
        glGetTexParameter##suffix##v(Target, pname, &value);                   \
     /* glGetTextureParameter##suffix##vEXT(name, Target, pname, &value); */   \
        return value;                                                          \
    }                                                                          \

#define GLCC_TEX_LEVEL_PARAMETER(type, function, suffix, pname)                \
    type function(int level)                                                   \
    {                                                                          \
	    type value;                                                            \
        glBindTexture(Target, name);                                           \
        glGetTexLevelParameter##suffix##v(Target, level, pname, &value);       \
        return value;                                                          \
    }                                                                          \

namespace gl
{

template<GLenum Target>
class texture
{
public:
	texture()
	{
		glGenTextures(1, &name);
	}

	~texture()
	{
		glDeleteTextures(1, &name);
	}

	void generate_mipmap()
	{
		// glGenerateTextureMipmapEXT(name, Target);
		glBindTexture(Target, name);
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
	void border_color(const GLfloat color[4])
	{
		glBindTexture(Target, name);
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

	GLCC_TEX_LEVEL_PARAMETER(GLint, width, i, GL_TEXTURE_WIDTH)
	GLCC_TEX_LEVEL_PARAMETER(GLint, height, i, GL_TEXTURE_HEIGHT)
	GLCC_TEX_LEVEL_PARAMETER(GLint, depth, i, GL_TEXTURE_DEPTH)

	template<typename Image>
	typename boost::enable_if<detail::is_1d_image<Image> >::type
	image(GLint level, GLint format, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glTexImage1D(Target, level, format,
				detail::image_traits<Image>::width(img), border,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_2d_image<Image> >::type
	image(GLint level, GLint format, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glTexImage2D(Target, level, format,
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img), border,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_3d_image<Image> >::type
	image(GLint level, GLint format, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glTexImage3D(Target, level, format,
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::depth(img), border,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_1d_image<Image> >::type
	compressed_image(GLint level, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexImage1D(Target, level,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::width(img), border,
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_2d_image<Image> >::type
	compressed_image(GLint level, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexImage2D(Target, level,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img), border,
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_3d_image<Image> >::type
	compressed_image(GLint level, GLint border, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexImage3D(Target, level,
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::depth(img), border,
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_1d_image<Image> >::type
	sub_image(int level, int offset, const Image& img)
	{
		glBindTexture(Target, name);
		glTexSubImage1D(Target, level, offset,
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_2d_image<Image> >::type
	sub_image(int level, const ivec2& offset, const Image& img)
	{
		glBindTexture(Target, name);
		glTexSubImage2D(Target, level, offset.a[0], offset.a[1],
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_3d_image<Image> >::type
	sub_image(int level, const ivec3& offset, const Image& img)
	{
		glBindTexture(Target, name);
		glTexSubImage3D(Target, level, offset.a[0], offset.a[1], offset.a[2],
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::depth(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::type(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_1d_image<Image> >::type
	compressed_sub_image(int level, int offset, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexSubImage1D(Target, level, offset,
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_2d_image<Image> >::type
	compressed_sub_image(int level, const ivec2& offset, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexSubImage2D(Target, level, offset.a[0], offset.a[1],
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	template<typename Image>
	typename boost::enable_if<detail::is_3d_image<Image> >::type
	compressed_sub_image(int level, const ivec3& offset, const Image& img)
	{
		glBindTexture(Target, name);
		glCompressedTexSubImage3D(Target, level, offset.a[0], offset.a[1], offset.a[2],
				detail::image_traits<Image>::width(img),
				detail::image_traits<Image>::height(img),
				detail::image_traits<Image>::depth(img),
				detail::image_traits<Image>::format(img),
				detail::image_traits<Image>::size(img),
				detail::image_traits<Image>::data(img));
	}

	//	void CopyTexImage1D( enum target, int level,
	//	   enum internalformat, int x, int y, sizei width,
	//	   int border );
	//	void CopyTexImage2D( enum target, int level,
	//	   enum internalformat, int x, int y, sizei width,
	//	   sizei height, int border );
	//	void CopyTexSubImage3D( enum target, int level,
	//	   int xoffset, int yoffset, int zoffset, int x, int y,
	//	   sizei width, sizei height );

	//	void CopyTexSubImage1D( enum target, int level,
	//	   int xoffset, int x, int y, sizei width );
	//	void CopyTexSubImage2D( enum target, int level,
	//	   int xoffset, int yoffset, int x, int y, sizei width,
	//	   sizei height );

	template<typename Image>
	void get_image(int level, Image& image)
	{
//		assert(width(level) == detail::image_traits<Image>::width(img));
//		assert(height(level) == detail::image_traits<Image>::height(img));
//		assert(depth(level) == detail::image_traits<Image>::depth(img));

		glBindTexture(Target, name);
		glGetTexImage(Target, level, detail::image_traits<Image>::format(image),
				detail::image_traits<Image>::type(image),
				detail::image_traits<Image>::data(image));
	}

	template<typename Image>
	void get_compressed_image(int lod, Image& image)
	{
		glBindTexture(Target, name);
		glGetCompressedTexImage(Target, lod,
				detail::image_traits<Image>::data(image));
	}

private:
	GLuint name;
};

typedef texture<GL_TEXTURE_2D> texture_2d;
typedef texture<GL_TEXTURE_RECTANGLE> texture_rectangle;

} // namespace gl

#undef GLCC_TEX_PARAMETER
#undef GLCC_TEX_LEVEL_PARAMETER

#endif /* GLCC_TEXTURE_HPP */
