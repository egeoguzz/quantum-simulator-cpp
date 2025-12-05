#include <iostream>
#include "QuantumState.h"
#include <complex>
#include <cmath>

int main() {
    QuantumState qs(1);

    double invSqrt2 = 1.0 / std::sqrt(2);
    std::complex<double> H[2][2] = {
        {invSqrt2, invSqrt2},
        {invSqrt2, -invSqrt2}
    };

    qs.applySingleQubitGate(H, 0);
    qs.printState();

    return 0;
}

