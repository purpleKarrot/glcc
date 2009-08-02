/*
 * vector.cpp
 *
 *  Created on: 29.07.2009
 *      Author: daniel
 */

#include <glcc/vector.hpp>
//#include <glcc/math/common.hpp>
//#include <glcc/math/exponential.hpp>
//#include <glcc/math/geometric.hpp>
//#include <glcc/math/matrix.hpp>
//#include <glcc/math/trigonometric.hpp>
//#include <glcc/math/vector.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
	gl::vec2 vec(2.f, 3.f);

	vec.yx() = vec;

	std::cout << vec.x() << " " << vec.y() << std::endl;
}
