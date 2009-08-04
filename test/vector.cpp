/*
 * vector.cpp
 *
 *  Created on: 29.07.2009
 *      Author: daniel
 */

#include <glcc/vector.hpp>
#include <glcc/math.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
	gl::vec2 vec(0.4f, 2.3f);

	//vec.yx()[0] = 0.5f;

	std::cout << vec.x() << " " << vec.y() << std::endl;
}
