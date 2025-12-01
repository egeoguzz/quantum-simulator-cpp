#pragma once
#include <vector>
#include <complex>

class QuantumState {
public:
    QuantumState(int numQubits);
    void applySingleQubitGate(const std::complex<double> gate[2][2], int target);
private:
    int numQubits_;
    std::vector<std::complex<double>> state_;
};
