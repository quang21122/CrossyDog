#pragma once
#include <iostream>
#include <chrono>

class Timer {
    std::chrono::duration<double> duration;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
public:
    Timer(int minutes, int seconds)
        : duration(std::chrono::minutes(minutes) + std::chrono::seconds(seconds)),
        start_time(std::chrono::high_resolution_clock::now()) {}

    // Get the remaining time in minutes and seconds
    void GetRemainingTime(int& remaining_minutes, int& remaining_seconds) {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = now - start_time;
        std::chrono::duration<double> remaining_time = duration - elapsed_seconds;

        remaining_minutes = static_cast<int>(std::chrono::duration_cast<std::chrono::minutes>(remaining_time).count());
        remaining_seconds = static_cast<int>(remaining_time.count()) % 60;
    }

    // Check if the timer has expired
    bool HasExpired() {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = now - start_time;
        return elapsed_seconds >= duration;
    }
};

