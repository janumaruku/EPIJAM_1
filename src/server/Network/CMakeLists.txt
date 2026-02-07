add_library(tcp_server OBJECT TcpServer.cpp
        TcpServer.hpp
        ClientSession.cpp
        ClientSession.hpp)

target_include_directories(tcp_server PUBLIC .)

target_compile_options(tcp_server PUBLIC -Wall -Wextra -Werror)
