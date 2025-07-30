# Airport Runway Scheduling Simulator with Qt GUI

This project simulates an airport runway scheduling system in C++ using a priority queue to manage aircraft landings and takeoffs with different priorities. It features a Qt GUI that displays the scheduling process and runway assignments interactively.

## Features
- Priority-based aircraft scheduling (landing/takeoff)
- Multiple runways managed simultaneously
- Real-time visualization with Qt GUI

## Build & Run

One needs to make sure to have Qt and CMake installed:

```bash
mkdir build && cd build
cmake ..
make
./runway_gui
