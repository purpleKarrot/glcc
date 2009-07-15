/*
 * context.hpp
 *
 *  Created on: 12.07.2009
 *      Author: daniel
 */

#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

namespace gl
{

// glX
GLXContext create_context()
{
	GLXContext gl2Context = glXCreateContext(m_display, vi, 0, GL_TRUE);

	if (!gl2Context)
		return 0;

	PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribs =
			(PFNGLXCREATECONTEXTATTRIBSARBPROC) glXGetProcAddress(
					(GLubyte*) "glXCreateContextAttribsARB");

	if (!glXCreateContextAttribs)
		return gl2Context;

	int attribs[] = { GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
			GLX_CONTEXT_MINOR_VERSION_ARB, 0, 0 };

	gl3Context = glXCreateContextAttribs(m_display, framebufferConfig, 0, true,
			attribs);
	glXDestroyContext(m_display, gl2Context);

	return gl3Context;
}

// wgl
HGLRC create_context()
{
	HGLRC gl2Context = wglCreateContext(m_hdc);

	// TODO: store current context
	wglMakeCurrent(m_hdc, tmpContext);

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB =
			(PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress(
					"wglCreateContextAttribsARB");

	// TODO: restore stored context

	if (!wglCreateContextAttribsARB)
		return gl2Context;

	int attribs[] = { WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
			WGL_CONTEXT_MINOR_VERSION_ARB, 0, 0 };

	gl3Context = wglCreateContextAttribsARB(m_hdc, 0, attribs);
	wglDeleteContext(gl2Context);

	return gl3Context;
}

} // namespace gl


#endif /* CONTEXT_HPP_ */
