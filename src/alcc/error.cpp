/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <alcc/error.hpp>

namespace al
{
namespace detail
{

const char* error_category::name() const
{
	return "OpenAL";
}

std::string error_category::message(int value) const
{
	// No Error.
	if (value == AL_NO_ERROR)
		return "No error";

	// Invalid Name paramater passed to AL call.
	if (value == AL_INVALID_NAME)
		return "Invalid Name paramater passed to AL call";

	// Invalid parameter passed to AL call.
	if (value == AL_INVALID_ENUM)
		return "Enum argument out of range";

	// Invalid enum parameter value.
	if (value == AL_INVALID_VALUE)
		return "Numeric argument out of range";

	// Illegal call.
	if (value == AL_INVALID_OPERATION)
		return "Operation illegal in current state";

	// No mojo.
	if (value == AL_OUT_OF_MEMORY)
		return "Not enough memory left to execute command";

	return "Unknown error";
}

} // namespace detail

boost::system::error_code error()
{
	static al::detail::error_category instance;
	return boost::system::error_code(alGetError(), instance);
}

} // namespace gl
