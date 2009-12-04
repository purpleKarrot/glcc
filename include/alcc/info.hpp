/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_INFO_HPP
#define ALCC_INFO_HPP

#include <alcc/detail/al.hpp>

namespace al
{

inline const char* vendor()
{
	return alGetString(AL_VENDOR);
}

inline const char* version()
{
	return alGetString(AL_VERSION);
}

inline const char* renderer()
{
	return alGetString(AL_RENDERER);
}

inline const char* extensions()
{
	return alGetString(AL_EXTENSIONS);
}

} // namespace al

#endif /* ALCC_INFO_HPP */
