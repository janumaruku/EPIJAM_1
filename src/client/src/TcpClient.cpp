/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpClient
*/

#include "TcpClient.hpp"

TcpClient::TcpClient(asio::io_context& io, const std::string& host, short port) :
    socket(io)
{
    tcp::resolver resolver(io);
    auto endpoints = resolver.resolve(host, std::to_string(port));

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
        { handle_read(buffer, error, bytes); });
}

void TcpClient::handle_read(std::shared_ptr<std::array<char, 1024>> buffer,
    const asio::error_code& error, std::size_t bytes)
{
    if (!error) {
        std::string msg(buffer->data(), bytes);
        std::cout << "Received: " << msg << "\n";

        start_read();
    } else {
        std::cerr << "Read error: " << error.message() << "\n";
    }
}

int main(int, char** av)
{
    try {
        int port = atoi(av[1]);
        asio::io_context io;
        TcpClient client(io, "127.0.0.1", port);

        io.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
