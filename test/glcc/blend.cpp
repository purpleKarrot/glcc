/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/blend.hpp>
#include <glcc/error.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/la/all.hpp>

namespace boost
{
namespace la
{

inline std::ostream& operator<<(std::ostream& os, gl::vec4 const& v)
{
	return os << "( " << (v | X) << " " << (v | Y) << " " << (v | Z) << " "
			<< (v | W) << " )";
}

}
}

using namespace boost::la;

BOOST_AUTO_TEST_SUITE(blend)

BOOST_AUTO_TEST_CASE(enable)
{
	gl::blend::enable();
	BOOST_CHECK(gl::blend::is_enabled());

	gl::blend::disable();
	BOOST_CHECK(!gl::blend::is_enabled());

	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(color)
{
	gl::vec4 color = { 1.f, 0.5f, 0.f, 0.7f };

	gl::blend::color(color);
	BOOST_CHECK_EQUAL(gl::blend::color(), color);

	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(equation)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_CASE(function)
{
	boost::system::error_code error = gl::error();
	BOOST_CHECK_MESSAGE(!error, error.message());
}

BOOST_AUTO_TEST_SUITE_END()
