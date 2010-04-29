/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/extensions.hpp>
#include "../GL3Context.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_FIXTURE_TEST_SUITE(extensions, GL3Context)

template<typename In, typename Out>
void copy(const In& in, Out out)
{
	std::copy(in.begin(), in.end(), out);
}

BOOST_AUTO_TEST_CASE(main)
{
	BOOST_TEST_MESSAGE( "number of extensions: " << gl::extensions().size() );

	copy(gl::extensions(),
			std::ostream_iterator<const char*>(std::cout, ", "));
}

BOOST_AUTO_TEST_SUITE_END()
