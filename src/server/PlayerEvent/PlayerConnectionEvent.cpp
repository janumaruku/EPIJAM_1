#include <iostream>
#include "PlayerConnectionEvent.hpp"

#include "Packet.hpp"
#include "Serializer.hpp"
#include  "../Serializer/utils.hpp"

void PlayerConnectionEvent::operator()(Core& core,
    const std::shared_ptr<ClientSession> client)
{
    // const auto buffer1 = Serializer::serializeMap(core.getMap());
    // const auto buffer2 = Serializer::framePacket(buffer1);

    Packet packet;

    packet.write(PacketType::CONNECTION_REQUEST);
    packet.write<std::uint8_t>(core.getMap().getEntities().size());

    for(const auto& [type, x, y] : core.getMap().getEntities()) {
        packet.write(static_cast<std::uint8_t>(type));
        packet.write<float>(x);
        packet.write<float>(y);
    }

    client->send(packet);

    std::clog << "[SERVER]: Map sent to player" << std::endl;
}
