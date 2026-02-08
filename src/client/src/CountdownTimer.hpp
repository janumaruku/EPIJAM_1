/*
** EPITECH PROJECT, 2026
** epijam_1
** File description:
** CountdownTimer
*/

#ifndef EPIJAM_1_COUNTDOWNTIMER_HPP
#define EPIJAM_1_COUNTDOWNTIMER_HPP

#include <chrono>
#include <string>

class CountdownTimer {
public:
    using Clock = std::chrono::steady_clock;

    explicit CountdownTimer(std::chrono::seconds duration);

    void start();

    void reset();

    bool isFinished() const;

    std::chrono::seconds remaining() const;

    std::string remainingAsString() const;

private:
    std::chrono::seconds _duration;
    Clock::time_point _startTime;
    bool _running;
};

#endif //EPIJAM_1_COUNTDOWNTIMER_HPP
