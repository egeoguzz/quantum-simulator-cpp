#include "QuantumState.h"

QuantumState::QuantumState(int numQubits)
    : numQubits_(numQubits),
      state_(1 << numQubits, {0.0, 0.0})
{
    state_[0] = {1.0, 0.0}; // |00...0>
}

void QuantumState::applySingleQubitGate(const std::complex<double> gate[2][2], int target) {
    int dim = state_.size();
    int step = 1 << target;

    std::vector<std::complex<double>> old = state_;

    for (int i = 0; i < dim; ++i) {
        int bit = (i >> target) & 1;
        int base = i & (~step);
        int i0 = base;
        int i1 = base | step;

        if (bit == 0) {
            std::complex<double> a0 = old[i0];
            std::complex<double> a1 = old[i1];

            state_[i0] = gate[0][0] * a0 + gate[0][1] * a1;
            state_[i1] = gate[1][0] * a0 + gate[1][1] * a1;
        }
    }
}

void QuantumState::printState() const {
    double normCheck = 0.0;
    for (const auto& amp : state_) {
        normCheck += std::norm(amp);
    }

    std::cout << "Quantum State (" << numQubits_ << " qubits):\n";
    int dim = state_.size();
    for (int i = 0; i < dim; ++i) {
        auto a = state_[i];
        std::cout << "|" << i << ">: "
                  << a.real()
                  << (a.imag() >= 0 ? "+" : "-")
                  << std::abs(a.imag()) << "i\n";
    }

    if (std::abs(normCheck - 1.0) > 1e-9) {
        std::cout << "Warning: State is not normalized! Norm = "
                  << normCheck << "\n";
    }
}
