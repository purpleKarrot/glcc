/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_GLOBAL_HPP
#define ALCC_GLOBAL_HPP

#include <alcc/detail/al.hpp>

namespace al
{

/// Doppler scale.  Default 1.0
inline void doppler_factor(float value)
{
	alDopplerFactor(value);
}

inline float doppler_factor()
{
	return alGetFloat(AL_DOPPLER_FACTOR);
}

/// Tweaks speed of propagation.
inline void doppler_velocity(float value)
{
	alDopplerVelocity(value);
}

inline float doppler_velocity()
{
	alGetFloat(AL_DOPPLER_VELOCITY);
}

/// Speed of Sound in units per second
inline void speed_of_sound(float value)
{
	alSpeedOfSound(value);
}

inline float speed_of_sound()
{
	alGetFloat(AL_SPEED_OF_SOUND);
}

enum distance_model_t // : ALenum
{
	none = AL_NONE, //
	inverse_distance = AL_INVERSE_DISTANCE,
	inverse_distance_clamped = AL_INVERSE_DISTANCE_CLAMPED, //
	linear_distance = AL_LINEAR_DISTANCE, //
	linear_distance_clamped = AL_LINEAR_DISTANCE_CLAMPED, //
	exponent_distance = AL_EXPONENT_DISTANCE, //
	exponent_distance_clamped = AL_EXPONENT_DISTANCE_CLAMPED
};

inline void distance_model(distance_model_t value)
{
	alDistanceModel(value);
}

inline distance_model_t distance_model()
{
	return alGetInteger(AL_DISTANCE_MODEL);
}

} // namespace al

#endif /* ALCC_GLOBAL_HPP */
