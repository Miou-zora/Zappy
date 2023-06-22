cmake_minimum_required(VERSION 3.11)
project(zappy_gui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(MAIN "main.cpp")

add_subdirectory(src)
add_executable(${PROJECT_NAME} ${MAIN})

target_link_libraries(${PROJECT_NAME} PRIVATE src_lib)

add_subdirectory(tests)
