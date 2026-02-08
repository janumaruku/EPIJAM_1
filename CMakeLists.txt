cmake_minimum_required(VERSION 3.28)
project(epijam_1 VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/server/Core
        src/server/GamePlay
        src/server/Map
        src/server/Network
        src/server/Physics
        src/server/Player
        src/server/PlayerEvent
        src/server/Serializer
        #[[src/client/include]])

add_subdirectory(src)