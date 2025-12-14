#include "QuantumCircuit.h"
#include "DSLParser.h"
#include <iostream>

int main() {
    QuantumCircuit qc(3);

    // DSLParser::loadFromFile("examples/teleportation.qc", qc);
    DSLParser::loadFromFile("examples/bell.qc", qc);

    int result = qc.measureAll();
    std::cout << "Measured outcome: |" << result << ">\n";
    return 0;
}
