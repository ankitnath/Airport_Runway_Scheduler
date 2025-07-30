cmake_minimum_required(VERSION 3.10)
project(AirportRunwaySchedulerQt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(runway_gui
    main.cpp
    scheduler_gui.cpp
)

target_include_directories(runway_gui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(runway_gui Qt5::Widgets)
