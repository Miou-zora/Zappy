cmake_minimum_required(VERSION 3.9)
project(zappy_gui)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized -lglut -lGLU -lGL -lGLEW -lglfw")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC
${PROJECT_SOURCE_DIR}/src/network/socket/
${PROJECT_SOURCE_DIR}/src/network/socket/IOPooledSocket/
${PROJECT_SOURCE_DIR}/src/network/sockaddrIn/
${PROJECT_SOURCE_DIR}/src/network/client/
${PROJECT_SOURCE_DIR}/src/network/client/client/
${PROJECT_SOURCE_DIR}/src/network/client/IOPooledClient/
${PROJECT_SOURCE_DIR}/src/network/IOPool/
${PROJECT_SOURCE_DIR}/src/network/IOPool/response/
${PROJECT_SOURCE_DIR}/src/network/IOPool/request/
${PROJECT_SOURCE_DIR}/src/network/IOPool/request/request/
${PROJECT_SOURCE_DIR}/src/errorManagement/
${PROJECT_SOURCE_DIR}/src/utils/
${PROJECT_SOURCE_DIR}/src/core/
${PROJECT_SOURCE_DIR}/src/graphic/
${PROJECT_SOURCE_DIR}/src/graphic/management/
${PROJECT_SOURCE_DIR}/src/graphic/program/
${PROJECT_SOURCE_DIR}/src/graphic/object/
${PROJECT_SOURCE_DIR}/src/graphic/object/camera/
${PROJECT_SOURCE_DIR}/src/graphic/object/model/
${PROJECT_SOURCE_DIR}/src/graphic/object/model/mesh/
${PROJECT_SOURCE_DIR}/src/graphic/window/
${PROJECT_SOURCE_DIR}/src/graphic/object/cube/
${PROJECT_SOURCE_DIR}/src/graphic/scene/
${PROJECT_SOURCE_DIR}/src/game/gameCore/
${PROJECT_SOURCE_DIR}/src/game/gameState/
${PROJECT_SOURCE_DIR}/src/game/IUpdate/
${PROJECT_SOURCE_DIR}/src/game/map/
${PROJECT_SOURCE_DIR}/src/game/map/tile/
${PROJECT_SOURCE_DIR}/src/game/player/
${PROJECT_SOURCE_DIR}/src/game/container/
${PROJECT_SOURCE_DIR}/src/game/container/thystameContainer/
${PROJECT_SOURCE_DIR}/src/game/container/foodContainer/
${PROJECT_SOURCE_DIR}/src/game/container/linemateContainer/
${PROJECT_SOURCE_DIR}/src/game/container/mendianeContainer/
)

include_directories(${INCLUDE_SRC})

project(zappy_gui)

set(SRC
${PROJECT_SOURCE_DIR}/src/network/socket/Socket.cpp
${PROJECT_SOURCE_DIR}/src/network/socket/IOPooledSocket/IOPooledSocket.cpp
${PROJECT_SOURCE_DIR}/src/network/sockaddrIn/SockaddrIn.cpp
${PROJECT_SOURCE_DIR}/src/network/client/client/Client.cpp
${PROJECT_SOURCE_DIR}/src/network/client/IOPooledClient/IOPooledClient.cpp
${PROJECT_SOURCE_DIR}/src/network/IOPool/IOPool.cpp
${PROJECT_SOURCE_DIR}/src/network/IOPool/response/Response.cpp
${PROJECT_SOURCE_DIR}/src/core/Core.cpp
${PROJECT_SOURCE_DIR}/src/graphic/program/Program.cpp
${PROJECT_SOURCE_DIR}/src/graphic/object/Object.cpp
${PROJECT_SOURCE_DIR}/src/graphic/object/camera/Camera.cpp
${PROJECT_SOURCE_DIR}/src/graphic/object/model/Model.cpp
${PROJECT_SOURCE_DIR}/src/graphic/object/model/mesh/Mesh.cpp
${PROJECT_SOURCE_DIR}/src/graphic/window/Window.cpp
${PROJECT_SOURCE_DIR}/src/graphic/management/Management.cpp
${PROJECT_SOURCE_DIR}/src/graphic/object/cube/Cube.cpp
${PROJECT_SOURCE_DIR}/src/graphic/scene/Scene.cpp
${PROJECT_SOURCE_DIR}/src/game/gameCore/GameCore.cpp
${PROJECT_SOURCE_DIR}/src/game/map/Map.cpp
${PROJECT_SOURCE_DIR}/src/game/map/tile/Tile.cpp
${PROJECT_SOURCE_DIR}/src/game/gameState/GameState.cpp
${PROJECT_SOURCE_DIR}/src/game/player/Player.cpp
${PROJECT_SOURCE_DIR}/src/game/container/Container.cpp
${PROJECT_SOURCE_DIR}/src/game/container/thystameContainer/ThystameContainer.cpp
${PROJECT_SOURCE_DIR}/src/game/container/foodContainer/FoodContainer.cpp
${PROJECT_SOURCE_DIR}/src/game/container/linemateContainer/LinemateContainer.cpp
${PROJECT_SOURCE_DIR}/src/game/container/mendianeContainer/MendianeContainer.cpp
)

set(MAIN "main.cpp")

add_executable(zappy_gui ${MAIN} ${SRC})

add_subdirectory(tests)
add_subdirectory(tests/ftCube)
add_subdirectory(tests/ftObjLoader)
add_subdirectory(tests/ftScene)
