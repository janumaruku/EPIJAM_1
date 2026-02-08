/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** Packet
*/

#include "Packet.hpp"

Packet::Packet(const std::vector<std::uint8_t>& buffer) : _buffer{buffer}
{
}

std::vector<std::uint8_t> Packet::getBuffer() const noexcept
{
    return _buffer;
}
