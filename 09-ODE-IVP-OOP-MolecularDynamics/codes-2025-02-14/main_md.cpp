//  g++-14 -std=c++17 particle.cpp main_md.cpp
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include <vector>
#include <string>
#include <fstream>


void print_to_csv(const std::vector<Particle> & particles, int istep);

int main(int argc, char **argv) {

  std::vector<Particle> bodies;
  bodies.resize(1); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 100.8767;
  p["DT"] = 0.01;
  p["G"] = -9.81;

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // Boundary conditions
  Boundary bc(2.345, 0.0, 0.0, 0.0, 0.5); // RMAX, CX, CY, CZ, EN

  // initial conditions and properties
  bodies[0].R[2] = 0.987;  // z is upwards, x to the right
  bodies[0].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  bodies[0].V[2] = 0.0; //4.9876; //3.987; // z is upwards, x to the right
  bodies[0].rad  = 0.103;
  bodies[0].mass = 0.337;
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t";
  bodies[0].print();
  std::cout << "\n";
  print_to_csv(bodies, 0);

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
	  bc.apply(bodies);
    double time = p["T0"] + ii*p["DT"];
    std::cout << time << "\t";
    bodies[0].print();
    std::cout << "\n";
    print_to_csv(bodies, ii);
  }

  return 0;
}


void print_to_csv(const std::vector<Particle> & particles, int istep)
{
  // define filename: "0000100.csv"
  std::string fname = std::to_string(istep);
  int nfields = 7; 
  int remaining = nfields - fname.size();
  if (remaining > 0) {
    fname.insert(0, remaining, '0');
  }
  fname = "DISPLAY/" + fname + ".csv";

  // open filestream
  std::ofstream fout(fname);

  // print each particle
  for (const auto & p : particles) {
    p.print_csv(fout);
    fout << "\n";
  }

  // close filestream
  fout.close();
}
