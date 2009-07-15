/*
 * pointers.hpp
 *
 *  Created on: 30.06.2009
 *      Author: daniel
 */

#ifndef POINTERS_HPP_
#define POINTERS_HPP_

// Version 1.0
extern PFNGLCULLFACEPROC glCullFace = NULL;
extern PFNGLFRONTFACEPROC glFrontFace = NULL;
extern PFNGLHINTPROC glHint = NULL;
extern PFNGLLINEWIDTHPROC glLineWidth = NULL;
extern PFNGLPOINTSIZEPROC glPointSize = NULL;
extern PFNGLPOLYGONMODEPROC glPolygonMode = NULL;
extern PFNGLSCISSORPROC glScissor = NULL;
extern PFNGLTEXPARAMETERFPROC glTexParameterf = NULL;
extern PFNGLTEXPARAMETERFVPROC glTexParameterfv = NULL;
extern PFNGLTEXPARAMETERIPROC glTexParameteri = NULL;
extern PFNGLTEXPARAMETERIVPROC glTexParameteriv = NULL;
extern PFNGLTEXIMAGE1DPROC glTexImage1D = NULL;
extern PFNGLTEXIMAGE2DPROC glTexImage2D = NULL;
extern PFNGLDRAWBUFFERPROC glDrawBuffer = NULL;
extern PFNGLCLEARPROC glClear = NULL;
extern PFNGLCLEARCOLORPROC glClearColor = NULL;
extern PFNGLCLEARSTENCILPROC glClearStencil = NULL;
extern PFNGLCLEARDEPTHPROC glClearDepth = NULL;
extern PFNGLSTENCILMASKPROC glStencilMask = NULL;
extern PFNGLCOLORMASKPROC glColorMask = NULL;
extern PFNGLDEPTHMASKPROC glDepthMask = NULL;
extern PFNGLDISABLEPROC glDisable = NULL;
extern PFNGLENABLEPROC glEnable = NULL;
extern PFNGLFINISHPROC glFinish = NULL;
extern PFNGLFLUSHPROC glFlush = NULL;
extern PFNGLBLENDFUNCPROC glBlendFunc = NULL;
extern PFNGLLOGICOPPROC glLogicOp = NULL;
extern PFNGLSTENCILFUNCPROC glStencilFunc = NULL;
extern PFNGLSTENCILOPPROC glStencilOp = NULL;
extern PFNGLDEPTHFUNCPROC glDepthFunc = NULL;
extern PFNGLPIXELSTOREFPROC glPixelStoref = NULL;
extern PFNGLPIXELSTOREIPROC glPixelStorei = NULL;
extern PFNGLREADBUFFERPROC glReadBuffer = NULL;
extern PFNGLREADPIXELSPROC glReadPixels = NULL;
extern PFNGLGETBOOLEANVPROC glGetBooleanv = NULL;
extern PFNGLGETDOUBLEVPROC glGetDoublev = NULL;
extern PFNGLGETERRORPROC glGetError = NULL;
extern PFNGLGETFLOATVPROC glGetFloatv = NULL;
extern PFNGLGETINTEGERVPROC glGetIntegerv = NULL;
extern PFNGLGETSTRINGPROC glGetString = NULL;
extern PFNGLGETTEXIMAGEPROC glGetTexImage = NULL;
extern PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv = NULL;
extern PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv = NULL;
extern PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv = NULL;
extern PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv = NULL;
extern PFNGLISENABLEDPROC glIsEnabled = NULL;
extern PFNGLDEPTHRANGEPROC glDepthRange = NULL;
extern PFNGLVIEWPORTPROC glViewport = NULL;

// Version 1.1
extern PFNGLDRAWARRAYSPROC glDrawArrays = NULL;
extern PFNGLDRAWELEMENTSPROC glDrawElements = NULL;
extern PFNGLGETPOINTERVPROC glGetPointerv = NULL;
extern PFNGLPOLYGONOFFSETPROC glPolygonOffset = NULL;
extern PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = NULL;
extern PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = NULL;
extern PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = NULL;
extern PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = NULL;
extern PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = NULL;
extern PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = NULL;
extern PFNGLBINDTEXTUREPROC glBindTexture = NULL;
extern PFNGLDELETETEXTURESPROC glDeleteTextures = NULL;
extern PFNGLGENTEXTURESPROC glGenTextures = NULL;
extern PFNGLISTEXTUREPROC glIsTexture = NULL;

// Version 1.2
extern PFNGLBLENDCOLORPROC glBlendColor = NULL;
extern PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
extern PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;
extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;

// Version 1.3
extern PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;

// Version 1.4
extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
extern PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
extern PFNGLPOINTPARAMETERIPROC glPointParameteri = NULL;
extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv = NULL;

// Version 1.5
extern PFNGLGENQUERIESPROC glGenQueries = NULL;
extern PFNGLDELETEQUERIESPROC glDeleteQueries = NULL;
extern PFNGLISQUERYPROC glIsQuery = NULL;
extern PFNGLBEGINQUERYPROC glBeginQuery = NULL;
extern PFNGLENDQUERYPROC glEndQuery = NULL;
extern PFNGLGETQUERYIVPROC glGetQueryiv = NULL;
extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = NULL;
extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = NULL;
extern PFNGLBINDBUFFERPROC glBindBuffer = NULL;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
extern PFNGLGENBUFFERSPROC glGenBuffers = NULL;
extern PFNGLISBUFFERPROC glIsBuffer = NULL;
extern PFNGLBUFFERDATAPROC glBufferData = NULL;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = NULL;
extern PFNGLMAPBUFFERPROC glMapBuffer = NULL;
extern PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = NULL;
extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = NULL;

