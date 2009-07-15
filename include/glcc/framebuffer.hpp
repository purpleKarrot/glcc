/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_FRAMEBUFFER_HPP
#define GLCC_FRAMEBUFFER_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/detail/scoped_bind_base.hpp>
#include <glcc/texture.hpp>
#include <glcc/renderbuffer.hpp>

namespace gl
{
namespace detail
{

class framebuffer_status
{
public:
	framebuffer_status(GLenum target) :
		status(glCheckFramebufferStatus(target))
	{
	}

	friend std::ostream &operator<<(std::ostream &os,
			const framebuffer_status& bf_status)
	{
		switch (bf_status.status)
		{
		case GL_FRAMEBUFFER_COMPLETE:
			return os << "Framebuffer complete";
		case GL_FRAMEBUFFER_UNSUPPORTED:
			return os << "Unsupported framebuffer format";
		case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
			return os << "Framebuffer incomplete attachment";
		case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
			return os << "Framebuffer incomplete, missing attachment";
		case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
			return os << "Framebuffer incomplete, missing draw buffer";
		case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
			return os << "Framebuffer incomplete, missing read buffer";
		default:
			return os << "Unknown Framebuffer state";
		}
	}

private:
	GLenum status;
};

class framebuffer_base
{
GLCC_BASE(framebuffer_base, Framebuffer, Framebuffers)
};

template<GLenum Target, GLenum Binding>
struct framebuffer_target
{
	typedef framebuffer_base value_type;
	typedef scoped_bind_base<framebuffer_target, Binding> scoped_bind;

	static inline void bind(const framebuffer_base& buffer)
	{
		glBindFramebuffer(Target, buffer.name);
	}

	static inline bool complete()
	{
		return glCheckFramebufferStatus(Target) == GL_FRAMEBUFFER_COMPLETE;
	}

	static inline framebuffer_status status()
	{
		return framebuffer_status(Target);
	}

	static inline void attach(GLenum attachment, renderbuffer buffer)
	{
		glFramebufferRenderbuffer(Target, attachment, GL_RENDERBUFFER,
				buffer.name);
	}

	template<typename TexTarget>
	static inline void attach(GLenum attachment, //
			const texture_base& texture, int level)
	{
		glFramebufferTexture2D(Target, attachment, TexTarget::target_type,
				texture.name, level);

		//		glFramebufferTexture1D(Target, attachment, TexTarget::target_type,
		//				texture.name, level);
		//
		//		glFramebufferTexture3D(Target, attachment, TexTarget::target_type,
		//				texture.name, level, layer);
		//
		//		glFramebufferTextureLayer(Target, attachment, texture.name, level,
		//				layer);
	}
};

}// end namespace detail

typedef detail::framebuffer_target<GL_DRAW_FRAMEBUFFER, //
		GL_DRAW_FRAMEBUFFER_BINDING> draw_framebuffer;

typedef detail::framebuffer_target<GL_READ_FRAMEBUFFER, //
		GL_READ_FRAMEBUFFER_BINDING> read_framebuffer;

typedef detail::framebuffer_target<GL_FRAMEBUFFER, //
		GL_FRAMEBUFFER_BINDING> framebuffer_target;

GLCC_OBJECT(framebuffer)

} // namespace gl

#endif /* GLCC_FRAMEBUFFER_HPP */
