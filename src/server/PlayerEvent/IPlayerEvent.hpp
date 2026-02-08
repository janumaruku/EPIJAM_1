/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** PlayerEvent
*/

#ifndef EPIJAM_1_PLAYEREVENT_HPP
#define EPIJAM_1_PLAYEREVENT_HPP
#include "../Core/Core.hpp"
#include "../Network/ClientSession.hpp"

class IPlayerEvent {
public:
    IPlayerEvent() = default;

    virtual ~IPlayerEvent() = default;

    virtual void operator()(Core &core, std::shared_ptr<ClientSession> client) = 0;
};

#endif //EPIJAM_1_PLAYEREVENT_HPP
