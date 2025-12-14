# Prepare entangled pair between qubit 1 and 2
H 1
CX 1 2

# Prepare state on qubit 0 (|+>)
H 0

# Bell measurement on qubit 0 and 1
CX 0 1
H 0
