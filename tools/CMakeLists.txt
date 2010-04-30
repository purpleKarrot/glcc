
find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

find_package(PNG REQUIRED)

add_executable(texture texture.cpp)

target_link_libraries(texture
  glcc
  GLEW
  ${SDL_LIBRARY}
  ${PNG_LIBRARIES}
  ${Boost_LIBRARIES}
  ${OPENGL_LIBRARIES}
  )
