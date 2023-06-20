cmake_minimum_required(VERSION 3.9)
project(zappy_gui)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized -lglut -lGLU -lGL -lGLEW -lglfw")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(MAIN "main.cpp")

# create zappy_gui project that is linked to the library src_lib and the main file

# add the library src_lib
add_subdirectory(src)
add_executable(zappy_gui ${MAIN})
target_link_libraries(zappy_gui PRIVATE src_lib)

add_subdirectory(tests)
add_subdirectory(tests/ftCube)
add_subdirectory(tests/ftObjLoader)
add_subdirectory(tests/ftScene)
add_subdirectory(tests/ftSenpai)

