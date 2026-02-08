add_library(map OBJECT
        ../Map/types.hpp
        ../Map/Map.cpp
        ../Map/Map.hpp
        ../Map/MapLoader.cpp
        ../Map/MapLoader.hpp)

target_include_directories(map PUBLIC . ../Map)

target_compile_options(map PUBLIC -Wall -Wextra -Werror)
