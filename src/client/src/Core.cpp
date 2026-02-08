/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** Core
*/

#include "ClientApp.hpp"

ClientApp::ClientApp(int port)
    : network(io, "127.0.0.1", port)
{
}

void ClientApp::run()
{
    std::thread networkThread([this]() {
        io.run();
    });

    engine.run();

    networkThread.join();
}
