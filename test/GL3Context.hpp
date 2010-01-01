/*
 * GL3Context.hpp
 *
 *  Created on: 30.12.2009
 *      Author: daniel
 */

#ifndef GL3CONTEXT_HPP
#define GL3CONTEXT_HPP

#include <SDL.h>

class GL3Context
{
public:
	GL3Context();
	~GL3Context();

	void swap_buffers(Uint32 ms);

private:
	SDL_WindowID window;
	SDL_GLContext context;
};

#endif /* GL3CONTEXT_HPP */
