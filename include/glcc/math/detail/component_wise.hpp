/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_DETAIL_COMPONENT_WISE_HPP
#define GLCC_MATH_DETAIL_COMPONENT_WISE_HPP

#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>
#include <glcc/math/detail/vector_param.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#define GLCC_COMPONENT_WISE(RETURN, FUNCTION, BSEQ)                            \
    GLCC_COMPONENT_WISE_I(RETURN, FUNCTION,                                    \
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
	detail::vector_param<GLCC_CW_T(TP), D>::type GLCC_CW_P(TP)

// expand to: P1.x(), P2.x(), P3.x()
#define GLCC_CW_COMPONENT(r, D, I, TP) BOOST_PP_COMMA_IF(I) GLCC_CW_P(TP).D

#define GLCC_COMPONENT_WISE_I(RETURN, FUNCTION, SEQ)                           \
	RETURN FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_PARAM,, SEQ));             \
	inline gl::detail::vector<RETURN, 2> FUNCTION(                             \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 2, SEQ))                \
	{                                                                          \
		return gl::detail::vector<RETURN, 2>(                                  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ))); \
	}                                                                          \
	inline gl::detail::vector<RETURN, 3> FUNCTION(                             \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 3, SEQ))                \
	{                                                                          \
		return gl::detail::vector<RETURN, 3>(                                  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, z, SEQ))); \
	}                                                                          \
	inline gl::detail::vector<RETURN, 4> FUNCTION(                             \
			BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_VEC_PARAM, 4, SEQ))                \
	{                                                                          \
		return gl::detail::vector<RETURN, 4>(                                  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, x, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, y, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, z, SEQ)),  \
				FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_COMPONENT, w, SEQ))); \
	}                                                                          \
	inline RETURN FUNCTION(BOOST_PP_SEQ_FOR_EACH_I(GLCC_CW_PARAM,, SEQ))

//#define GLCC_COMPONENT_WISE_E(RETURN, FUNCTION, T1, P1, T2, P2)              \
//	RETURN FUNCTION(T1 P1, T2 P2);                                             \
//	inline gl::detail::vector2<RETURN> FUNCTION(                               \
//			const gl::detail::vector2<T1>& P1, T2 P2)                          \
//	{                                                                          \
//		return gl::detail::vector2<RETURN>(                                    \
//				FUNCTION(P1.x(), P2), FUNCTION(P1.y(), P2));                   \
//	}                                                                          \
//	inline gl::detail::vector3<RETURN> FUNCTION(                               \
//			const gl::detail::vector3<T1>& P1, T2 P2)                          \
//	{                                                                          \
//		return gl::detail::vector3<RETURN>(FUNCTION(P1.x(), P2),               \
//				FUNCTION(P1.y(), P2), FUNCTION(P1.z(), P2));                   \
//	}                                                                          \
//	inline gl::detail::vector4<RETURN> FUNCTION(                               \
//			const gl::detail::vector4<T1>& P1, T2 P2)                          \
//	{                                                                          \
//		return gl::detail::vector4<RETURN>(                                    \
//				FUNCTION(P1.x(), P2), FUNCTION(P1.y(), P2),                    \
//				FUNCTION(P1.z(), P2), FUNCTION(P1.w(), P2));                   \
//	}

#endif /* GLCC_MATH_DETAIL_COMPONENT_WISE_HPP */
