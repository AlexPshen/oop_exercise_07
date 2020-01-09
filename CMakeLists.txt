cmake_minimum_required(VERSION 3.5)

project(oop_exercise_07)

add_executable(oop_exercise_07
               main.cpp
               rectangle.cpp
               trigon.cpp
               quadrate.cpp
               point.cpp
)

set(CMAKE_BUILD_TYPE Debug)
set_property(TARGET oop_exercise_07 PROPERTY CXX_STANDARD 14)
