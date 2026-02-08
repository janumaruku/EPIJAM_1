/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Serializer
*/


#include "Serializer.hpp"

#include "utils.hpp"

// std::vector<uint8_t> Serializer::serializeMap(const Map& map)
// {
//     std::vector<uint8_t> buffer;
//
//     write<uint8_t>(buffer, static_cast<uint8_t>(PacketType::MapInit));
//
//     const auto& entities = map.getEntities();
//     const std::uint16_t count = static_cast<std::uint16_t>(entities.size());
//     write<std::uint16_t>(buffer, count);
//
//     for (const auto& [type, x, y] : entities) {
//         write<uint8_t>(buffer, static_cast<uint8_t>(type));
//         write<float>(buffer, x);
//         write<float>(buffer, y);
//     }
//
//     return buffer;
// }
//
// std::vector<uint8_t> Serializer::framePacket(const std::vector<uint8_t>& payload)
// {
//     std::vector<uint8_t> packet;
//
//     const std::uint16_t size = static_cast<std::uint16_t>(payload.size());
//     write<std::uint16_t>(packet, size);
//
//     packet.insert(packet.end(), payload.begin(), payload.end());
//     return packet;
// }
