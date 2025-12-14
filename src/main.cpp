#include "QuantumCircuit.h"
#include "DSLParser.h"

int main() {
    QuantumCircuit qc(2);
    DSLParser::loadFromFile("example.qc", qc);
    qc.run();
    return 0;
}

