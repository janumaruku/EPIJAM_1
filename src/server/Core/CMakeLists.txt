add_executable(server main.cpp
        Core.cpp
        Core.hpp
        ../Map/types.hpp
        ../Map/Map.cpp
        ../Map/Map.hpp
        ../Map/MapLoader.cpp
        ../Map/MapLoader.hpp)

target_include_directories(server PUBLIC . ../Map)

set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(server tcp_server)
