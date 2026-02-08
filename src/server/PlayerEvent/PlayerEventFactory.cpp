/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** PlayerEventFactory
*/

#include <stdexcept>

#include "PlayerEventFactory.hpp"

PlayerEventFactory& PlayerEventFactory::get_instance() noexcept
{
    static PlayerEventFactory instance;
    return instance;
}

void PlayerEventFactory::register_creator(const EventType& key,
const PlayerEventCreatorFunction& creator)
{
    get_map()[key] = creator;
}

void PlayerEventFactory::unregister_creator(const EventType& key)
{
    get_map().erase(key);
}

std::unique_ptr<IPlayerEvent> PlayerEventFactory::create(const EventType& key)
{
    auto& map     = get_map();
    const auto it = map.find(key);

    if (it == map.end()) {
        throw std::out_of_range(
            "PlayerEventFactory: no creator registered for given key");
    }
    return (it->second)();
}

PlayerEventFactory::PlayerEventCreatorMap& PlayerEventFactory::get_map() noexcept
{
    static PlayerEventCreatorMap map;
    return map;
}
