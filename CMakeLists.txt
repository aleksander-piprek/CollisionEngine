cmake_minimum_required(VERSION 3.15)
project(engine)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SOURCES src/main.cpp
            src/components/engine.cpp)
set(INCLUDES include/engine.hpp)

add_executable(engine ${SOURCES} ${INCLUDES})

target_link_libraries(engine sfml-graphics sfml-audio)