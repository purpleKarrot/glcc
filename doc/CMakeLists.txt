##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

boost_add_documentation(glcc.qbk
  HEADERS
    gl_autodoc.xml

    glcc.hpp
    glcc/blend.hpp
    glcc/buffer.hpp
    glcc/depth.hpp
    glcc/draw.hpp
    glcc/error.hpp
    glcc/framebuffer.hpp
    glcc/hint.hpp
    glcc/info.hpp
    glcc/logic.hpp
    glcc/matrix.hpp
    glcc/miscellaneous.hpp
    glcc/pixel.hpp
    glcc/program.hpp
    glcc/query.hpp
    glcc/renderbuffer.hpp
    glcc/set.hpp
    glcc/shader.hpp
    glcc/stencil.hpp
    glcc/texture.hpp
    glcc/uniform.hpp
    glcc/vector.hpp
    glcc/vertex_array.hpp
    glcc/vertex_attrib.hpp

  DOXYGEN_PARAMETERS
    PREDEFINED=GENERATING_DOCUMENTATION
    MACRO_EXPANSION=YES
    STRIP_FROM_PATH=${CMAKE_SOURCE_DIR}/include
    INCLUDE_PATH=${CMAKE_SOURCE_DIR}/include
  )
