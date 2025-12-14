#include "QuantumCircuit.h"

int main() {
    QuantumCircuit qc(2);
    qc.h(0);
    qc.cx(0, 1);
    qc.run();
    return 0;
}
