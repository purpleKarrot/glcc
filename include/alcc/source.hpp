/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_SOURCE_HPP
#define ALCC_SOURCE_HPP

#include <alcc/detail/al.hpp>
#include <glcc/vector.hpp>
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


/**
 * SOURCE
 * Sources represent individual sound objects in 3D-space.
 * Sources take the PCM data provided in the specified Buffer,
 * apply Source-specific modifications, and then
 * submit them to be mixed according to spatial arrangement etc.
 */
class source
{
public:
	void play()
	{
		alSourcePlay(name);
	}

	void stop()
	{
		alSourceStop(name);
	}

	void rewind()
	{
		alSourceRewind(name);
	}

	void pause()
	{
		alSourcePause(name);
	}

public:
	void gain(float value)
	{
		alSourcef(name, AL_GAIN, value);
	}

	float gain() const
	{
		GLfloat value;
		alGetSourcef(name, AL_GAIN, &value);
		return value;
	}

	void min_gain(float value)
	{
		alSourcef(name, AL_MIN_GAIN, value);
	}

	float min_gain() const
	{
		GLfloat value;
		alGetSourcef(name, AL_MIN_GAIN, &value);
		return value;
	}

	void max_gain(float value)
	{
		alSourcef(name, AL_MAX_GAIN, value);
	}

	float max_gain() const
	{
		GLfloat value;
		alGetSourcef(name, AL_MAX_GAIN, &value);
		return value;
	}

	void position(gl::vec3 const& value)
	{
		alSource3f(name, AL_POSITION, value.x, value.y, value.z);
	}

	gl::vec3 position() const
	{
		gl::vec3 value;
		alGetSource3f(name, AL_POSITION, &value.x, &value.y, &value.z);
		return value;
	}

	void velocity(gl::vec3 const& value)
	{
		alSource3f(name, AL_VELOCITY, value.x, value.y, value.z);
	}

	gl::vec3 velocity() const
	{
		gl::vec3 value;
		alGetSource3f(name, AL_VELOCITY, &value.x, &value.y, &value.z);
		return value;
	}

	void direction(gl::vec3 const& value)
	{
		alSource3f(name, AL_DIRECTION, value.x, value.y, value.z);
	}

	gl::vec3 derection() const
	{
		gl::vec3 value;
		alGetSource3f(name, AL_DIRECTION, &value.x, &value.y, &value.z);
		return value;
	}

	void source_relative(bool value)
	{
		alSourcei(name, AL_SOURCE_RELATIVE, value);
	}

	bool source_relative() const
	{
		ALint value;
		alGetSourcei(name, AL_SOURCE_RELATIVE, &value);
		return value == AL_TRUE;
	}

	void reference_distance(float value)
	{
		alSourcef(name, AL_REFERENCE_DISTANCE, value);
	}

	float reference_distance() const
	{
		ALfloat value;
		alGetSourcef(name, AL_REFERENCE_DISTANCE, &value);
		return value;
	}

	void max_distance(float value)
	{
		alSourcef(name, AL_MAX_DISTANCE, value);
	}

	float max_distance() const
	{
		ALfloat value;
		alGetSourcef(name, AL_MAX_DISTANCE, &value);
		return value;
	}

	void rolloff_factor(float value)
	{
		alSourcef(name, AL_ROLLOFF_FACTOR, value);
	}

	float rolloff_factor() const
	{
		ALfloat value;
		alGetSourcef(name, AL_ROLLOFF_FACTOR, &value);
		return value;
	}

	void cone_inner_angle(float value)
	{
		alSourcef(name, AL_CONE_INNER_ANGLE, value);
	}

	float cone_inner_angle() const
	{
		ALfloat value;
		alGetSourcef(name, AL_CONE_INNER_ANGLE, &value);
		return value;
	}

	void cone_outer_angle(float value)
	{
		alSourcef(name, AL_CONE_OUTER_ANGLE, value);
	}

	float cone_outer_angle() const
	{
		ALfloat value;
		alGetSourcef(name, AL_CONE_OUTER_ANGLE, &value);
		return value;
	}

	void cone_outer_gain(float value)
	{
		alSourcef(name, AL_CONE_OUTER_GAIN, value);
	}

	float cone_outer_gain() const
	{
		ALfloat value;
		alGetSourcef(name, AL_CONE_OUTER_GAIN, &value);
		return value;
	}

	void pitch(float value)
	{
		alSourcef(name, AL_PITCH, value);
	}

	float pitch() const
	{
		ALfloat value;
		alGetSourcef(name, AL_PITCH, &value);
		return value;
	}

	void looping(bool value)
	{
		alSourcei(name, AL_LOOPING, value);
	}

	bool looping() const
	{
		ALint value;
		alGetSourcei(name, AL_LOOPING, &value);
		return value == AL_TRUE;
	}

	void msec_offset(int value)
	{
		alSourcei(name, AL_MSEC_OFFSET, value);
	}

	int msec_offset() const
	{
		ALint value;
		alGetSourcei(name, AL_MSEC_OFFSET, &value);
		return value;
	}

	void byte_offset(int value)
	{
		alSourcei(name, AL_BYTE_OFFSET, value);
	}

	int byte_offset() const
	{
		ALint value;
		alGetSourcei(name, AL_BYTE_OFFSET, &value);
		return value;
	}

	void sample_offset(int value)
	{
		alSourcei(name, AL_SAMPLE_OFFSET, value);
	}

	int sample_offset() const
	{
		ALint value;
		alGetSourcei(name, AL_SAMPLE_OFFSET, &value);
		return value;
	}

	//	 * Attached Buffer                   AL_BUFFER               ALint

	int state() const
	{
		ALint value;
		alGetSourcei(name, AL_SOURCE_STATE, &value);
		return value;
	}

	int buffers_queued() const
	{
		ALint value;
		alGetSourcei(name, AL_BUFFERS_QUEUED, &value);
		return value;
	}

	int buffers_processed() const
	{
		ALint value;
		alGetSourcei(name, AL_BUFFERS_PROCESSED, &value);
		return value;
	}

private:
	ALuint name;
};

} // namespace al

#endif /* ALCC_SOURCE_HPP */
