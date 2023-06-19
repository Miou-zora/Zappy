cmake_minimum_required(VERSION 3.9)

set(FTSCENE_BINARY ftScene)

set(FTSCENE_SRC
	ftScene.cpp
)

add_executable(${FTSCENE_BINARY} ${FTSCENE_SRC})
target_link_libraries(${FTSCENE_BINARY} src_lib)
