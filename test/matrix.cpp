/*
 * matrix.cpp
 *
 *  Created on: 02.08.2009
 *      Author: daniel
 */

#include <boost/la/all.hpp>
#include <boost/la/matrix_access.hpp>

#include <glcc/vector.hpp>
#include <glcc/matrix.hpp>
//#include <glcc/math/matrix.hpp>
#include <iostream>

using namespace boost::la;

std::ostream& operator<<(std::ostream&os, const gl::mat2x3& m)
{
	os << (m | A00) << " " << (m | A01) << " " << (m | A02) << " " << std::endl;
	os << (m | A10) << " " << (m | A11) << " " << (m | A12) << " " << std::endl;
	return os;
}

int main(int argc, char* argv[])
{
	gl::mat2x3 mat;

	//	mat[0][0] = 1;
	//	mat[0][1] = 1;
	//	mat[1][0] = 1;
	//	mat[1][1] = 1;

	//	mat[0] = gl::vec3(3);
	//	mat[1] = gl::vec3(2);
	//	mat[2] = gl::vec3(4);

	gl::mat2x3 m = mat / 2;

	std::cout << mat + m << std::endl;
}
