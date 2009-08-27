/*
 * shader.cpp
 *
 *  Created on: 14.08.2009
 *      Author: daniel
 */

#include <glcc/matrix.hpp>
#include <glcc/program.hpp>

GLCC_PROGRAM(shader,(gl::mat3x4, desaturate))

shader myshader;

int main(int, char**)
{
	myshader.desaturate(3);

}
