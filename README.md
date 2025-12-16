# Quantum Simulator in C++

A lightweight quantum circuit simulator implemented in modern C++.
This project focuses on the practical, systems-level mechanics behind quantum
computing rather than relying on high-level libraries or black-box abstractions.

The goal is to demonstrate how core quantum concepts such as superposition,
entanglement, and measurement are represented and executed at the state-vector level.

---

## Features

- State-vector based quantum simulation
- Single-qubit gates: X, H, Z, S, T, RZ
- Two-qubit gate: CNOT (entanglement)
- High-level 'QuantumCircuit' API
- Text-based DSL for defining quantum circuits
- Probabilistic measurement with state collapse
- Example circuits (Bell state, quantum teleportation)

---

## Architecture Overview

- **QuantumState**  
  Owns and manipulates the complex state vector, implements gate application,
  normalization checks, and probabilistic measurement.

- **Gate**  
  Lightweight data structure representing quantum gate operations.

- **QuantumCircuit**  
  High-level circuit builder that stores gate sequences and executes them
  on a quantum state.

- **DSLParser**  
  Parses simple text-based circuit definitions and maps them to circuit operations.

- **Examples**  
  Small demo circuits that showcase key quantum behaviors.

---

## Build & Run

```bash
mkdir build
cd build
cmake ..
make
./quantum_simulator
Run the binary from the repository root if using DSL examples:

bash
./build/quantum_simulator

DSL Format
Example circuit definition:

txt

H 0
CX 0 1
RZ 1 1.57
Supported operations:

H q
X q
RZ q theta
CX control target

Lines starting with # are treated as comments.

Example Circuits
Bell State
Demonstrates superposition and entanglement. Measurement collapses to |00> or |11> with approximately equal probability.

Quantum Teleportation (simplified)
Demonstrates multi-qubit interaction and measurement-based state collapse.
Classical feed-forward is intentionally omitted for simplicity.

Why This Project
This simulator was built as a hands-on exploration of quantum computing fundamentals
from a software engineering perspective. It emphasizes clarity, correctness, and
clean abstractions over performance or large-scale simulation.

Future Improvements
Partial qubit measurement

Classical feed-forward logic for teleportation

Noise and decoherence models

Performance optimizations for larger qubit counts

Note: This project is intended for educational and experimental use.
