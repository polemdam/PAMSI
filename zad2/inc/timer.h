#pragma once
#include <chrono>
#include <iostream>

class Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<float> duration;

public:
    void start_measuring();
    void stop_measuring();
    void print_duration();
};

void Timer::start_measuring()
{
     start = std::chrono::steady_clock::now();
}
void Timer::stop_measuring()
{
    stop = std::chrono::steady_clock::now();
}

void Timer::print_duration()
{
    duration = stop - start;
    std::cout << "duration = " << duration.count() << std::endl;
}
