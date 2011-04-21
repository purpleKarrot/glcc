/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/texture.hpp>
#include "detail/unit_test.hpp"

#include <glcc/extension/image_traits_gil.hpp>
#include <boost/gil/extension/io/png_io.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>

#include <glcc/extension/image_traits_sdl.hpp>
#include <SDL/SDL_image.h>

BOOST_AUTO_TEST_SUITE(texture)

BOOST_AUTO_TEST_CASE(gil)
{
	boost::gil::rgba8_image_t image;
	boost::gil::png_read_image("image.png", image);

	gl::texture_2d texture;
	texture.image(0, GL_RGB, 0, image);

	BOOST_CHECK_EQUAL(image.width(), texture.width(0));
	BOOST_CHECK_EQUAL(image.height(), texture.height(0));

	GLint width = texture.width(0);
	GLint height= texture.height(0);

	texture.generate_mipmap();

	boost::gil::rgb8_image_t image2(width/2, height/2);
	texture.get_image(1, image2);
	boost::gil::jpeg_write_view("image.jpeg", boost::gil::view(image2));
}

BOOST_AUTO_TEST_CASE(sdl)
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_Surface* image = IMG_Load("image.png");
	BOOST_REQUIRE_MESSAGE(image, "could not load image!");

	gl::texture_2d texture;
	texture.image(0, GL_RGB, 0, image);

	BOOST_CHECK_EQUAL(image->w, texture.width(0));
	BOOST_CHECK_EQUAL(image->h, texture.height(0));

	GLint width = texture.width(0);
	GLint height= texture.height(0);

	texture.generate_mipmap();

	boost::gil::rgb8_image_t image2(width/2, height/2);
	texture.get_image(1, image2);
	boost::gil::jpeg_write_view("image_sdl.jpeg", boost::gil::view(image2));

	IMG_Quit();
}

BOOST_AUTO_TEST_SUITE_END()
