/*
 * GL3Context.cpp
 *
 *  Created on: 30.12.2009
 *      Author: daniel
 */

#include "GL3Context.hpp"
#include <stdexcept>

GL3Context::GL3Context()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("Unable to initialize SDL");

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
		throw std::runtime_error("Unable to create window");
	}

	context = SDL_GL_CreateContext(window);

	SDL_GL_SetSwapInterval(1);
}

GL3Context::~GL3Context()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GL3Context::swap_buffers(Uint32 ms)
{
	SDL_GL_SwapWindow(window);
	SDL_Delay(ms);
}
