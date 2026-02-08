/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

// int main()
// {
//     try {
//         Core core(8080);
//         core.run();
//     } catch (const std::exception& e) {
//         std::cerr << "[FATAL] " << e.what() << std::endl;
//     }
//     return 0;
// }

int main(int, char** av)
{
    try {
        int port = atoi(av[1]);
        Core core(port);
        core.run();
    } catch (const std::exception& e) {
        std::cerr << "[FATAL] " << e.what() << std::endl;
    }
    return 0;
}