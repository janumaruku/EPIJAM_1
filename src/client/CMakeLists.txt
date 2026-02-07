
include_directories(include)

add_executable(ray_client 
    src/main.cpp 
    src/animated_sprite.cpp
    src/Parallax_Manager.cpp
    )

set_target_properties(ray_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_link_libraries(ray_client raylib GL m pthread dl rt X11)

