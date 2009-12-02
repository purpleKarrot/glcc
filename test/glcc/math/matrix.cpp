/*
 * matrix.cpp
 *
 *  Created on: 01.12.2009
 *      Author: daniel
 */

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <glcc/vector.hpp>
#include <glcc/detail/vector_stream.hpp>
#include <glcc/math.hpp>
#include <glcc/matrix.hpp>

#include <boost/la/all.hpp>
using namespace boost::la;

std::ostream& operator<<(std::ostream&os, const gl::mat4& m)
{
	for (int i=0; i<16; ++i)
		os << reinterpret_cast<const float*>(m.data)[i] << " ";

	return os;
}

BOOST_AUTO_TEST_SUITE(gl_matrix)

BOOST_AUTO_TEST_CASE(test)
{
	gl::vec3 v(1, 2, 3);

	gl::mat4 mat = v|trans_matrix;

	std::cout << mat << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
