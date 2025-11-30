#include "QuantumCircuit.h"

QuantumCircuit::QuantumCircuit(int numQubits)
    : numQubits_(numQubits) {}

void QuantumCircuit::x(int q) {
    gates_.push_back({Gate::X, q});
}

void QuantumCircuit::h(int q) {
    gates_.push_back({Gate::H, q});
}

void QuantumCircuit::rz(int q, double theta) {
    gates_.push_back({Gate::RZ, q, -1, theta});
}

void QuantumCircuit::cx(int control, int target) {
    Gate g;
    g.type = Gate::CX;
    g.control = control;
    g.target = target;
    gates_.push_back(g);
}
