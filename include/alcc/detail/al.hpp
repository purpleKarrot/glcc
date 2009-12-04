/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_DETAIL_AL_HPP
# define ALCC_DETAIL_AL_HPP
#
# ifdef _WIN32
#
#  include <al.h>
#  include <alc.h>
#
# elif defined(__APPLE__)
#
#  include <OpenAL/al.h>
#  include <OpenAL/alc.h>
#
# else
#
#  include <AL/al.h>
#  include <AL/alc.h>
#
# endif
#
#endif /* ALCC_DETAIL_AL_HPP */
