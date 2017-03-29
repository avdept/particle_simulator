cmake_minimum_required(VERSION 3.6)
project(ParticleSimulation)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY libSDL2-2.0.0.dylib)
set(SOURCE_FILES main.cpp Screen.cpp Screen.h)

add_executable(ParticleSimulation ${SOURCE_FILES})
target_link_libraries(ParticleSimulation ${SDL2_LIBRARY})  #this needed to link sdl2 library with executable