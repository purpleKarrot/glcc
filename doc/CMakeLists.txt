##############################################################
# Copyright (c) 2008-2010 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

add_reference(glcc-ref.xml
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
  )

add_documentation(
  glcc.qbk
  glcc-ref.xml
  )
