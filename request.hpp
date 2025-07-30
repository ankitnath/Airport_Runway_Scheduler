// request.hpp
#pragma once
#include <string>
#include <ctime>

enum class RequestType { LANDING, TAKEOFF };

struct Request {
    int id;
    std::string flightNumber;
    RequestType type;
    int priority;
    std::time_t requestTime;

    bool operator<(const Request& other) const {
        if (priority == other.priority)
            return requestTime > other.requestTime; // FIFO among same priority
        return priority > other.priority; // Lower number = higher priority
    }
};