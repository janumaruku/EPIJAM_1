/*
** EPITECH PROJECT, 2026
** EPIJAM_1
** File description:
** TcpServer
*/

#include "TcpServer.hpp"

void TcpServer::accept_connexion()
{
    auto socket = std::make_shared<asio::ip::tcp::socket>(io_const);
    accept.async_accept(*socket, [this, socket](const asio::error_code &error)
                        {
        if (!error) {
            std::cout<< "handle new connexion\n";
            read_connexion(socket);
        } else {
            std::cerr <<"Error in new connection acceptation: " << error.message() << std::endl;
        }
        accept_connexion(); });
}

void TcpServer::read_connexion(std::shared_ptr<tcp::socket> sock)
{
    auto buffer = std::make_shared<std::array<char, 1024>>();

    sock->async_read_some(asio::buffer(*buffer),
                          [this, sock, buffer](const asio::error_code &error, std::size_t bytes)
                          {
                              if (!error)
                              {
                                  std::cout << "Message reçu: " << std::string(buffer->data(), bytes);
                                  write_connexion(sock, buffer, bytes);
                              }
                              else
                              {
                                  std::cerr << "Error in reading: " << error.message() << std::endl;
                              }
                          });
}

void TcpServer::write_connexion(std::shared_ptr<tcp::socket> socket,
                                std::shared_ptr<std::array<char, 1024>> buffer,
                                std::size_t bytes)
{
    auto response = std::make_shared<std::string>(
        "Message envoyer: " + std::string(buffer->data(), bytes));

    asio::async_write(*socket, asio::buffer(*response),
                      [this, socket, response](const asio::error_code &error, std::size_t)
                      {
                          if (!error)
                          {
                              read_connexion(socket);
                          }
                          else
                          {
                              std::cerr << "Erreur d'écriture: " << error.message() << std::endl;
                          }
                      });
}

int main()
{
    try
    {
        asio::io_context io_context;
        TcpServer server(io_context, 8080);
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}