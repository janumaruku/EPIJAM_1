add_library(network OBJECT TcpServer.cpp
        TcpServer.hpp
        TcpServer.cpp
        ClientSession.cpp
        ClientSession.hpp)

target_include_directories(network PUBLIC . ../Core)

target_compile_options(network PUBLIC -Wall -Wextra -Werror)
