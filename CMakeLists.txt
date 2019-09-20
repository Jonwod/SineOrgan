cmake_minimum_required(VERSION 3.14)
project(SineOrgan)

set(CMAKE_CXX_STANDARD 14)

add_executable(SineOrgan main.cpp Lib/WaveMath.h Interface/OrganInterface.h Base/InstrumentBase.cpp Base/InstrumentBase.h Interface/OutputDeviceInterface.h Concrete/OutputDeviceSDL.cpp Concrete/OutputDeviceSDL.h Concrete/SineOrgan.cpp Concrete/SineOrgan.h)
target_link_libraries(SineOrgan libSDL2.so)