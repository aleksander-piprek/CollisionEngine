cmake_minimum_required(VERSION 3.15)
project(engine)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(SOURCES src/main.cpp)
set(INCLUDES include/engine.hpp)

add_executable(engine ${SOURCES} ${INCLUDES})

target_include_directories(engine PUBLIC ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

target_link_libraries(engine PUBLIC ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)