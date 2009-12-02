/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <boost/test/unit_test.hpp>
#include <glcc/info.hpp>

BOOST_AUTO_TEST_SUITE(info)

BOOST_AUTO_TEST_CASE(main)
{
	BOOST_TEST_MESSAGE( "vendor: " << gl::vendor() );
	BOOST_TEST_MESSAGE( "renderer: " << gl::renderer() );
	BOOST_TEST_MESSAGE( "version: " << gl::version() );
	BOOST_TEST_MESSAGE( "sl_version: " << gl::shading_language_version() );

	//	std::copy(extensions::begin(), extensions::end(),
	//			std::ostream_iterator<const char*>(std::cout, " "));
}

BOOST_AUTO_TEST_SUITE_END()
