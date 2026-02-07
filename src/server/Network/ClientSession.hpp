/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** ClientSession
*/

#ifndef BISTROMATIC_CLIENTSESSION_HPP
#define BISTROMATIC_CLIENTSESSION_HPP
#include <memory>
#include <vector>
#include <asio/ip/tcp.hpp>

class ClientSession : public std::enable_shared_from_this<ClientSession> {
public:
    explicit ClientSession(asio::ip::tcp::socket socket);

    void start();
    void send(const std::vector<uint8_t>& data);

private:
    void do_read();
    void do_write();

    asio::ip::tcp::socket _socket;
    std::vector<uint8_t> _readBuffer;
    std::vector<uint8_t> _writeBuffer;
};

#endif //BISTROMATIC_CLIENTSESSION_HPP