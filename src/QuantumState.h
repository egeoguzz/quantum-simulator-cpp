#pragma once
#include <vector>
#include <complex>

class QuantumState {
public:
    QuantumState(int numQubits);
    void applySingleQubitGate(const std::complex<double> gate[2][2], int target);
    void applyX(int target);
    void applyZ(int target);
    void applyH(int target);
    void applyPhase(int target);
    void applyT(int target);
    void applyRZ(int target, double theta);
    void printState() const;
private:
    int numQubits_;
    std::vector<std::complex<double>> state_;
};
