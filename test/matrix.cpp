/*
 * matrix.cpp
 *
 *  Created on: 02.08.2009
 *      Author: daniel
 */

#include <glcc/vector.hpp>
#include <glcc/matrix.hpp>
#include <glcc/math/matrix.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	gl::mat3x2 mat;

//	mat[0][0] = 1;
//	mat[0][1] = 1;
//	mat[1][0] = 1;
//	mat[1][1] = 1;

	mat[0] = gl::vec3(3);
	mat[1] = gl::vec3(2);
//	mat[2] = gl::vec3(4);

	gl::mat3x2 m = mat / 2;

	std::cout << mat + m << std::endl;
}
