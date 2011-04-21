/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_ERROR_HPP
#define GLCC_ERROR_HPP

#include <GL/gl.h>
#include <boost/system/system_error.hpp>

namespace gl
{

boost::system::error_code error();

} // namespace gl

#endif /* GLCC_ERROR_HPP */
