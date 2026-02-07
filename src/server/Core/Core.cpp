/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

#include "MapLoader.hpp"

Core::Core(short port)
{
    _map = MapLoader::loadFromFile("maps/map.txt", 32.0f);
    _server = std::make_unique<TcpServer>(_io, port);
}

void Core::run()
{
    std::cout << "[CORE] Starting server loop\n";
    _io.run();
    std::cout << "[CORE] Server stopped\n";
}
