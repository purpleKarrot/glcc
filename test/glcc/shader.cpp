/*
 * shader.cpp
 *
 *  Created on: 14.08.2009
 *      Author: daniel
 */

#include <boost/test/unit_test.hpp>
#include <glcc/matrix.hpp>
#include <glcc/program.hpp>

BOOST_AUTO_TEST_SUITE(shader_program)

BOOST_AUTO_TEST_CASE(main)
{
	GLCC_PROGRAM(, (gl::mat3x4, desaturate)) myshader;

	gl::mat3x4 m;

	myshader.desaturate(m);
}

BOOST_AUTO_TEST_SUITE_END()
