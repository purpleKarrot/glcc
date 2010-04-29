/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>

#ifndef GLCC_CHECK_ERROR
#define GLCC_CHECK_ERROR()                                     \
    do {                                                       \
	    boost::system::error_code error = gl::error();         \
	    BOOST_CHECK_MESSAGE(!error, error.message());          \
    } while(::boost::test_tools::dummy_cond)                   \

#endif /* GLCC_CHECK_ERROR */
