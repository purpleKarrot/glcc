/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/texture.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/extension/io/png_io.hpp>
#include "detail/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(texture)

BOOST_AUTO_TEST_CASE(load)
{
	boost::gil::rgb8_image_t image;
	boost::gil::png_read_image("image.png", image);

	gl::texture texture;
	gl::texture_2d::bind(texture);
	gl::texture_2d::image(0, GL_RGB, 0, boost::gil::view(image));

	BOOST_CHECK_EQUAL(image.width(), gl::texture_2d::width(0));
	BOOST_CHECK_EQUAL(image.height(), gl::texture_2d::height(0));

	GLint width = gl::texture_2d::width(0);
	GLint height= gl::texture_2d::height(0);

//	boost::gil::rgb8_image_t image2(width, height);
//	gl::texture_2d::get_image(0, boost::gil::view(image2));
//
//	BOOST_CHECK_EQUAL(image, image2);
}

BOOST_AUTO_TEST_SUITE_END()
