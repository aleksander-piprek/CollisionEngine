cmake_minimum_required(VERSION 3.15)
project(engine)

find_package(SFML 2.5 COMPONENTS graphics audio system REQUIRED)

set(SOURCES "main.cpp"
            "src/engine/engine.cpp"
            "src/window/window.cpp"
            "src/sphere/sphere.cpp")

add_executable(engine ${SOURCES} ${INCLUDES})

target_link_libraries(engine sfml-graphics sfml-audio sfml-system)