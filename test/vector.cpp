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
	gl::vec3 v(1, 2, 3);

	//vec.yx()[0] = 0.5f;

	std::cout << gl::math::normalize(v) << std::endl;

	std::cout << v.yyzx() << std::endl;
}
