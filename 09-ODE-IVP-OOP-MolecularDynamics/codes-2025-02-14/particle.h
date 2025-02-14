// particle.h
#pragma once
#include <iostream>
#include <valarray>
#include <fstream>

struct Particle {
    std::valarray<double> R{0.0, 0.0, 0.0}, V{0.0, 0.0, 0.0}, F{0.0, 0.0, 0.0};
    double mass{0}, rad{0};
    void print(void);
    void print_csv(std::ofstream & fout) const;
};