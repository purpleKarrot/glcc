/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

// GL_ARB_framebuffer_object
GLCC_PROC(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer)
GLCC_PROC(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer)
GLCC_PROC(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers)
GLCC_PROC(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers)
GLCC_PROC(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage)
GLCC_PROC(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv)
GLCC_PROC(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer)
GLCC_PROC(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer)
GLCC_PROC(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers)
GLCC_PROC(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers)
GLCC_PROC(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus)
GLCC_PROC(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D)
GLCC_PROC(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D)
GLCC_PROC(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D)
GLCC_PROC(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer)
GLCC_PROC(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv)
GLCC_PROC(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap)
GLCC_PROC(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer)
GLCC_PROC(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample)
GLCC_PROC(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer)

// GL_ARB_map_buffer_range
GLCC_PROC(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange)
GLCC_PROC(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange)

// GL_ARB_vertex_array_object
GLCC_PROC(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray)
GLCC_PROC(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays)
GLCC_PROC(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays)
GLCC_PROC(PFNGLISVERTEXARRAYPROC, glIsVertexArray)

// GL_ARB_uniform_buffer_object
GLCC_PROC(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices)
GLCC_PROC(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv)
GLCC_PROC(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName)
GLCC_PROC(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex)
GLCC_PROC(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv)
GLCC_PROC(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName)
GLCC_PROC(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding)

// GL_ARB_copy_buffer
GLCC_PROC(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData)

// GL_ARB_sync
GLCC_PROC(PFNGLFENCESYNCPROC, glFenceSync)
GLCC_PROC(PFNGLISSYNCPROC, glIsSync)
GLCC_PROC(PFNGLDELETESYNCPROC, glDeleteSync)
GLCC_PROC(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync)
GLCC_PROC(PFNGLWAITSYNCPROC, glWaitSync)
GLCC_PROC(PFNGLGETINTEGER64VPROC, glGetInteger64v)
GLCC_PROC(PFNGLGETSYNCIVPROC, glGetSynciv)
