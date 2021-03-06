#include <SDL.h>
#include <iostream>
#include <glcc.hpp>
#include <GL/glu.h>

#include <boost/gil/extension/io/png_io.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>

#include "texture.h"

SDL_WindowID window;
SDL_GLContext context;

void set_tex_param(GLenum target, const struct TexParameter* param)
{
	//	gl::texture_2d::base_level(param->base_level);
	//	gl::texture_2d::border_color(param->border_color);
	//	gl::texture_2d::compare_mode(param->compare_mode);
	//	gl::texture_2d::compare_func(param->compare_func);
	//	gl::texture_2d::lod_bias(param->lod_bias);
	//	gl::texture_2d::mag_filter(param->mag_filter);
	//	gl::texture_2d::max_level(param->max_level);
	//	gl::texture_2d::max_lod(param->max_lod);
	//	gl::texture_2d::min_filter(param->min_filter);
	//	gl::texture_2d::min_lod(param->min_lod);
	//	//gl::texture_2d::swizzle_rgba(param->swizzle_rgba);
	//	gl::texture_2d::wrap_s(param->wrap_s);
	//	gl::texture_2d::wrap_t(param->wrap_t);
	//	gl::texture_2d::wrap_r(param->wrap_r);

	glTexParameteri(target, GL_TEXTURE_BASE_LEVEL, param->base_level);
	glTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, param->border_color);
	glTexParameteri(target, GL_TEXTURE_COMPARE_MODE, param->compare_mode);
	glTexParameteri(target, GL_TEXTURE_COMPARE_FUNC, param->compare_func);
	glTexParameterf(target, GL_TEXTURE_LOD_BIAS, param->lod_bias);
	glTexParameteri(target, GL_TEXTURE_MAG_FILTER, param->mag_filter);
	glTexParameteri(target, GL_TEXTURE_MAX_LEVEL, param->max_level);
	glTexParameterf(target, GL_TEXTURE_MAX_LOD, param->max_lod);
	glTexParameteri(target, GL_TEXTURE_MIN_FILTER, param->min_filter);
	glTexParameterf(target, GL_TEXTURE_MIN_LOD, param->min_lod);
	//	glTexParameteriv(target, GL_TEXTURE_SWIZZLE_RGBA, param->swizzle_rgba);
	glTexParameteri(target, GL_TEXTURE_WRAP_S, param->wrap_s);
	glTexParameteri(target, GL_TEXTURE_WRAP_T, param->wrap_t);
	glTexParameteri(target, GL_TEXTURE_WRAP_R, param->wrap_r);
}

