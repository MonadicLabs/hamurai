project( HAMURAI_TEST )

INCLUDE_DIRECTORIES( ${HAMURAI_TEST_SOURCE_DIR}/Catch/single_include/ )

add_executable( hamurai_test main.cc )
