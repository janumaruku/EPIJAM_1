/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpServer
*/

#ifndef TCPSERVER_HPP_
#define TCPSERVER_HPP_

#include <asio.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "ClientSession.hpp"

using asio::ip::tcp;

#include <asio.hpp>
#include <vector>
#include <memory>
#include "ClientSession.hpp"

using asio::ip::tcp;

class TcpServer {
public:
    TcpServer(asio::io_context& io, short port);

private:
    void accept();

    tcp::acceptor _acceptor;
    std::vector<std::shared_ptr<ClientSession>> _clients;
};

#endif
