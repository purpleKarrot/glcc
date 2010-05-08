/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <SDL.h>
#include <GL3/gl3w.h>
#include <stdexcept>
#include <boost/test/unit_test.hpp>

class GL3Context
{
public:
	GL3Context()
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

		gl3wInit();
//		glGetError(); // glewInit() does some crap...

		SDL_GL_SetSwapInterval(1);
	}

	~GL3Context()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

private:
	SDL_WindowID window;
	SDL_GLContext context;
};

BOOST_GLOBAL_FIXTURE(GL3Context)
