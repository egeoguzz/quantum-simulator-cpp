#include "QuantumCircuit.h"
#include <iostream>

int main() {
    QuantumCircuit qc(2);
    qc.h(0);
    qc.cx(0, 1);

    int outcome = qc.measureAll();
    std::cout << "Measured outcome: |" << outcome << ">\n";
    return 0;
}