void get_tex_param(GLenum target, struct TexParameter* param)
{
	param->base_level = gl::texture_2d::base_level();
	glGetTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, param->border_color);
	param->compare_mode = gl::texture_2d::compare_mode();
	param->compare_func = gl::texture_2d::compare_func();
	param->lod_bias = gl::texture_2d::lod_bias();

	glGetTexParameteriv(target, GL_TEXTURE_BASE_LEVEL, &param->base_level);
	glGetTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, param->border_color);
	glGetTexParameteriv(target, GL_TEXTURE_COMPARE_MODE,
			(GLint*) &param->compare_mode);
	glGetTexParameteriv(target, GL_TEXTURE_COMPARE_FUNC,
			(GLint*) &param->compare_func);
	glGetTexParameterfv(target, GL_TEXTURE_LOD_BIAS, &param->lod_bias);
	glGetTexParameteriv(target, GL_TEXTURE_MAG_FILTER,
			(GLint*) &param->mag_filter);
	glGetTexParameteriv(target, GL_TEXTURE_MAX_LEVEL, &param->max_level);
	glGetTexParameterfv(target, GL_TEXTURE_MAX_LOD, &param->max_lod);
	glGetTexParameteriv(target, GL_TEXTURE_MIN_FILTER,
			(GLint*) &param->min_filter);
	glGetTexParameterfv(target, GL_TEXTURE_MIN_LOD, &param->min_lod);
	//	glGetTexParameteriv(target, GL_TEXTURE_SWIZZLE_RGBA, param->swizzle_rgba);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_S, (GLint*) &param->wrap_s);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_T, (GLint*) &param->wrap_t);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_R, (GLint*) &param->wrap_r);

	GLint val;

	glGetTexLevelParameteriv(target, 0, GL_TEXTURE_WIDTH, &val);
	printf("GL_TEXTURE_WIDTH 0 : %d\n", val);
	glGetTexLevelParameteriv(target, 0, GL_TEXTURE_HEIGHT, &val);
	printf("GL_TEXTURE_HEIGHT 0 : %d\n", val);
	glGetTexLevelParameteriv(target, 0, GL_TEXTURE_DEPTH, &val);
	printf("GL_TEXTURE_DEPTH 0 : %d\n", val);

	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_WIDTH, &val);
	printf("GL_TEXTURE_WIDTH 1 : %d\n", val);
	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_HEIGHT, &val);
	printf("GL_TEXTURE_HEIGHT 1 : %d\n", val);
	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_DEPTH, &val);
	printf("GL_TEXTURE_DEPTH 1 : %d\n", val);

	glGenerateMipmap(target);

	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_WIDTH, &val);
	printf("GL_TEXTURE_WIDTH 1 : %d\n", val);
	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_HEIGHT, &val);
	printf("GL_TEXTURE_HEIGHT 1 : %d\n", val);
	glGetTexLevelParameteriv(target, 1, GL_TEXTURE_DEPTH, &val);
	printf("GL_TEXTURE_DEPTH 1 : %d\n", val);
}

void print_tex_param(const struct TexParameter* param)
{
	printf("\n");
	printf("GL_TEXTURE_BASE_LEVEL: %d\n", param->base_level);
	printf("GL_TEXTURE_BORDER_COLOR: %f %f %f %f\n", param->border_color[0],
			param->border_color[1], param->border_color[2],
			param->border_color[3]);
	printf("GL_TEXTURE_COMPARE_MODE: %x\n", param->compare_mode);
	printf("GL_TEXTURE_COMPARE_FUNC: %x\n", param->compare_func);
	printf("GL_TEXTURE_LOD_BIAS: %f\n", param->lod_bias);
	printf("GL_TEXTURE_MAG_FILTER: %x\n", param->mag_filter);
	printf("GL_TEXTURE_MAX_LEVEL: %d\n", param->max_level);
	printf("GL_TEXTURE_MAX_LOD: %f\n", param->max_lod);
	printf("GL_TEXTURE_MIN_FILTER: %x\n", param->min_filter);
	printf("GL_TEXTURE_MIN_LOD: %f\n", param->min_lod);
	printf("GL_TEXTURE_WRAP_S: %x\n", param->wrap_s);
	printf("GL_TEXTURE_WRAP_T: %x\n", param->wrap_t);
	printf("GL_TEXTURE_WRAP_R: %x\n", param->wrap_r);
	printf("\n");
}

void DrawGLScene()
{
	boost::gil::rgb8_image_t image;
	boost::gil::png_read_image("image.png", image);

	gl::texture texture;
	gl::texture_2d::bind(texture);
	gl::texture_2d::image(0, GL_RGB, 0, boost::gil::view(image));

	struct TexParameter tex_param;
	get_tex_param(GL_TEXTURE_2D, &tex_param);
	print_tex_param(&tex_param);

	GLint width = gl::texture_2d::width(1);
	GLint height = gl::texture_2d::height(1);

	boost::gil::rgb8_image_t image2(width, height);
	gl::texture_2d::get_image(1, boost::gil::view(image2));
	boost::gil::png_write_view("image2.png", boost::gil::view(image2));
}

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return -1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow("SDL GL3 Window", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL
					| SDL_WINDOW_SHOWN);

	if (!window)
	{
		SDL_Quit();
		fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
		return -2;
	}

	context = SDL_GL_CreateContext(window);

	SDL_GL_SetSwapInterval(1);

	DrawGLScene();

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 1;
}