// Version 2.0
extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = NULL;
extern PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = NULL;
extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = NULL;
extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = NULL;
extern PFNGLATTACHSHADERPROC glAttachShader = NULL;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
extern PFNGLCOMPILESHADERPROC glCompileShader = NULL;
extern PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
extern PFNGLCREATESHADERPROC glCreateShader = NULL;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
extern PFNGLDELETESHADERPROC glDeleteShader = NULL;
extern PFNGLDETACHSHADERPROC glDetachShader = NULL;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = NULL;
extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = NULL;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = NULL;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
extern PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
extern PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
extern PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
extern PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = NULL;
extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = NULL;
extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = NULL;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = NULL;
extern PFNGLISPROGRAMPROC glIsProgram = NULL;
extern PFNGLISSHADERPROC glIsShader = NULL;
extern PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
extern PFNGLSHADERSOURCEPROC glShaderSource = NULL;
extern PFNGLUSEPROGRAMPROC glUseProgram = NULL;
extern PFNGLUNIFORM1FPROC glUniform1f = NULL;
extern PFNGLUNIFORM2FPROC glUniform2f = NULL;
extern PFNGLUNIFORM3FPROC glUniform3f = NULL;
extern PFNGLUNIFORM4FPROC glUniform4f = NULL;
extern PFNGLUNIFORM1IPROC glUniform1i = NULL;
extern PFNGLUNIFORM2IPROC glUniform2i = NULL;
extern PFNGLUNIFORM3IPROC glUniform3i = NULL;
extern PFNGLUNIFORM4IPROC glUniform4i = NULL;
extern PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
extern PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
extern PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
extern PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
extern PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
extern PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
extern PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
extern PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = NULL;
extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = NULL;
extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = NULL;
extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = NULL;
extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = NULL;
extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = NULL;
extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = NULL;
extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = NULL;
extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = NULL;
extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = NULL;
extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = NULL;
extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = NULL;
extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = NULL;
extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = NULL;
extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = NULL;
extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = NULL;
extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = NULL;
extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = NULL;
extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = NULL;
extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = NULL;
extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = NULL;
extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = NULL;
extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = NULL;
extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = NULL;
extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = NULL;
extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = NULL;
extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = NULL;
extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = NULL;
extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = NULL;
extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = NULL;
extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = NULL;
extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = NULL;
extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = NULL;
extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = NULL;
extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = NULL;
extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = NULL;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;

// Version 2.1
extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = NULL;
extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = NULL;
extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = NULL;
extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = NULL;
extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = NULL;
extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = NULL;

// Version 3.0
extern PFNGLCOLORMASKIPROC glColorMaski = NULL;
extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v = NULL;
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v = NULL;
extern PFNGLENABLEIPROC glEnablei = NULL;
extern PFNGLDISABLEIPROC glDisablei = NULL;
extern PFNGLISENABLEDIPROC glIsEnabledi = NULL;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = NULL;
extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = NULL;
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange = NULL;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase = NULL;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = NULL;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying =
		NULL;
extern PFNGLCLAMPCOLORPROC glClampColor = NULL;
extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = NULL;
extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = NULL;
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = NULL;
extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = NULL;
extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = NULL;
extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv = NULL;
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = NULL;
extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = NULL;
extern PFNGLUNIFORM1UIPROC glUniform1ui = NULL;
extern PFNGLUNIFORM2UIPROC glUniform2ui = NULL;
extern PFNGLUNIFORM3UIPROC glUniform3ui = NULL;
extern PFNGLUNIFORM4UIPROC glUniform4ui = NULL;
extern PFNGLUNIFORM1UIVPROC glUniform1uiv = NULL;
extern PFNGLUNIFORM2UIVPROC glUniform2uiv = NULL;
extern PFNGLUNIFORM3UIVPROC glUniform3uiv = NULL;
extern PFNGLUNIFORM4UIVPROC glUniform4uiv = NULL;
extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = NULL;
extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = NULL;
extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = NULL;
extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = NULL;
extern PFNGLCLEARBUFFERIVPROC glClearBufferiv = NULL;
extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = NULL;
extern PFNGLCLEARBUFFERFVPROC glClearBufferfv = NULL;
extern PFNGLCLEARBUFFERFIPROC glClearBufferfi = NULL;
extern PFNGLGETSTRINGIPROC glGetStringi = NULL;

// Version 3.1
extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = NULL;
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = NULL;
extern PFNGLTEXBUFFERPROC glTexBuffer = NULL;
extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = NULL;

// GL_ARB_framebuffer_object
extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer = NULL;
extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = NULL;
extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = NULL;
extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = NULL;
extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = NULL;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = NULL;
extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer = NULL;
extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = NULL;
extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = NULL;
extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = NULL;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = NULL;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = NULL;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = NULL;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = NULL;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = NULL;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC
		glGetFramebufferAttachmentParameteriv = NULL;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap = NULL;
extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = NULL;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC
		glRenderbufferStorageMultisample = NULL;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = NULL;

// GL_ARB_map_buffer_range
extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange = NULL;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = NULL;

// GL_ARB_vertex_array_object
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
extern PFNGLISVERTEXARRAYPROC glIsVertexArray = NULL;

// GL_ARB_uniform_buffer_object
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = NULL;
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = NULL;
extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = NULL;
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = NULL;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = NULL;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = NULL;
extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = NULL;

// GL_ARB_copy_buffer
extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = NULL;

#endif /* POINTERS_HPP_ */
