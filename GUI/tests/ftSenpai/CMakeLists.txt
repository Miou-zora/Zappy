cmake_minimum_required(VERSION 3.9)

set(FTSENPAI_BINARY ftSenpai)

set(FTSENPAI_SRC
	ftSenpai.cpp
)

add_executable(${FTSENPAI_BINARY} ${FTSENPAI_SRC})
target_link_libraries(${FTSENPAI_BINARY} src_lib)
