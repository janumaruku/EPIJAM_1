/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** CountdownTimer
*/

#include "CountdownTimer.hpp"
#include <iomanip>
#include <sstream>

CountdownTimer::CountdownTimer(std::chrono::seconds duration)
    : _duration(duration), _running(false)
{
}

void CountdownTimer::start()
{
    _startTime = Clock::now();
    _running = true;
}

void CountdownTimer::reset()
{
    start();
}

bool CountdownTimer::isFinished() const
{
    return remaining().count() <= 0;
}

std::chrono::seconds CountdownTimer::remaining() const
{
    if (!_running)
        return _duration;

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
        Clock::now() - _startTime
    );

    auto remaining = _duration - elapsed;
    return remaining.count() > 0 ? remaining : std::chrono::seconds(0);
}

std::string CountdownTimer::remainingAsString() const
{
    auto secs = remaining().count();
    int minutes = static_cast<int>(secs / 60);
    int seconds = static_cast<int>(secs % 60);

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes
        << ":"
        << std::setw(2) << std::setfill('0') << seconds;

    return oss.str();
}
