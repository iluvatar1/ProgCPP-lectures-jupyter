#pragma once
#include <valarray>
#include <iostream>

class Boundary{
  double RMAX_{0.0}, EN_{0.0}; // RMAX is the radius of the sphere, EN is the coefficient of restitution
  std::valarray<double> C_{0.0, 0.0, 0.0}; // Center

  public:
    Boundary(double RMAX, double CX, double CY, double CZ, double EN) {
      RMAX_ = RMAX;
      C_[0] = CX;
      C_[1] = CY;
      C_[2] = CZ;
      EN_ = EN;
    }

    template <class particle_array_t>
    void apply(particle_array_t & parray) {
      // applySphericalConstraint
      for (auto & p : parray) {
        double r2 = ((p.R-C_)*(p.R-C_)).sum();
        double r = std::sqrt(r2);
        double delta = r + p.rad - RMAX_;
        if (delta > 0) {
            std::valarray<double> N = (p.R - C_)/r;
            p.R = p.R - delta*N;
            double vn = (p.V*N).sum();
            if (vn > 0) {
                p.V = p.V - (EN_+1)*vn*N;
            }
        }
      }
    }
};