/*
 * main.cpp
 *
 *  Created on: 01.12.2009
 *      Author: daniel
 */

#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test;

#include <GL/glut.h>

test_suite* init_unit_test_suite(int argc, char* argv[])
{
	framework::master_test_suite().p_name.value = "gl:: test suite";

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 500);
	glutCreateWindow("GLUT Window");

	return 0;
}
