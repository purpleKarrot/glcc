/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef ALCC_ERROR_HPP
#define ALCC_ERROR_HPP

//#include <system_error>
#include <alcc/detail/al.hpp>
#include <boost/system/system_error.hpp>

namespace al
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

} // namespace al

#endif /* ALCC_ERROR_HPP */
