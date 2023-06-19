cmake_minimum_required(VERSION 3.9)

set(FTOBJLOADER_BINARY ftObjLoader)

set(FTOBJLOADER_SRC
	ftObjLoader.cpp
)

add_executable(${FTOBJLOADER_BINARY} ${FTOBJLOADER_SRC})
target_link_libraries(${FTOBJLOADER_BINARY} src_lib)
