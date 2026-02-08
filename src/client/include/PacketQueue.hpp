//
// Created by kotti on 08/02/2026.
//

#ifndef EPIJAM_1_PACKETQUEUE_HPP
#define EPIJAM_1_PACKETQUEUE_HPP

#include <memory>
#include <queue>
#include <vector>

#include "../../server/Serializer/Packet.hpp"

class PacketQueue {
public:
    PacketQueue(const PacketQueue&) = delete;

    PacketQueue& operator=(const PacketQueue&) = delete;

    static PacketQueue& getInstance();

    // TcpClient pushes ownership into the queue
    void push(std::unique_ptr<Packet> pkt);

    // Core/game pops all packets, taking ownership
    std::vector<std::unique_ptr<Packet>> popAll();

private:
    PacketQueue() = default;

    ~PacketQueue() = default;

    std::mutex _mutex;
    std::queue<std::unique_ptr<Packet>> _queue;
};

#endif //EPIJAM_1_PACKETQUEUE_HPP
