/*
 * gl_compile.cpp
 *
 *  Created on: 06.05.2009
 *      Author: daniel
 */

#include <boost/test/unit_test.hpp>
#include <glcc.hpp>

BOOST_AUTO_TEST_SUITE(compile)

BOOST_AUTO_TEST_CASE(main)
{
	gl::texture texture;
	gl::set<gl::texture> textures(5);

	gl::query query;
	gl::set<gl::query> queries(5);

	gl::vertex_array vertex_array;
	gl::set<gl::vertex_array> vertex_arrays(5);
	vertex_array.bind();
	vertex_arrays[2].bind();

	gl::renderbuffer renderbuffer;
	gl::set<gl::renderbuffer> renderbuffers(5);

	gl::framebuffer framebuffer;
	gl::set<gl::framebuffer> framebuffers(5);
}

BOOST_AUTO_TEST_SUITE_END()
