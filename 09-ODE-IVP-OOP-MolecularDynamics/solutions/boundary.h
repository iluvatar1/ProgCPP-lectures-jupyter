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
        std::valarray<double> RC = p.R - C_;
        double rc2 = (RC * RC).sum();
        double rmaxnew = RMAX_ - p.rad;
        if (rc2 > rmaxnew*rmaxnew) {
          double rc = std::sqrt(rc2);
          double delta = (rc - rmaxnew);
          if (delta > 0.0) {
            std::valarray<double> n = RC / rc;
            p.R = p.R - n * delta;
            double Vn = (p.V * n).sum();
            p.V = p.V - (EN_ + 1)*Vn*n;
          }
        }
      }
    }
};
