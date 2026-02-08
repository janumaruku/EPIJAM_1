//
// Created by kotti on 07/02/2026.
//

#ifndef BISTROMATIC_PLAYEREVENTFACTORY_HPP
#define BISTROMATIC_PLAYEREVENTFACTORY_HPP

#include <functional>
#include <map>
#include <memory>

#include "IPlayerEvent.hpp"
#include "utils.hpp"

class PlayerEventFactory {
    using PlayerEventCreatorFunction = std::function<std::unique_ptr<IPlayerEvent>()>;

public:
    static PlayerEventFactory& get_instance() noexcept;

    static void register_creator(const EventType& key,
        const PlayerEventCreatorFunction& creator);

    static void unregister_creator(const EventType& key);

    static std::unique_ptr<IPlayerEvent> create(const EventType& key);

private:
    using PlayerEventCreatorMap = std::map<EventType, PlayerEventCreatorFunction>;

    PlayerEventFactory() = default;

    ~PlayerEventFactory() = default;

    static PlayerEventCreatorMap& get_map() noexcept;
};

#define REGISTER_COMMAND_CREATOR(name, key, class_name) \
    static bool dummy_##name = []() { \
        PlayerEventFactory::register_creator( \
            key, \
            []() { \
                return std::make_unique<class_name>(); \
            } \
        ); \
        return true; \
    }();

#endif //BISTROMATIC_PLAYEREVENTFACTORY_HPP
