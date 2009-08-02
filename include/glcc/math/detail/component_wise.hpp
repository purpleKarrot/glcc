/*
 * macros.hpp
 *
 *  Created on: Jun 6, 2009
 *      Author: daniel
 */

#ifndef GLCC_MATH_DETAIL_COMPONENT_WISE_HPP
#define GLCC_MATH_DETAIL_COMPONENT_WISE_HPP

#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#define GLCC_COMPONENT_WISE(TEMPLATE, RETURN, FUNCTION, BSEQ)                  \
    GLCC_COMPONENT_WISE_I(TEMPLATE, RETURN, FUNCTION,                          \
    		BOOST_PP_CAT(GLCC_COMPONENT_WISE_X BSEQ, 0))

#define GLCC_COMPONENT_WISE_X(T, P) ((T, P)) GLCC_COMPONENT_WISE_Y
#define GLCC_COMPONENT_WISE_Y(T, P) ((T, P)) GLCC_COMPONENT_WISE_X
#define GLCC_COMPONENT_WISE_X0
#define GLCC_COMPONENT_WISE_Y0

#define GLCC_CW_T(TP) BOOST_PP_TUPLE_ELEM(2, 0, TP)
#define GLCC_CW_P(TP) BOOST_PP_TUPLE_ELEM(2, 1, TP)

// expand to: T1 P1, T2 P2, T3 P3
#define GLCC_CW_PARAM(r, data, I, TP) \
	BOOST_PP_COMMA_IF(I) GLCC_CW_T(TP) GLCC_CW_P(TP)

// expand to: const gl::detail::vector2<T1>& P1,
//            const gl::detail::vector2<T2>& P2,
//            const gl::detail::vector2<T3>& P3
#define GLCC_CW_VEC_PARAM(r, D, I, TP) BOOST_PP_COMMA_IF(I) \
	BOOST_PP_CAT(const gl::detail::vector, D)<GLCC_CW_T(TP)>& GLCC_CW_P(TP)

// expand to: P1.x(), P2.x(), P3.x()
#define GLCC_CW_COMPONENT(r, D, I, TP) BOOST_PP_COMMA_IF(I) GLCC_CW_P(TP).D()

#define GLCC_COMPONENT_WISE_I(TEMPLATE, RETURN, FUNCTION, SEQ)                 \
	TEMPLATE RETURN FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_PARAM,, SEQ));    \
	TEMPLATE inline gl::detail::vector2<RETURN> FUNCTION(                      \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 2, SEQ))                \
	{                                                                          \
		return gl::detail::vector2<RETURN>(                                    \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ))); \
	}                                                                          \
	TEMPLATE inline gl::detail::vector3<RETURN> FUNCTION(                      \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 3, SEQ))                \
	{                                                                          \
		return gl::detail::vector3<RETURN>(                                    \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, z, SEQ))); \
	}                                                                          \
	TEMPLATE inline gl::detail::vector4<RETURN> FUNCTION(                      \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 4, SEQ))                \
	{                                                                          \
		return gl::detail::vector4<RETURN>(                                    \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, z, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, w, SEQ))); \
	}                                                                          \
	TEMPLATE inline RETURN FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_PARAM,, SEQ))

// 2nd argument is either vector or value
#define GLCC_COMPONENT_WISE_2_M(TEMPLATE, RETURN, FUNCTION, T1, P1, T2, P2)    \
	TEMPLATE RETURN FUNCTION(T1 P1, T2 P2);                                    \
	TEMPLATE inline gl::detail::vector2<RETURN> FUNCTION(                      \
			const gl::detail::vector2<T1>& P1,                                 \
			const gl::detail::vector2<T2>& P2)                                 \
	{                                                                          \
		return gl::detail::vector2<RETURN>(                                    \
				FUNCTION(P1.x(), P2.x()), FUNCTION(P1.y(), P2.y()));           \
	}                                                                          \
	TEMPLATE inline gl::detail::vector2<RETURN> FUNCTION(                      \
			const gl::detail::vector2<T1>& P1, T2 P2)                          \
	{                                                                          \
		return gl::detail::vector2<RETURN>(                                    \
				FUNCTION(P1.x(), P2), FUNCTION(P1.y(), P2));                   \
	}                                                                          \
	TEMPLATE inline gl::detail::vector3<RETURN> FUNCTION(                      \
			const gl::detail::vector3<T1>& P1,                                 \
			const gl::detail::vector3<T2>& P2)                                 \
	{                                                                          \
		return gl::detail::vector3<RETURN>(FUNCTION(P1.x(), P2.x()),           \
				FUNCTION(P1.y(), P2.y()), FUNCTION(P1.z(), P2.z()));           \
	}                                                                          \
	TEMPLATE inline gl::detail::vector3<RETURN> FUNCTION(                      \
			const gl::detail::vector3<T1>& P1, T2 P2)                          \
	{                                                                          \
		return gl::detail::vector3<RETURN>(FUNCTION(P1.x(), P2),               \
				FUNCTION(P1.y(), P2), FUNCTION(P1.z(), P2));                   \
	}                                                                          \
	TEMPLATE inline gl::detail::vector4<RETURN> FUNCTION(                      \
			const gl::detail::vector4<T1>& P1,                                 \
			const gl::detail::vector4<T2>& P2)                                 \
	{                                                                          \
		return gl::detail::vector4<RETURN>(                                    \
				FUNCTION(P1.x(), P2.x()), FUNCTION(P1.y(), P2.y()),            \
				FUNCTION(P1.z(), P2.z()), FUNCTION(P1.w(), P2.w()));           \
	}                                                                          \
	TEMPLATE inline gl::detail::vector4<RETURN> FUNCTION(                      \
			const gl::detail::vector4<T1>& P1, T2 P2)                          \
	{                                                                          \
		return gl::detail::vector4<RETURN>(                                    \
				FUNCTION(P1.x(), P2), FUNCTION(P1.y(), P2),                    \
				FUNCTION(P1.z(), P2), FUNCTION(P1.w(), P2));                   \
	}                                                                          \
	TEMPLATE inline RETURN FUNCTION(T1 P1, T2 P2)

#endif /* GLCC_MATH_DETAIL_COMPONENT_WISE_HPP */
