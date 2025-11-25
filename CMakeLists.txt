cmake_minimum_required(VERSION 3.10)
project(quantum_simulator_cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(quantum_simulator
    src/main.cpp
    src/QuantumState.cpp
    src/Gate.cpp
    src/QuantumCircuit.cpp
)
