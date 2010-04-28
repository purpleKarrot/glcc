/*
 * texture.h
 *
 *  Created on: 24.04.2010
 *      Author: daniel
 */

#ifndef TEXTURE_H
#define TEXTURE_H

struct header
{
	int dimension; // dimension 1,2,3, compressed bool

};

struct TexParameter
{
	GLint base_level;
	GLfloat border_color[4];
	GLenum compare_mode;
	GLenum compare_func;
	GLfloat lod_bias;
	GLenum mag_filter;
	GLint max_level;
	GLfloat max_lod;
	GLenum min_filter;
	GLfloat min_lod;
//	GLenum swizzle_rgba[4];
	GLenum wrap_s;
	GLenum wrap_t;
	GLenum wrap_r;
};

struct TexImage
{
	GLenum target;
	GLint level;
	GLint internalformat;
	GLsizei width;
	GLsizei height; //* only used in 2D and 3D
	GLsizei depth; //** only used in 3D
	GLint border;
	GLenum format; //only used when uncompressed
	GLenum type; //only used when uncompressed
	GLsizei imageSize; // only needed when compressed
	//GLvoid* data;
};

#endif /* TEXTURE_H */
