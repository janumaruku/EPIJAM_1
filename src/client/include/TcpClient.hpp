/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpClient
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include <asio.hpp>
#include <iostream>
#include <memory>

#include "Packet.hpp"

using asio::ip::tcp;

class TcpClient {
public:
    TcpClient(asio::io_context& io, const std::string& host, short port);

    void send_message(const std::string& msg);

private:
    void start_read();
    void handle_read(std::shared_ptr<std::array<char, 1024>> buffer,
        const asio::error_code& error, std::size_t bytes);
    void processPackets();
    void handlePacket(Packet& pkt);

    tcp::socket socket;
    std::vector<uint8_t> _recvBuffer;
};

#endif
