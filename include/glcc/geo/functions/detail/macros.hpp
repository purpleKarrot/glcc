/*
 * macros.hpp
 *
 *  Created on: Jun 6, 2009
 *      Author: daniel
 */

#ifndef MACROS_HPP_
#define MACROS_HPP_

// Type, Function, Parameter
#define GLCC_COMPONENT_WISE(T, F, P) \
	T F(T P); \
	inline vector<T, 2> F(const vector<T, 2>& P) \
	{ \
		return vector<T, 2>(F(P.x()), F(P.y())); \
	} \
	inline vector<T, 3> F(const vector<T, 3>& P) \
	{ \
		return vector<T, 3>(F(P.x()), F(P.y()), F(P.z())); \
	} \
	inline vector<T, 4> F(const vector<T, 4>& P) \
	{ \
		return vector<T, 4>(F(P.x()), F(P.y()), F(P.z()), F(P.w())); \
	} \
	inline T F(T P)

// Type, Function, Parameter
#define GLCC_COMPONENT_WISE_STD(F, P) \
	using std::F; \
	template<typename T> \
	inline vector<T, 2> F(const vector<T, 2>& P) \
	{ \
		return vector<T, 2>(F(P.x()), F(P.y())); \
	} \
	template<typename T> \
	inline vector<T, 3> F(const vector<T, 3>& P) \
	{ \
		return vector<T, 3>(F(P.x()), F(P.y()), F(P.z())); \
	} \
	template<typename T> \
	inline vector<T, 4> F(const vector<T, 4>& P) \
	{ \
		return vector<T, 4>(F(P.x()), F(P.y()), F(P.z()), F(P.w())); \
	}

#endif /* MACROS_HPP_ */
