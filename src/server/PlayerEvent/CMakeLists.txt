add_library(player_event OBJECT
        ../PlayerEvent/PlayerEventFactory.cpp
        ../PlayerEvent/PlayerEventFactory.hpp
        utils.hpp
        IPlayerEvent.hpp
        PlayerConnectionEvent.cpp
        PlayerConnectionEvent.hpp)

include_directories(. ../Serializer)

target_compile_options(network PUBLIC -Wall -Wextra -Werror)
