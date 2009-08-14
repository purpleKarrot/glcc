##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

find_package(GLUT REQUIRED)

set(LIBRARIES
  ${Boost_SYSTEM_LIBRARY}
  ${OPENGL_LIBRARIES}
  ${GLUT_glut_LIBRARY})

add_executable(vector vector.cpp)
add_executable(matrix matrix.cpp)
add_executable(shader shader.cpp)
