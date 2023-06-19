cmake_minimum_required(VERSION 3.9)

set(BINARY unitTests)

set(TESTS_SRC
	network/tests_socket.cpp
	network/tests_client.cpp
)

add_executable(${BINARY} ${TESTS_SRC})

target_link_libraries(${BINARY} src_lib)
target_link_libraries(${BINARY}
	criterion
)
