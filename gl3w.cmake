##############################################################
# Copyright (c) 2010 Daniel Pfeifer                          #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

set(GL3W_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(GL3W_INCLUDE_DIR ${CMAKE_BINARY_DIR}/include/GL3)
set(GL3W_GL3_H_FILE ${GL3W_INCLUDE_DIR}/gl3.h)
set(GL3W_GL3_H_URL http://www.opengl.org/registry/api/gl3.h)
set(GL3W_GL3W_H_FILE ${GL3W_INCLUDE_DIR}/gl3w.h)
set(GL3W_GL3W_C_FILE ${GL3W_SOURCE_DIR}/gl3w.c)

# Create directories
if(NOT EXISTS ${GL3W_SOURCE_DIR})
  file(MAKE_DIRECTORY  ${GL3W_SOURCE_DIR})
endif(NOT EXISTS ${GL3W_SOURCE_DIR})
if(NOT EXISTS ${GL3W_INCLUDE_DIR})
  file(MAKE_DIRECTORY  ${GL3W_INCLUDE_DIR})
endif(NOT EXISTS ${GL3W_INCLUDE_DIR})

# Download gl3.h
if(NOT EXISTS ${GL3W_GL3_H_FILE})
  file(DOWNLOAD ${GL3W_GL3_H_URL} ${GL3W_GL3_H_FILE})
endif(NOT EXISTS ${GL3W_GL3_H_FILE})

# Parse function names from gl3.h
set(GL3W_PROC_MATCH "^GLAPI .* APIENTRY ([^( ]+).+$")
file(STRINGS ${GL3W_GL3_H_FILE} PROC_LINES REGEX ${GL3W_PROC_MATCH})

set(PROCS)
foreach(LINE ${PROC_LINES})
  string(REGEX REPLACE ${GL3W_PROC_MATCH} "\\1" PROC ${LINE})
  list(APPEND PROCS ${PROC})
endforeach(LINE ${PROC_LINES})

macro(GL3W_PROC_T out in)
  string(TOUPPER ${in} UPPER)
  set(${out} PFN${UPPER}PROC)
endmacro(GL3W_PROC_T out in)

# Generate gl3w.h
set(GL3W_GL3W_H_FILE ${GL3W_INCLUDE_DIR}/gl3w.h)
file(WRITE ${GL3W_GL3W_H_FILE} "
#ifndef __gl3w_h_
#define __gl3w_h_

#include <GL3/gl3.h>

#ifndef __gl_h_
#define __gl_h_
#endif

#ifdef __cplusplus
extern \"C\" {
#endif

/* gl3w api */
int gl3wInit(void);
int gl3wIsSupported(int major, int minor);
void *gl3wGetProcAddress(const char *proc);

/* OpenGL functions */
")

foreach(PROC ${PROCS})
  GL3W_PROC_T(UPROC ${PROC})
  file(APPEND ${GL3W_GL3W_H_FILE}
    "extern ${UPROC} ${PROC};\n")
endforeach(PROC ${PROCS})

file(APPEND ${GL3W_GL3W_H_FILE} "
#ifdef __cplusplus
}
#endif

#endif
")

# Generate gl3w.c
file(WRITE ${GL3W_GL3W_C_FILE} "
#include <GL3/gl3w.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>

static HANDLE libgl;

static void open_libgl(void)
{
	libgl = LoadLibraryA(\"opengl32.dll\");
}

static void close_libgl(void)
{
	FreeLibrary(libgl);
}

static void *get_proc(const char *proc)
{
	void *res;

	if (!(res = wglGetProcAddress(proc)))
		res = GetProcAddress(libgl, proc);
	return res;
}

#else

#include <dlfcn.h>
#include <GL/glx.h>

static void *libgl;

static void open_libgl(void)
{
	libgl = dlopen(\"libGL.so.1\", RTLD_LAZY | RTLD_GLOBAL);
}

static void close_libgl(void)
{
	dlclose(libgl);
}

static void *get_proc(const char *proc)
{
	void *res;

	if (!(res = glXGetProcAddress((const GLubyte *) proc)))
		res = dlsym(libgl, proc);
	return res;
}

#endif

static struct {
	int major, minor;
} version;

static int parse_version(void)
{
	const char *p;
	int major, minor;

	if (!glGetString || !(p = glGetString(GL_VERSION)))
		return -1;
	for (major = 0; *p >= '0' && *p <= '9'; p++)
		major = 10 * major + *p - '0';
	for (minor = 0, p++; *p >= '0' && *p <= '9'; p++)
		minor = 10 * minor + *p - '0';
	if (major < 3)
		return -1;
	version.major = major;
	version.minor = minor;
	return 0;
}

static void load_procs(void);

int gl3wInit(void)
{
	open_libgl();
	load_procs();
	close_libgl();
	return parse_version();
}

int gl3wIsSupported(int major, int minor)
{
	if (major < 3)
		return 0;
	if (version.major == major)
		return version.minor >= minor;
	return version.major >= major;
}

void *gl3wGetProcAddress(const char *proc)
{
	return get_proc(proc);
}

")

foreach(PROC ${PROCS})
  GL3W_PROC_T(UPROC ${PROC})
  file(APPEND ${GL3W_GL3W_C_FILE} "${UPROC} ${PROC} = NULL;\n")
endforeach(PROC ${PROCS})

file(APPEND ${GL3W_GL3W_C_FILE} "\nstatic void load_procs(void)\n{\n")

foreach(PROC ${PROCS})
  GL3W_PROC_T(UPROC ${PROC})
  file(APPEND ${GL3W_GL3W_C_FILE}
    "\t${PROC} = (${UPROC}) get_proc(\"${PROC}\");\n")
endforeach(PROC ${PROCS})

file(APPEND ${GL3W_GL3W_C_FILE} "}\n")

