cmake_minimum_required(VERSION 3.9)
project(zappy_gui)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wshadow -Wuninitialized")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC
)

include_directories(${INCLUDE_SRC})

project(zappy_gui)

set(SRC
)

set(MAIN "main.cpp")

add_executable(zappy_gui ${MAIN} ${SRC})

