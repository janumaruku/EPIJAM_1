/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** Packet
*/

#ifndef EPIJAM_1_PACKET_HPP
#define EPIJAM_1_PACKET_HPP
#include <cstdint>
#include <cstring>
#include <vector>

class Packet {
public:
    Packet() = default;

    explicit Packet(const std::vector<std::uint8_t> &buffer);

    ~Packet() = default;

    template <typename T>
    T read()
    {
        T value;

        std::memcpy(&value, &_buffer[_offset], sizeof(T));
        _offset += sizeof(T);

        return value;
    }

    template <typename T>
    void write(const T& value)
    {
        std::memcpy(&_buffer[_offset], &value, sizeof(T));
        _offset += sizeof(T);
    }

private:
    std::vector<std::uint8_t> _buffer;
    size_t _offset = 0;
};

#endif //EPIJAM_1_PACKET_HPP