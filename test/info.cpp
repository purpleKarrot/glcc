/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/info.hpp>
#include <glcc/extension.hpp>
#include <GL/glut.h>
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 500);
	glutCreateWindow("error.cpp");

	std::cout << "vendor: " << gl::vendor() << std::endl;
	std::cout << "renderer: " << gl::renderer() << std::endl;
	std::cout << "version: " << gl::version() << std::endl;
	std::cout << "sl_version: " << gl::shading_language_version() << std::endl;

//	std::copy(extensions::begin(), extensions::end(),
//			std::ostream_iterator<const char*>(std::cout, " "));
}
