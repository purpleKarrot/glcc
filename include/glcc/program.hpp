/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROGRAM_HPP
#define GLCC_PROGRAM_HPP

#include <glcc/program_base.hpp>
#include <glcc/detail/uniform.hpp>
#include <glcc/detail/get_uniform.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/stringize.hpp>

#define GLCC_PROGRAM(NAME, UNIFORMS)                                            \
    GLCC_PROGRAM_I(NAME, BOOST_PP_CAT(GLCC_PROGRAM_X UNIFORMS, 0))

#define GLCC_PROGRAM_X(x, y) ((x, y)) GLCC_PROGRAM_Y
#define GLCC_PROGRAM_Y(x, y) ((x, y)) GLCC_PROGRAM_X
#define GLCC_PROGRAM_X0
#define GLCC_PROGRAM_Y0

#define GLCC_uniform_type(tuple) BOOST_PP_TUPLE_ELEM(2, 0, tuple)
#define GLCC_uniform_name(tuple) BOOST_PP_TUPLE_ELEM(2, 1, tuple)
#define GLCC_uniform_str(tuple) BOOST_PP_STRINGIZE(GLCC_uniform_name(tuple))
#define GLCC_uniform_loc(tuple) BOOST_PP_CAT(GLCC_uniform_name(tuple), _loc)

#define GLCC_PROGRAM_I(NAME, UNIFORMS)                                          \
    class NAME : public gl::program                                             \
    {                                                                           \
		BOOST_PP_SEQ_FOR_EACH(GLCC_PROGRAM_LOC,, UNIFORMS)                      \
    public:                                                                     \
		bool link()                                                             \
		{                                                                       \
			if(!gl::program::link())                                            \
				return false;                                                   \
			BOOST_PP_SEQ_FOR_EACH(GLCC_PROGRAM_LOCATE,, UNIFORMS)               \
			return true;                                                        \
		}                                                                       \
		BOOST_PP_SEQ_FOR_EACH(GLCC_PROGRAM_SETGET,, UNIFORMS)                   \
    }

#define GLCC_PROGRAM_LOC(r, data, elem) GLuint GLCC_uniform_loc(elem);

#define GLCC_PROGRAM_LOCATE(r, data, elem)                                      \
	GLCC_uniform_loc(elem) =                                                    \
	glGetUniformLocation(this->name, GLCC_uniform_str(elem));

#define GLCC_PROGRAM_SETGET(r, data, elem)                                      \
	GLCC_uniform_type(elem) GLCC_uniform_name(elem)()                           \
	{                                                                           \
		GLCC_uniform_type(elem) value;                                          \
		gl::detail::get_uniform(name, GLCC_uniform_loc(elem), value);           \
		return value;                                                           \
	}                                                                           \
	void GLCC_uniform_name(elem)(GLCC_uniform_type(elem) const& value)          \
	{                                                                           \
		gl::detail::uniform(GLCC_uniform_loc(elem), value);                     \
	}

#endif /* GLCC_PROGRAM_HPP */
