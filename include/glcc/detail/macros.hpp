/*
 * macros.hpp
 *
 *  Created on: 10.09.2008
 *      Author: daniel
 */

#ifndef GLCC_DETAIL_MACROS_HPP
#define GLCC_DETAIL_MACROS_HPP

#define GLCC_ENABLE(NAME) \
	inline void enable() { glEnable(NAME); } \
	inline void disable() { glDisable(NAME); } \
	inline bool is_enabled() { return glIsEnabled(NAME); }

#define GLCC_BASE(BASE, GLTS, GLTP) \
	public: \
	GLuint name; \
	BASE(GLuint n) : name(n) { /*assert(name == 0 || glIs##GLTS(name));*/ } \
	protected: \
	BASE() : name(0) {} \
	static void gen(GLsizei n, GLuint* p) { glGen##GLTP(n, p); } \
	static void del(GLsizei n, GLuint* p) { glDelete##GLTP(n, p); }

#define GLCC_OBJECT(OBJECT) \
	template<typename T> class set; \
	class OBJECT: public detail::OBJECT##_base \
	{ \
	typedef detail::OBJECT##_base base_type; \
	friend class set<OBJECT> ; \
	public: \
	OBJECT() { gen(1, &name); } \
	~OBJECT() { del(1, &name); } \
	};

#endif /* GLCC_DETAIL_MACROS_HPP */
