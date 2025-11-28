#pragma once
#include <complex>

struct Gate {
    enum Type { X, H, RZ, CX };
    Type type;
    int target;
    int control = -1;
    double theta = 0.0;
};
