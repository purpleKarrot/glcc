#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>

#include "texture.h"

void set_tex_param(GLenum target, const struct TexParameter* param)
{
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
//	glGenerateMipmap(target);

	glGetTexParameteriv(target, GL_TEXTURE_BASE_LEVEL, &param->base_level);
	glGetTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, param->border_color);
	glGetTexParameteriv(target, GL_TEXTURE_COMPARE_MODE, &param->compare_mode);
	glGetTexParameteriv(target, GL_TEXTURE_COMPARE_FUNC, &param->compare_func);
	glGetTexParameterfv(target, GL_TEXTURE_LOD_BIAS, &param->lod_bias);
	glGetTexParameteriv(target, GL_TEXTURE_MAG_FILTER, &param->mag_filter);
	glGetTexParameteriv(target, GL_TEXTURE_MAX_LEVEL, &param->max_level);
	glGetTexParameterfv(target, GL_TEXTURE_MAX_LOD, &param->max_lod);
	glGetTexParameteriv(target, GL_TEXTURE_MIN_FILTER, &param->min_filter);
	glGetTexParameterfv(target, GL_TEXTURE_MIN_LOD, &param->min_lod);
	//	glGetTexParameteriv(target, GL_TEXTURE_SWIZZLE_RGBA, param->swizzle_rgba);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_S, &param->wrap_s);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_T, &param->wrap_t);
	glGetTexParameteriv(target, GL_TEXTURE_WRAP_R, &param->wrap_r);

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

void InitGL(int Width, int Height)
{
	glEnable(GL_TEXTURE_2D);

	glViewport(0, 0, Width, Height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene()
{
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	load_image("slideshow-play.png");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-1.5f, 0.0f, -6.0f);

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2i(1, 0);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2i(1, 1);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2i(0, 1);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

	glTranslatef(3.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2i(1, 0);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2i(1, 1);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2i(0, 1);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

	SDL_GL_SwapBuffers();
	SDL_Delay(500);

	struct TexParameter tex_param;
	get_tex_param(GL_TEXTURE_2D, &tex_param);
	print_tex_param(&tex_param);

	glDeleteTextures(1, &texture);
}

int load_image(const char* filename)
{
	GLuint texture;
	SDL_Surface * surface;
	GLenum texture_format;
	GLint bytes_per_pixel;

	surface = IMG_Load(filename);
	if (!surface)
		return -1;

	if (surface->format->palette)
	{
		printf("error: image has a palette\n");
		return -1;
	}

	if ((surface->w & (surface->w - 1)) != 0)
		printf("warning: image's width is not a power of 2\n");

	if ((surface->h & (surface->h - 1)) != 0)
		printf("warning: image's height is not a power of 2\n");

	bytes_per_pixel = surface->format->BytesPerPixel;
	printf("info: number of colors: %d\n", bytes_per_pixel);

	printf(
			"rgba mask: %08x %08x %08x %08x\n", //
			surface->format->Rmask, surface->format->Gmask,
			surface->format->Bmask, surface->format->Amask);

	if (bytes_per_pixel == 4)
	{
		if (surface->format->Rmask == 0x000000ff)
			texture_format = GL_RGBA;
		else
			texture_format = 0x8000;//GL_ABGR;
	}
	else if (bytes_per_pixel == 3)
	{
		if (surface->format->Rmask == 0x000000ff)
			texture_format = GL_RGB;
		else
			texture_format = GL_BGR;
	}
	else
	{
		printf("warning: the image is not truecolor... "
			"this will probably break\n");
		return -1;
	}

	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glTexImage2D(GL_TEXTURE_2D, 0, bytes_per_pixel, surface->w, surface->h, 0,
			texture_format, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_FreeSurface(surface);
}

int main(int argc, char *argv[])
{
	int done;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return -1;
	}

	if (SDL_SetVideoMode(640, 480, 0, SDL_OPENGL) == NULL)
	{
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		return -2;
	}

	InitGL(640, 480);

	DrawGLScene();

	SDL_Quit();
	return 1;
}
