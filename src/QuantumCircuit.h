#pragma once
#include <vector>
#include "Gate.h"

class QuantumCircuit {
public:
    QuantumCircuit(int numQubits);
    void x(int q);
    void h(int q);
    void rz(int q, double theta);
    void cx(int control, int target);
private:
    int numQubits_;
    std::vector<Gate> gates_;
};
