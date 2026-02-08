/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpServer
*/

#include "TcpServer.hpp"
#include <iostream>

#include "Core.hpp"

TcpServer::TcpServer(asio::io_context& io, const short port, Core& core)
    : _acceptor(io, tcp::endpoint(tcp::v4(), port)), _core{core}
{
    std::cout << "[SERVER] Listening on port " << port << std::endl;
    accept();
}

void TcpServer::accept()
{
    _acceptor.async_accept(
        [this](const asio::error_code& ec, tcp::socket socket) {
            if (!ec) {
                const auto endpoint = socket.remote_endpoint();

                std::cout << "[SERVER] New client connected from "
                          << endpoint.address().to_string()
                          << ":" << endpoint.port()
                          << std::endl;

                const auto client = std::make_shared<ClientSession>(std::move(socket));
                _clients.push_back(client);
                _core.onClientConnected(client);
                client->start();
            } else {
                std::cerr << "[SERVER] Accept error: "
                          << ec.message() << std::endl;
            }

            accept();
        }
    );
}
