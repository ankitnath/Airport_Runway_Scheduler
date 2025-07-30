// runway states
#pragma once
#include "request.hpp"

enum class RunwayState { IDLE, OCCUPIED };

class Runway {
    RunwayState state;
    int runwayID;

public:
    Runway(int id) : state(RunwayState::IDLE), runwayID(id) {}

    bool isAvailable() const { return state == RunwayState::IDLE; }
    void occupy() { state = RunwayState::OCCUPIED; }
    void release() { state = RunwayState::IDLE; }
    int getID() const { return runwayID; }
};
