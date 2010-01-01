/*
 * vector.cpp
 *
 *  Created on: 29.07.2009
 *      Author: daniel
 */

#include <boost/test/unit_test.hpp>
#include <glcc/math/vector.hpp>
#include <glcc/detail/vector_stream.hpp>
#include <boost/la/all.hpp>
using namespace boost::la;

BOOST_AUTO_TEST_SUITE(math_vector)

BOOST_AUTO_TEST_CASE(lessThan)
{
	gl::vec2 a(1, 2);
	gl::vec2 b(2, 1);

static const	int v = vector_traits<gl::bvec2>::dim;
	BOOST_CHECK_EQUAL(v, 2);

//	BOOST_CHECK_EQUAL(gl::math::lessThan(a, b), gl::bvec2(true, false));
}

BOOST_AUTO_TEST_CASE(lessThanEqual)
{
}

BOOST_AUTO_TEST_CASE(greaterThan)
{
}

BOOST_AUTO_TEST_CASE(greaterThanEqual)
{
}

BOOST_AUTO_TEST_CASE(equal)
{
}

BOOST_AUTO_TEST_CASE(notEqual)
{
}

BOOST_AUTO_TEST_CASE(any)
{
}

BOOST_AUTO_TEST_CASE(all)
{
}

BOOST_AUTO_TEST_CASE(not_)
{
}

BOOST_AUTO_TEST_SUITE_END()
