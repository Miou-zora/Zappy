cmake_minimum_required(VERSION 3.9)

set(FTSCENE_BINARY ftScene)

set(FTSCENE_SRC
	ftScene.cpp
)

add_executable(${FTSCENE_BINARY} ${SRC} ${INCLUDE_SRC} ${FTSCENE_SRC})
