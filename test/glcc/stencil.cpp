/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/stencil.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(stencil)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::stencil::enable();
	BOOST_CHECK(gl::stencil::is_enabled());

	gl::stencil::disable();
	BOOST_CHECK(!gl::stencil::is_enabled());
}

BOOST_AUTO_TEST_CASE(function)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(op)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(clear)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(mask)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
