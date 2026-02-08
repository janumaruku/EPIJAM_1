/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

#include "MapLoader.hpp"
#include "../PlayerEvent/PlayerEventFactory.hpp"

Core::Core(short port)
{
    _map    = MapLoader::loadFromFile("maps/map.txt", 32.0f);
    _server = std::make_unique<TcpServer>(_io, port, *this);
}

void Core::run()
{
    std::cout << "[CORE] Starting server loop\n";
    _io.run();
    std::cout << "[CORE] Server stopped\n";
}

void Core::onClientConnected(const std::shared_ptr<ClientSession>& client)
{
    try {
        const auto event =
            PlayerEventFactory::create(EventType::CONNECTION_REQUEST);
        (*event)(*this, client);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

Map Core::getMap() const noexcept
{
    return _map;
}
