//
// Created by kotti on 07/02/2026.
//

#include "ClientSession.hpp"
#include <iostream>
#include <asio/write.hpp>

ClientSession::ClientSession(asio::ip::tcp::socket socket)
    : _socket(std::move(socket))
{
    _readBuffer.resize(1024);
}

void ClientSession::start()
{
    do_read();
}

void ClientSession::send(const Packet& pkt)
{
    std::vector<uint8_t> framed;

    const uint16_t size = static_cast<uint16_t>(pkt.getBuffer().size());
    framed.resize(sizeof(size) + size);

    std::memcpy(framed.data(), &size, sizeof(size));
    std::memcpy(framed.data() + sizeof(size),
                pkt.getBuffer().data(),
                size);

    asio::async_write(_socket, asio::buffer(framed),
        [](auto, auto) {});
}

void ClientSession::do_read()
{
    // auto self = shared_from_this();

    _socket.async_read_some(
        asio::buffer(_readBuffer),
        [this](const asio::error_code& ec, const std::size_t bytes) {
            if (!ec) {
                std::cout << "Received " << bytes << " bytes\n";

                _writeBuffer.assign(_readBuffer.begin(),
                    _readBuffer.begin() + bytes);

                do_write();
            } else {
                std::cerr << "Read error: " << ec.message() << std::endl;
            }
        }
    );
}

void ClientSession::do_write()
{
    // auto self = shared_from_this();

    asio::async_write(
        _socket,
        asio::buffer(_writeBuffer),
        [this](const asio::error_code& ec, std::size_t) {
            if (!ec) {
                do_read();
            } else {
                std::cerr << "Write error: " << ec.message() << std::endl;
            }
        }
    );
}
