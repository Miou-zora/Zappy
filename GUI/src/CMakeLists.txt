cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra -Wshadow -Wuninitialized -lglut -lGLU -lGL -lGLEW -lglfw")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(INCLUDE_SRC
${CMAKE_CURRENT_SOURCE_DIR}/network/socket/
${CMAKE_CURRENT_SOURCE_DIR}/network/socket/IOPooledSocket/
${CMAKE_CURRENT_SOURCE_DIR}/network/sockaddrIn/
${CMAKE_CURRENT_SOURCE_DIR}/network/client/
${CMAKE_CURRENT_SOURCE_DIR}/network/client/client/
${CMAKE_CURRENT_SOURCE_DIR}/network/client/IOPooledClient/
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/response/
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/request/
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/request/request/
${CMAKE_CURRENT_SOURCE_DIR}/errorManagement/
${CMAKE_CURRENT_SOURCE_DIR}/utils/
${CMAKE_CURRENT_SOURCE_DIR}/core/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/management/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/camera/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/model/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/window/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/scene/
${CMAKE_CURRENT_SOURCE_DIR}/graphic/button/
${CMAKE_CURRENT_SOURCE_DIR}/game/gameCore/
${CMAKE_CURRENT_SOURCE_DIR}/game/gameState/
${CMAKE_CURRENT_SOURCE_DIR}/game/IUpdate/
${CMAKE_CURRENT_SOURCE_DIR}/game/map/
${CMAKE_CURRENT_SOURCE_DIR}/game/map/tile/
${CMAKE_CURRENT_SOURCE_DIR}/game/player/
${CMAKE_CURRENT_SOURCE_DIR}/game/incantation/
${CMAKE_CURRENT_SOURCE_DIR}/game/incantation/incantationEvent/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/thystameContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/foodContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/linemateContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/mendianeContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/deraumereContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/phirasContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/container/siburContainer/
${CMAKE_CURRENT_SOURCE_DIR}/game/event/
${CMAKE_CURRENT_SOURCE_DIR}/game/event/broadcastEvent/
${CMAKE_CURRENT_SOURCE_DIR}/game/event/eventPool/
${CMAKE_CURRENT_SOURCE_DIR}/game/catchable/
${CMAKE_CURRENT_SOURCE_DIR}/game/team/
${CMAKE_CURRENT_SOURCE_DIR}/game/button/quitButton/
${CMAKE_CURRENT_SOURCE_DIR}/game/button/switchTimeunitButton/
${CMAKE_CURRENT_SOURCE_DIR}/game/egg/
${CMAKE_CURRENT_SOURCE_DIR}/game/button/killButton/
)

include_directories(${INCLUDE_SRC})

set(SRC
${CMAKE_CURRENT_SOURCE_DIR}/network/socket/Socket.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/socket/IOPooledSocket/IOPooledSocket.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/sockaddrIn/SockaddrIn.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/client/client/Client.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/client/IOPooledClient/IOPooledClient.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/IOPool.cpp
${CMAKE_CURRENT_SOURCE_DIR}/network/IOPool/response/Response.cpp
${CMAKE_CURRENT_SOURCE_DIR}/core/Core.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/Object.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/camera/Camera.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/object/model/Model.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/window/Window.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/management/Management.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/scene/Scene.cpp
${CMAKE_CURRENT_SOURCE_DIR}/graphic/button/AButton.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameCore/GameCore.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/map/Map.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/map/tile/Tile.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameState/GameState.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/player/Player.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/incantation/Incantation.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/incantation/incantationEvent/IncantationEvent.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/container/Container.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/event/eventPool/EventPool.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/event/broadcastEvent/BroadcastEvent.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/button/quitButton/QuitButton.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/button/switchTimeunitButton/SwitchTimeunitButton.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/egg/Egg.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/button/killButton/KillButton.cpp
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} REQUIRED)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

set(LIBRARY_NAME "src_lib")

add_library(${LIBRARY_NAME} STATIC)

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_SRC})
target_sources(${LIBRARY_NAME} PRIVATE ${SRC})
target_link_libraries(${LIBRARY_NAME} PRIVATE raylib)

