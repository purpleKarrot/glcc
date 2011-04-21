/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_TEST_DETAIL_UNIT_TEST_HPP
#define GLCC_TEST_DETAIL_UNIT_TEST_HPP

#define BOOST_TEST_MODULE glcc
#include <boost/test/unit_test.hpp>

#include <SDL/SDL.h>
#include <stdexcept>
#include <glcc/error.hpp>

#define GLCC_CHECK_ERROR()                                     \
    do {                                                       \
        boost::system::error_code error = gl::error();         \
        BOOST_CHECK_MESSAGE(!error, error.message());          \
    } while(::boost::test_tools::dummy_cond)                   \

class opengl_context
{
public:
	opengl_context()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			throw std::runtime_error("Unable to initialize SDL");

		// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		// window = SDL_CreateWindow("SDL GL3 Window",
		// 		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512,
		// 		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		surface = SDL_SetVideoMode(512, 512, 24, SDL_OPENGL);

		if (!surface /*!window*/)
		{
			SDL_Quit();
			throw std::runtime_error("Unable to create window");
		}

		// context = SDL_GL_CreateContext(window);

		// SDL_GL_SetSwapInterval(1);
	}

	~opengl_context()
	{
		// SDL_GL_DeleteContext(context);
		// SDL_DestroyWindow(window);
		SDL_Quit();
	}

private:
	// SDL_WindowID window;
	// SDL_GLContext context;
	SDL_Surface* surface;
};

BOOST_GLOBAL_FIXTURE(opengl_context)

#endif /* GLCC_TEST_DETAIL_UNIT_TEST_HPP */
