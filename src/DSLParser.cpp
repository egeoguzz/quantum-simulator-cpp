#include "DSLParser.h"
#include "QuantumCircuit.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void DSLParser::loadFromFile(const std::string& path, QuantumCircuit& qc) {
    std::ifstream in(path);
    if (!in.is_open()) {
        throw std::runtime_error("Could not open DSL file: " + path);
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string op;
        iss >> op;

        if (op == "H") {
            int q; iss >> q;
            qc.h(q);
        } else if (op == "X") {
            int q; iss >> q;
            qc.x(q);
        } else if (op == "RZ") {
            int q; double theta; iss >> q >> theta;
            qc.rz(q, theta);
        } else if (op == "CX") {
            int c, t; iss >> c >> t;
            qc.cx(c, t);
        } else {
            throw std::runtime_error("Unknown operation: " + op);
        }
    }
}
