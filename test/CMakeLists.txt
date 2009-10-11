##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

find_package(GLUT REQUIRED)

set(LIBRARIES glcc
# ${Boost_SYSTEM_LIBRARY}
  ${OPENGL_LIBRARIES}
# ${GLUT_glut_LIBRARY}
  )

add_executable(vector vector.cpp)
add_executable(matrix matrix.cpp)
add_executable(shader shader.cpp)
add_library(cl cl.cpp)

target_link_libraries(vector ${LIBRARIES})
target_link_libraries(matrix ${LIBRARIES})
target_link_libraries(shader ${LIBRARIES})

if(CMAKE_HOST_WIN32)
  add_executable(wgl wgl)
  target_link_libraries(wgl ${LIBRARIES})
endif(CMAKE_HOST_WIN32)
