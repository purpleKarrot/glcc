/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/blend.hpp>
#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(hint)

BOOST_AUTO_TEST_CASE(line_smooth_hint)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(polygon_smooth_hint)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(texture_compression_hint)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(fragment_shader_derivative_hint)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
