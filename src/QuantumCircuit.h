#pragma once
#include <vector>
#include "Gate.h"
#include <string>

class QuantumCircuit {
public:
    QuantumCircuit(int numQubits);
    void x(int q);
    void h(int q);
    void rz(int q, double theta);
    void cx(int control, int target);
    void run();
    int measureAll();
private:
    int numQubits_;
    std::vector<Gate> gates_;
};
