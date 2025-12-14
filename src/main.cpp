#include <iostream>
#include "QuantumState.h"
#include <complex>
#include <cmath>

int main() {
    QuantumState qs(2);   // 2 qubit: |00>

    qs.applyH(0);         // superposition
    qs.applyCNOT(0, 1);   // entanglement

    qs.printState();
    return 0;
}

