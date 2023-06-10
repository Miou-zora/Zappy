cmake_minimum_required(VERSION 3.9)
project(zappy_gui)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC ${PROJECT_SOURCE_DIR}/src/network/socket/
${PROJECT_SOURCE_DIR}/src/network/sockaddrIn/
${PROJECT_SOURCE_DIR}/src/network/client/
${PROJECT_SOURCE_DIR}/src/errorManagement/
${PROJECT_SOURCE_DIR}/src/core/
${PROJECT_SOURCE_DIR}/src/utils/
)

include_directories(${INCLUDE_SRC})

project(zappy_gui)

set(SRC ${PROJECT_SOURCE_DIR}/src/network/socket/Socket.cpp
${PROJECT_SOURCE_DIR}/src/network/sockaddrIn/SockaddrIn.cpp
${PROJECT_SOURCE_DIR}/src/network/client/Client.cpp
${PROJECT_SOURCE_DIR}/src/core/Core.cpp
${PROJECT_SOURCE_DIR}/src/utils/ObjLoader.cpp
)

set(MAIN "main.cpp")

add_executable(zappy_gui ${MAIN} ${SRC})

add_subdirectory(tests)
