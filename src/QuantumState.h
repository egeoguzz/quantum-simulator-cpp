#pragma once
#include <vector>
#include <complex>

class QuantumState {
public:
    QuantumState(int numQubits);
private:
    int numQubits_;
    std::vector<std::complex<double>> state_;
};
