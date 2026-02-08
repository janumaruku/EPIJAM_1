add_executable(server main.cpp
        Core.cpp
        Core.hpp)

target_include_directories(server PUBLIC . ../Map ../Network)

set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(server network player_event map serializer)
