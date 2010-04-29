/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/depth.hpp>
#include "detail/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(depth)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::depth::enable();
	BOOST_CHECK(gl::depth::is_enabled());

	gl::depth::disable();
	BOOST_CHECK(!gl::depth::is_enabled());

	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(function)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(mask)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(range)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(clear)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_SUITE_END()
