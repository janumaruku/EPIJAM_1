/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** PlayerConnectionEvent
*/

#ifndef EPIJAM_1_PLAYERCONNECTIONEVENT_HPP
#define EPIJAM_1_PLAYERCONNECTIONEVENT_HPP

#include "IPlayerEvent.hpp"
#include "PlayerEventFactory.hpp"

class PlayerConnectionEvent : public IPlayerEvent {
public:
    PlayerConnectionEvent() = default;

    ~PlayerConnectionEvent() override = default;

    void operator()(Core& core, std::shared_ptr<ClientSession> client) override;
};

REGISTER_COMMAND_CREATOR(PlayerConnectionEvent, EventType::CONNECTION_REQUEST,
    PlayerConnectionEvent)

#endif //EPIJAM_1_PLAYERCONNECTIONEVENT_HPP
