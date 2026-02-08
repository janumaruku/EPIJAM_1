/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Core
*/

#ifndef BISTROMATIC_CORE_HPP
#define BISTROMATIC_CORE_HPP

#include <asio.hpp>
#include <memory>

#include "../Map/Map.hpp"
#include "../Network/TcpServer.hpp"

class Core {
public:
    explicit Core(short port);
    void run();

    void onClientConnected(const std::shared_ptr<ClientSession>& client);

    Map getMap() const noexcept;

private:
    asio::io_context _io;
    std::unique_ptr<TcpServer> _server;
    Map _map;
};

#endif //BISTROMATIC_CORE_HPP
