add_library(serializer OBJECT
        ../Serializer/utils.hpp
        ../Serializer/Serializer.cpp
        ../Serializer/Serializer.hpp
        Packet.cpp
        Packet.hpp)

include_directories(. ../Map)

target_compile_options(network PUBLIC -Wall -Wextra -Werror)
