#include <vector>
#include <iostream>

bool g_InvalidInput = false;
double PowerWithExponent(double base, unsigned int exponent);

double Power(double base, int exponent) {
    g_InvalidInput = false;

    if (base == 0.0 && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)exponent;
    if (exponent < 0)
        absExponent = -absExponent;
    
    double result = PowerWithExponent(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

double PowerWithExponent(double base, unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    
    double result = PowerWithExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;
    
    return result;
}

int main() {
    double base = 2.5;
    int exponent = 5;

    std::cout << "result is " << Power(base, exponent) << std::endl;
    
    return 0;
}