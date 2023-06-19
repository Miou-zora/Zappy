cmake_minimum_required(VERSION 3.9)
project(zappy_gui)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized -lglut -lGLU -lGL -lGLEW -lglfw")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC
${PROJECT_SOURCE_DIR}/network/socket/
${PROJECT_SOURCE_DIR}/network/socket/IOPooledSocket/
${PROJECT_SOURCE_DIR}/network/sockaddrIn/
${PROJECT_SOURCE_DIR}/network/client/
${PROJECT_SOURCE_DIR}/network/client/client/
${PROJECT_SOURCE_DIR}/network/client/IOPooledClient/
${PROJECT_SOURCE_DIR}/network/IOPool/
${PROJECT_SOURCE_DIR}/network/IOPool/response/
${PROJECT_SOURCE_DIR}/network/IOPool/request/
${PROJECT_SOURCE_DIR}/network/IOPool/request/request/
${PROJECT_SOURCE_DIR}/errorManagement/
${PROJECT_SOURCE_DIR}/utils/
${PROJECT_SOURCE_DIR}/core/
${PROJECT_SOURCE_DIR}/graphic/
${PROJECT_SOURCE_DIR}/graphic/management/
${PROJECT_SOURCE_DIR}/graphic/program/
${PROJECT_SOURCE_DIR}/graphic/object/
${PROJECT_SOURCE_DIR}/graphic/object/camera/
${PROJECT_SOURCE_DIR}/graphic/object/model/
${PROJECT_SOURCE_DIR}/graphic/object/model/mesh/
${PROJECT_SOURCE_DIR}/graphic/window/
${PROJECT_SOURCE_DIR}/graphic/object/cube/
${PROJECT_SOURCE_DIR}/graphic/scene/
${PROJECT_SOURCE_DIR}/game/gameCore/
${PROJECT_SOURCE_DIR}/game/gameState/
${PROJECT_SOURCE_DIR}/game/IUpdate/
${PROJECT_SOURCE_DIR}/game/map/
${PROJECT_SOURCE_DIR}/game/map/tile/
${PROJECT_SOURCE_DIR}/game/player/
${PROJECT_SOURCE_DIR}/game/container/
${PROJECT_SOURCE_DIR}/game/container/thystameContainer/
${PROJECT_SOURCE_DIR}/game/container/foodContainer/
${PROJECT_SOURCE_DIR}/game/container/linemateContainer/
${PROJECT_SOURCE_DIR}/game/container/mendianeContainer/
${PROJECT_SOURCE_DIR}/game/container/deraumereContainer/
${PROJECT_SOURCE_DIR}/game/container/phirasContainer/
${PROJECT_SOURCE_DIR}/game/container/siburContainer/
)

include_directories(${INCLUDE_SRC})

set(SRC
${PROJECT_SOURCE_DIR}/network/socket/Socket.cpp
${PROJECT_SOURCE_DIR}/network/socket/IOPooledSocket/IOPooledSocket.cpp
${PROJECT_SOURCE_DIR}/network/sockaddrIn/SockaddrIn.cpp
${PROJECT_SOURCE_DIR}/network/client/client/Client.cpp
${PROJECT_SOURCE_DIR}/network/client/IOPooledClient/IOPooledClient.cpp
${PROJECT_SOURCE_DIR}/network/IOPool/IOPool.cpp
${PROJECT_SOURCE_DIR}/network/IOPool/response/Response.cpp
${PROJECT_SOURCE_DIR}/core/Core.cpp
${PROJECT_SOURCE_DIR}/graphic/program/Program.cpp
${PROJECT_SOURCE_DIR}/graphic/object/Object.cpp
${PROJECT_SOURCE_DIR}/graphic/object/camera/Camera.cpp
${PROJECT_SOURCE_DIR}/graphic/object/model/Model.cpp
${PROJECT_SOURCE_DIR}/graphic/object/model/mesh/Mesh.cpp
${PROJECT_SOURCE_DIR}/graphic/window/Window.cpp
${PROJECT_SOURCE_DIR}/graphic/management/Management.cpp
${PROJECT_SOURCE_DIR}/graphic/object/cube/Cube.cpp
${PROJECT_SOURCE_DIR}/graphic/scene/Scene.cpp
${PROJECT_SOURCE_DIR}/game/gameCore/GameCore.cpp
${PROJECT_SOURCE_DIR}/game/map/Map.cpp
${PROJECT_SOURCE_DIR}/game/map/tile/Tile.cpp
${PROJECT_SOURCE_DIR}/game/gameState/GameState.cpp
${PROJECT_SOURCE_DIR}/game/player/Player.cpp
${PROJECT_SOURCE_DIR}/game/container/Container.cpp
${PROJECT_SOURCE_DIR}/game/container/thystameContainer/ThystameContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/foodContainer/FoodContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/linemateContainer/LinemateContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/mendianeContainer/MendianeContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/deraumereContainer/DeraumereContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/phirasContainer/PhirasContainer.cpp
${PROJECT_SOURCE_DIR}/game/container/siburContainer/SiburContainer.cpp
)


# generate library
add_library(src_lib STATIC)
target_include_directories(src_lib PUBLIC ${INCLUDE_SRC})
target_sources(src_lib PRIVATE ${SRC})

