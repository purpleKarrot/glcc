/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/logic.hpp>
#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(logic)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::logic::enable();
	BOOST_CHECK(gl::logic::is_enabled());

	gl::logic::disable();
	BOOST_CHECK(!gl::logic::is_enabled());
}

BOOST_AUTO_TEST_CASE(op)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
