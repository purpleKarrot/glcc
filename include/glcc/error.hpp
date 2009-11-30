/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_ERROR_HPP
#define GLCC_ERROR_HPP

#include <glcc/detail/gl.hpp>
#include <boost/system/system_error.hpp>

namespace gl
{
namespace detail
{

struct error_category: boost::system::error_category
{
	const char* name() const;

	std::string message(int value) const;
};

} // namespace detail

boost::system::error_code error();

} // namespace gl

#endif /* GLCC_ERROR_HPP */
