/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** Core
*/

#ifndef EPIJAM_1_CORE_HPP
#define EPIJAM_1_CORE_HPP

#include "GameEngine.hpp"
#include "TcpClient.hpp"

class ClientApp {
public:
    explicit ClientApp(int port);
    void run();

private:
    asio::io_context io;
    TcpClient network;

    GameEngine engine;
};

#endif //EPIJAM_1_CORE_HPP