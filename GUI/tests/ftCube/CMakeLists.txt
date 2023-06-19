cmake_minimum_required(VERSION 3.9)

set(FTCUBE_BINARY ftCube)

set(FTCUBE_SRC
	ftCube.cpp
)

add_executable(${FTCUBE_BINARY} ${FTCUBE_SRC})
target_link_libraries(${FTCUBE_BINARY} src_lib)
