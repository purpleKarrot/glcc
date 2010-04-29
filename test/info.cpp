/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/info.hpp>
#include "detail/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(info)

BOOST_AUTO_TEST_CASE(main)
{
	BOOST_TEST_MESSAGE( "vendor: " << gl::vendor() );
	BOOST_TEST_MESSAGE( "renderer: " << gl::renderer() );
	BOOST_TEST_MESSAGE( "version: " << gl::version() );
	BOOST_TEST_MESSAGE( "sl_version: " << gl::shading_language_version() );

	BOOST_TEST_MESSAGE( "major_version: " << gl::major_version() );
	BOOST_TEST_MESSAGE( "minor_version: " << gl::minor_version() );

	GLCC_CHECK_ERROR();
}

BOOST_AUTO_TEST_SUITE_END()
