#include "particle.h"

int main(int argc, char **argv)
{
  Particle body1, body2;
  body1.R[0] = 5.6;
  body2.V[2] = -0.98;
  body1.print();
  return 0;
}