/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/depth.hpp>
#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(depth)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::depth::enable();
	BOOST_CHECK(gl::depth::is_enabled());

	gl::depth::disable();
	BOOST_CHECK(!gl::depth::is_enabled());

	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(function)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(mask)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(range)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(clear)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
