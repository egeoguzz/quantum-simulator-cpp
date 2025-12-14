#include "QuantumCircuit.h"
#include "QuantumState.h"

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

void QuantumCircuit::run() {
    QuantumState state(numQubits_);

    for (const auto& gate : gates_) {
        switch (gate.type) {
            case Gate::X:
                state.applyX(gate.target);
                break;
            case Gate::H:
                state.applyH(gate.target);
                break;
            case Gate::RZ:
                state.applyRZ(gate.target, gate.theta);
                break;
            case Gate::CX:
                state.applyCNOT(gate.control, gate.target);
                break;
        }
    }

    state.printState();
}

int QuantumCircuit::measureAll() {
    QuantumState state(numQubits_);

    for (const auto& gate : gates_) {
        switch (gate.type) {
            case Gate::X:  state.applyX(gate.target); break;
            case Gate::H:  state.applyH(gate.target); break;
            case Gate::RZ: state.applyRZ(gate.target, gate.theta); break;
            case Gate::CX: state.applyCNOT(gate.control, gate.target); break;
        }
    }

    int result = state.measureAll();
    state.printState();
    return result;
}
