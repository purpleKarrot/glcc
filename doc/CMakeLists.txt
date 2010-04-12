##############################################################
# Copyright (c) 2008-2010 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

add_reference(glcc-ref.xml
  ../include/glcc.hpp
  ../include/glcc/blend.hpp
  ../include/glcc/buffer.hpp
  ../include/glcc/depth.hpp
  ../include/glcc/draw.hpp
  ../include/glcc/error.hpp
  ../include/glcc/extension.hpp
  ../include/glcc/framebuffer.hpp
  ../include/glcc/hint.hpp
  ../include/glcc/info.hpp
  ../include/glcc/logic.hpp
  ../include/glcc/miscellaneous.hpp
  ../include/glcc/pixel.hpp
  ../include/glcc/program.hpp
  ../include/glcc/query.hpp
  ../include/glcc/renderbuffer.hpp
  ../include/glcc/set.hpp
  ../include/glcc/shader.hpp
  ../include/glcc/stencil.hpp
  ../include/glcc/texture.hpp
  ../include/glcc/uniform.hpp
  ../include/glcc/vertex_array.hpp
  ../include/glcc/vertex_attrib_pointer.hpp
  HEADER_PREFIX glcc
  )

add_documentation(
  glcc.qbk
  glcc-ref.xml
  )
