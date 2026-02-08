/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** PacketQueue
*/

#include "PacketQueue.hpp"

PacketQueue& PacketQueue::getInstance()
{
    static PacketQueue instance;
    return instance;
}

void PacketQueue::push(std::unique_ptr<Packet> pkt)
{
    std::lock_guard lock(_mutex);
    _queue.push(std::move(pkt));
}

std::vector<std::unique_ptr<Packet>> PacketQueue::popAll()
{
    std::lock_guard lock(_mutex);
    std::vector<std::unique_ptr<Packet>> packets;
    while (!_queue.empty()) {
        packets.push_back(std::move(_queue.front()));
        _queue.pop();
    }
    return packets;
}
