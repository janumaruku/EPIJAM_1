//
// Created by kotti on 08/02/2026.
//

#include "Core.hpp"

ClientApp::ClientApp(int port)
    : network(io, "127.0.0.1", port)
{
}

void ClientApp::run()
{
    std::thread networkThread([this]() { io.run(); });

    engine.run(); 
    network.stop();       
    io.stop();           
    networkThread.join(); 
    
}
