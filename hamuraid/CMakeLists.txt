cmake_minimum_required(VERSION 2.8)
project(HAMURAID)

include_directories(${LIBHAMURAI_SOURCE_DIR}/include)

# Add lib
LINK_DIRECTORIES(${LIBHAMURAI_BINARY_DIR})
set( DEPS "${DEPS};hamurai" )

# Global shit
file (GLOB_RECURSE HAMURAID_SRC ./src/*.cc)
add_executable(hamuraid ${HAMURAID_SRC})

target_link_libraries (hamuraid ${DEPS} )
