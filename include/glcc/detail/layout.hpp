/*
 * layout.hpp
 *
 *  Created on: 29.08.2008
 *      Author: daniel
 */

#ifndef LAYOUT_HPP_
#define LAYOUT_HPP_

#include "gl.hpp"
#include <boost/gil/gray.hpp>
#include <boost/gil/rgba.hpp>

namespace gl
{
namespace detail
{

typedef boost::mpl::vector1<boost::gil::red_t> red_t;
typedef boost::mpl::vector1<boost::gil::green_t> green_t;
typedef boost::mpl::vector1<boost::gil::blue_t> blue_t;
typedef boost::mpl::vector1<boost::gil::alpha_t> alpha_t;
typedef boost::mpl::vector2<boost::gil::gray_color_t , boost::gil::alpha_t>
		luminance_alpha_t;

typedef boost::gil::layout<red_t> red_layout_t;
typedef boost::gil::layout<green_t> green_layout_t;
typedef boost::gil::layout<blue_t> blue_layout_t;
typedef boost::gil::layout<alpha_t> alpha_layout_t;
typedef boost::gil::layout<luminance_alpha_t> luminance_alpha_layout_t;

//GLCC_DEFINE_LAYOUT_TRAITS(red_t, GL_RED)
//GLCC_DEFINE_LAYOUT_TRAITS(green_t, GL_GREEN)
//GLCC_DEFINE_LAYOUT_TRAITS(blue_t, GL_BLUE)
//GLCC_DEFINE_LAYOUT_TRAITS(alpha_t, GL_ALPHA)
//GLCC_DEFINE_LAYOUT_TRAITS(luminance_alpha_t, GL_LUMINANCE_ALPHA)

} // namespace detail
} // namespace gl

#endif /* LAYOUT_HPP_ */
