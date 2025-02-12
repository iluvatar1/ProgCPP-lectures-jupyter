#include "particle.h"

// particle.cpp
void Particle::print(void) {
    std::cout << mass << "\t" << rad << "\t"
              << R[0] << "\t" << R[1] << "\t" << R[2] << "\t"
              << V[0] << "\t" << V[1] << "\t" << V[2] << "\t"
              << F[0] << "\t" << F[1] << "\t" << F[2] << "\t";
}

// You can also overload the cout operator: friend declared to acces possible private data
// see: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/