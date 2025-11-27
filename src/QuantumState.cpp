#include "QuantumState.h"

QuantumState::QuantumState(int numQubits)
    : numQubits_(numQubits),
      state_(1 << numQubits, {0.0, 0.0})
{
    state_[0] = {1.0, 0.0}; // |00...0>
}
