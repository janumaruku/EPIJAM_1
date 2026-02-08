#include <iostream>
#include "PlayerConnectionEvent.hpp"

#include "Packet.hpp"
#include "Serializer.hpp"
#include  "../Serializer/utils.hpp"

void PlayerConnectionEvent::operator()(Core& core,
    const std::shared_ptr<ClientSession> client)
{
    const auto buffer1 = Serializer::serializeMap(core.getMap());
    const auto buffer2 = Serializer::framePacket(buffer1);

    client->send(buffer2);

    std::clog << "[SERVER]: Map sent to player" << std::endl;
}
