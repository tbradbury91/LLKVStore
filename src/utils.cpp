#include "utils.h"

Timer::Timer() { reset(); }

void Timer::reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::elapsed() const {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - startTime;
    return diff.count();
}
