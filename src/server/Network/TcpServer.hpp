/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpServer
*/

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include <iostream>
#include <asio.hpp>
#include <memory>
#include <vector>

using asio::ip::tcp;

class TcpServer {
public:
    TcpServer(asio::io_context& io, const short port) : io_const(io),
        accept(io, tcp::endpoint(
            tcp::v4(),
            port))
    {
        accept_connexion();
    }

private:
    asio::io_context& io_const;
    tcp::acceptor accept;

    void accept_connexion();

    void read_connexion(const std::shared_ptr<tcp::socket>& sock);

    void write_connexion(const std::shared_ptr<tcp::socket>& socket,
        const std::shared_ptr<std::array<char, 1024>>& buffer,
        std::size_t bytes);
};

#endif
