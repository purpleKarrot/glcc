/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/extensions.hpp>
#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(extension)

BOOST_AUTO_TEST_CASE(main)
{
	BOOST_TEST_MESSAGE( "number of extensions: " << gl::extensions().size() );

//	std::copy(gl::extensions().begin(), gl::extensions().end(),
//			std::ostream_iterator<const char*>(std::cout, ", "));

	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
