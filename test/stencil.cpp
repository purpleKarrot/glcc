/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/stencil.hpp>
#include "detail/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(stencil)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::stencil::enable();
	BOOST_CHECK(gl::stencil::is_enabled());

	gl::stencil::disable();
	BOOST_CHECK(!gl::stencil::is_enabled());

	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(function)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(op)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(clear)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_CASE(mask)
{
	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_SUITE_END()
