/*
** EPITECH PROJECT, 2026
** bistroMatic
** File description:
** Serializer
*/

#ifndef BISTROMATIC_SERIALIZER_HPP
#define BISTROMATIC_SERIALIZER_HPP

#include <cstdint>
#include <vector>

#include "../Map/Map.hpp"

class Serializer {
public:
    template <typename T>
    static void write(std::vector<std::uint8_t>& buffer, const T& value)
    {
        static_assert(std::is_trivially_copyable_v<T>);
        const auto ptr = reinterpret_cast<const std::uint8_t*>(&value);
        buffer.insert(buffer.end(), ptr, ptr + sizeof(T));
    }

    // static std::vector<std::uint8_t> serializeMap(const Map& map);
    //
    // static std::vector<std::uint8_t> framePacket(const std::vector<std::uint8_t>& payload);
};

#endif //BISTROMATIC_SERIALIZER_HPP
