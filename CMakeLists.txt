cmake_minimum_required(VERSION 3.5)
project(gameAI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Actors/Guard/Guard.h
        Actors/BaseGameEntity.h
        Actors/BaseGameEntity.cpp
        Actors/StateMachine.h
        Actors/State.h
        Actors/EntityNames.h
        Actors/location_type.h Actors/Guard/GuardOwnedStates.h Actors/Guard/GuardOwnedStates.cpp)

add_executable(gameAI ${SOURCE_FILES})