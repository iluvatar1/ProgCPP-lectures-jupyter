#pragma once
#include <map>

class Collider {
  std::map<std::string, double> params; // parameters to compute the forces
  public:
    Collider(const std::map<std::string, double> &PARAMS) { params = PARAMS; }

    template<class particle_array_t>
    void computeForces(particle_array_t & parray) {
      // reset forces
      for (auto & p : parray) {
        p.F = {0,0,0};
      }
      // individual forces
      for (auto & p : parray) {
        // gravity force
        p.F[2] += p.mass*params["G"];

        //TODO: force with floor

      }
    }
};
