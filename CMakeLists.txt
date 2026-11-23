cmake_minimum_required(VERSION 3.16)
project(text-humanizer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(texthumanizer
    src/main.cpp
    src/humanizer.cpp
    src/patterns.cpp
    src/paraphrase.cpp
)

target_include_directories(texthumanizer PRIVATE include)

if(WIN32)
    target_link_libraries(texthumanizer PRIVATE userenv)
endif()
