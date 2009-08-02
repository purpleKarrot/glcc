/*
 * vector.cpp
 *
 *  Created on: 29.07.2009
 *      Author: daniel
 */

#include <glcc/vector.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	gl::vec2 vec(2.f, 3.f);

	vec.yx() = vec;

	std::cout << vec.x() << " " << vec.y() << std::endl;
}
