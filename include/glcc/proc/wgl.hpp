/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License,  Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

typedef BOOL (WINAPI * PFNWGLCOPYCONTEXTPROC) (HGLRC,  HGLRC,  UINT);
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTPROC) (HDC);
typedef HGLRC (WINAPI * wglCreateLayerContext) (HDC, int);
typedef BOOL (WINAPI * wglDeleteContext) (HGLRC);
typedef BOOL (WINAPI * wglDescribeLayerPlane) (HDC, int, int, UINT, LPLAYERPLANEDESCRIPTOR);
typedef HGLRC (WINAPI * wglGetCurrentContext) (void);
typedef HDC (WINAPI * wglGetCurrentDC) (void);
typedef int (WINAPI * wglGetLayerPaletteEntries) (HDC, int, int, int, COLORREF*);
typedef PROC (WINAPI * wglGetProcAddress) (LPCSTR);
typedef BOOL (WINAPI * wglMakeCurrent) (HDC, HGLRC);
typedef BOOL (WINAPI * wglRealizeLayerPalette) (HDC, int, BOOL);
typedef int (WINAPI * wglSetLayerPaletteEntries) (HDC, int, int, int, const COLORREF*);
typedef BOOL (WINAPI * wglShareLists) (HGLRC, HGLRC);
typedef BOOL (WINAPI * wglSwapLayerBuffers) (HDC, UINT);
typedef BOOL (WINAPI * wglUseFontBitmapsA) (HDC, DWORD, DWORD, DWORD);
typedef BOOL (WINAPI * wglUseFontBitmapsW) (HDC, DWORD, DWORD, DWORD);
typedef BOOL (WINAPI * wglUseFontOutlinesA) (HDC, DWORD, DWORD, DWORD, FLOAT, FLOAT, int, LPGLYPHMETRICSFLOAT);
typedef BOOL (WINAPI * wglUseFontOutlinesW) (HDC, DWORD, DWORD, DWORD, FLOAT, FLOAT, int, LPGLYPHMETRICSFLOAT);

GLCC_PROC(PFNWGLCOPYCONTEXTPROC, wglCopyContext)
GLCC_PROC(PFNWGLCREATECONTEXTPROC, wglCreateContext)

