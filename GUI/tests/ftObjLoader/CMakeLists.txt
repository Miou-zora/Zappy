cmake_minimum_required(VERSION 3.9)

set(FTOBJLOADER_BINARY ftObjLoader)

set(FTOBJLOADER_SRC
	ftObjLoader.cpp
)

add_executable(${FTOBJLOADER_BINARY} ${SRC} ${INCLUDE_SRC} ${FTOBJLOADER_SRC})
