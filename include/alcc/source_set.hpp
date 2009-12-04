/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_SOURCE_SET_HPP
#define ALCC_SOURCE_SET_HPP

#include <alcc/source.hpp>
#include <glcc/set.hpp>

namespace al
{

struct source_set: gl::set<source>
{
	source_set(std::size_t size) :
		gl::set<source>(size)
	{
	}

	void play()
	{
		alSourcePlayv(count_, elements_);
	}

	void stop()
	{
		alSourceStopv(count_, elements_);
	}

	void rewind()
	{
		alSourceRewindv(count_, elements_);
	}

	void pause()
	{
		alSourcePausev(count_, elements_);
	}
};

} // namespace al

#endif /* ALCC_SOURCE_SET_HPP */
