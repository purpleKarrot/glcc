/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_LISTENER_HPP
#define ALCC_LISTENER_HPP

#include <alcc/detail/al.hpp>
#include <glcc/vector.hpp>

namespace al
{
namespace listener
{

inline void gain(float value)
{
	alListenerf(AL_GAIN, value);
}

inline float gain()
{
	ALfloat value;
	alGetListenerf(AL_GAIN, &value);
	return value;
}

inline void position(gl::vec3 const& value)
{
	alListener3f(AL_POSITION, value.x, value.y, value.z);
}

inline gl::vec3 position()
{
	gl::vec3 value;
	alGetListener3f(AL_POSITION, &value.x, &value.y, &value.z);
	return value;
}

inline void velocity(gl::vec3 const& value)
{
	alListener3f(AL_VELOCITY, value.x, value.y, value.z);
}

inline gl::vec3 velocity()
{
	gl::vec3 value;
	alGetListener3f(AL_VELOCITY, &value.x, &value.y, &value.z);
	return value;
}

inline void orientation(gl::vec3 const& forward, gl::vec3 const& up)
{
	ALfloat value[6] = { forward.x, forward.y, forward.z, up.x, up.y, up.z };
	alListenerfv(AL_ORIENTATION, value);
}

inline std::pair<gl::vec3, gl::vec3> orientation()
{
	ALfloat value[6];
	alGetListenerfv(AL_ORIENTATION, value);
	return std::make_pair(gl::vec3(value[0], value[1], value[2]), //
			gl::vec3(value[3], value[4], value[5]));
}

} // namespace listener
} // namespace al

#endif /* ALCC_LISTENER_HPP */
