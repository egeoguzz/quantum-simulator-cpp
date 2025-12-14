#pragma once
#include <string>

class QuantumCircuit;

class DSLParser {
public:
    static void loadFromFile(const std::string& path, QuantumCircuit& qc);
};
