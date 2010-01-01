# Copyright (c) 2009 Daniel Pfeifer

function(ADD_TEST_MODULE name)

  set(MAIN_CPP  ${CMAKE_CURRENT_BINARY_DIR}/${name}.cpp)
  file(WRITE ${MAIN_CPP}
    "#define BOOST_TEST_MODULE ${name}\n"
    "#include <boost/test/unit_test.hpp>\n")

  add_executable(${name} ${MAIN_CPP} ${ARGN})

  get_target_property(TEST_EXE ${name} LOCATION)

  add_custom_target(${name}_run
#   ${TEST_EXE} -log_level=all > ${CMAKE_SOURCE_DIR}/${name}.txt 2>&1
    ${TEST_EXE} --log_level=message
    DEPENDS ${name})

endfunction(ADD_TEST_MODULE name)
