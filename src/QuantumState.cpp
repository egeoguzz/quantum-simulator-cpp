#include "QuantumState.h"
#include <iostream>
#include <cmath>
#include <random>

QuantumState::QuantumState(int numQubits)
    : numQubits_(numQubits),
      state_(1 << numQubits, {0.0, 0.0})
{
    state_[0] = {1.0, 0.0};
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

void QuantumState::applyX(int target) {
    std::complex<double> X[2][2] = {
        {{0,0}, {1,0}},
        {{1,0}, {0,0}}
    };
    applySingleQubitGate(X, target);
}

void QuantumState::applyZ(int target) {
    std::complex<double> Z[2][2] = {
        {{1,0}, {0,0}},
        {{0,0}, {-1,0}}
    };
    applySingleQubitGate(Z, target);
}

void QuantumState::applyH(int target) {
    double invSqrt2 = 1.0 / std::sqrt(2);
    std::complex<double> H[2][2] = {
        {invSqrt2, invSqrt2},
        {invSqrt2, -invSqrt2}
    };
    applySingleQubitGate(H, target);
}

void QuantumState::applyPhase(int target) {
    std::complex<double> S[2][2] = {
        {{1,0}, {0,0}},
        {{0,0}, {0,1}}
    };
    applySingleQubitGate(S, target);
}

void QuantumState::applyT(int target) {
    double pi_4 = M_PI / 4;
    std::complex<double> T[2][2] = {
        {{1,0}, {0,0}},
        {{0,0}, {std::cos(pi_4), std::sin(pi_4)}}
    };
    applySingleQubitGate(T, target);
}

void QuantumState::applyRZ(int target, double theta) {
    std::complex<double> eNeg = {std::cos(-theta/2), std::sin(-theta/2)};
    std::complex<double> ePos = {std::cos(theta/2), std::sin(theta/2)};
    std::complex<double> RZ[2][2] = {
        {eNeg, {0,0}},
        {{0,0}, ePos}
    };
    applySingleQubitGate(RZ, target);
}

void QuantumState::applyCNOT(int control, int target) {
    int dim = state_.size();
    int controlMask = 1 << control;
    int targetMask  = 1 << target;

    std::vector<std::complex<double>> old = state_;

    for (int i = 0; i < dim; ++i) {
        if (i & controlMask) {
            int flipped = i ^ targetMask;
            state_[flipped] = old[i];
        } else {
            state_[i] = old[i];
        }
    }
}

int QuantumState::measureAll() {
    double totalProb = 0.0;
    for (const auto& amp : state_) {
        totalProb += std::norm(amp);
    }

    if (std::abs(totalProb - 1.0) > 1e-9 && totalProb > 0.0) {
        for (auto& amp : state_) {
            amp /= std::sqrt(totalProb);
        }
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    double r = dist(gen);
    double cumulative = 0.0;
    int outcome = 0;

    for (int i = 0; i < (int)state_.size(); ++i) {
        cumulative += std::norm(state_[i]);
        if (r <= cumulative) {
            outcome = i;
            break;
        }
    }

    for (auto& amp : state_) {
        amp = {0.0, 0.0};
    }
    state_[outcome] = {1.0, 0.0};

    return outcome;
}
