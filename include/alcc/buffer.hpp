/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_BUFFER_HPP
#define ALCC_BUFFER_HPP

#include <alcc/detail/al.hpp>
//#include <glcc/detail/macros.hpp>

namespace al
{
//namespace detail
//{
//
//class buffer_base
//{
//GLCC_BASE(buffer_base, Buffer, Buffers)
//};
//
//} // namespace detail

//GLCC_OBJECT(buffer)

class buffer
{
public:

	void data(ALenum format, const ALvoid* data, ALsizei size, ALsizei freq)
	{
		alBufferData(name, format, data, size, freq);
	}

	int frequency() const
	{
		ALint value;
		alGetBufferi(name, AL_FREQUENCY, &value);
		return value;
	}

	int size() const
	{
		ALint value;
		alGetBufferi(name, AL_SIZE, &value);
		return value;
	}

	int bits() const
	{
		ALint value;
		alGetBufferi(name, AL_BITS, &value);
		return value;
	}

	int channels() const
	{
		ALint value;
		alGetBufferi(name, AL_CHANNELS, &value);
		return value;
	}

private:
	ALuint name;
};

} // namespace al

#endif /* ALCC_BUFFER_HPP */
