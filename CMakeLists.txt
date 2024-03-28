cmake_minimum_required(VERSION 3.15)
project(engine)

if (WIN32)
    set(CMAKE_PREFIX_PATH "D:\\Software Engineering\\SFML-2.6.1\\lib\\cmake\\SFML")
endif (WIN32)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SOURCES "src/main.cpp"
            "src/components/engine.cpp"
            "src/components/window.cpp"
            "src/components/workingDirectory.cpp"
            "src/components/sphere.cpp")

set(INCLUDES "include/engine.hpp"
             "include/window.hpp"
             "include/workingDirectory.hpp"
             "include/sphere.hpp")

add_executable(engine ${SOURCES} ${INCLUDES})

target_link_libraries(engine sfml-graphics sfml-audio)