/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpClient
*/

#include "../include/TcpClient.hpp"

#include "../../server/Serializer/Packet.hpp"
#include "../../server/Serializer/utils.hpp"

TcpClient::TcpClient(asio::io_context& io, const std::string& host, short port) :
    socket(io)
{
    tcp::resolver resolver(io);
    const auto endpoints = resolver.resolve(host, std::to_string(port));

    asio::async_connect(socket, endpoints,
        [this](const asio::error_code& error, const tcp::endpoint&)
        {
            if (!error) {
                std::cout << "Connected to server\n";
                start_read();
            } else {
                std::cerr << "Connection error: " << error.message() << "\n";
            }
        });
}

void TcpClient::send_message(const std::string& msg)
{
    auto data = std::make_shared<std::string>(msg);

    asio::async_write(socket, asio::buffer(*data),
        [data](const asio::error_code& error, std::size_t)
        {
            if (error)
                std::cerr << "Send error: " << error.message() << "\n";
        });
}

void TcpClient::start_read()
{
    auto buffer = std::make_shared<std::array<char, 1024>>();

    socket.async_read_some(asio::buffer(*buffer),
        [this, buffer](const asio::error_code& error, std::size_t bytes)
        {
            handle_read(buffer, error, bytes);
        });
}

void TcpClient::handle_read(std::shared_ptr<std::array<char, 1024>> buffer,
    const asio::error_code& error, std::size_t bytes)
{
    if (!error) {
        const std::string msg(buffer->data(), bytes);
        std::cout << "Received: " << msg << "\n";

        _recvBuffer.insert(
            _recvBuffer.end(),
            buffer->begin(),
            buffer->begin() + bytes
        );

        processPackets();

        start_read();
    } else {
        std::cerr << "Read error: " << error.message() << "\n";
    }
}

void TcpClient::processPackets()
{
    while (true) {
        // Need at least size header
        if (_recvBuffer.size() < sizeof(uint16_t))
            return;

        uint16_t payloadSize;
        std::memcpy(&payloadSize, _recvBuffer.data(), sizeof(uint16_t));

        const size_t fullSize = sizeof(uint16_t) + payloadSize;

        if (_recvBuffer.size() < fullSize)
            return;

        // Extract payload
        std::vector<uint8_t> payload(payloadSize);
        std::memcpy(
            payload.data(),
            _recvBuffer.data() + sizeof(uint16_t),
            payloadSize
        );

        // Remove from buffer
        _recvBuffer.erase(
            _recvBuffer.begin(),
            _recvBuffer.begin() + fullSize
        );

        Packet pkt(payload);
        handlePacket(pkt);
    }
}

void TcpClient::handlePacket(Packet& pkt)
{
    const auto type = pkt.read<PacketType>();

    if (type != PacketType::CONNECTION_REQUEST) {
        std::cerr << "Unexpected packet type\n";
        return;
    }

    const uint8_t count = pkt.read<uint8_t>();

    std::cout << "Received map with " << (int)count << " entities\n";

    for (uint8_t i = 0; i < count; ++i) {
        uint8_t entityType = pkt.read<uint8_t>();
        float x = pkt.read<float>();
        float y = pkt.read<float>();

        std::cout << "Entity "
                  << (int)entityType
                  << " at (" << x << ", " << y << ")\n";

        // Here: spawn sprite / entity in your game world
    }
}


// int main(int, char** av)
// {
//     try {
//         int port = atoi(av[1]);
//         asio::io_context io;
//         TcpClient client(io, "127.0.0.1", port);
//
//         io.run();
//     } catch (std::exception& e) {
//         std::cerr << "Exception: " << e.what() << "\n";
//     }
// }
