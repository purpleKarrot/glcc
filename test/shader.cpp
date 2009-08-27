/*
 * shader.cpp
 *
 *  Created on: 14.08.2009
 *      Author: daniel
 */

#include <glcc/matrix.hpp>
#include <glcc/program.hpp>

int main(int, char**)
{
	GLCC_PROGRAM(, (gl::mat3x4, desaturate)) myshader;

	myshader.desaturate(3);
}
