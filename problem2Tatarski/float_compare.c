#include <math.h>

int float_equal(double a, double b, double epsilon) {
    return fabs(a - b) <= epsilon;
}
