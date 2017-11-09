project (LIBHAMURAI)

set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")

include_directories(${LIBHAMURAI_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${LIBHAMURAI_SOURCE_DIR}/extdeps/concurrentqueue)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread" )

file (GLOB_RECURSE HAMURAI_SRC ${LIBHAMURAI_SOURCE_DIR}/src/*.c*)
file (GLOB_RECURSE HAMURAI_HEADERS ${LIBHAMURAI_SOURCE_DIR}/include/*.h)

add_library(hamurai SHARED ${HAMURAI_SRC} ${HAMURAI_HEADERS} )

target_link_libraries( hamurai ${DEPS} )
