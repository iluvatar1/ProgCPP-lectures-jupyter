#include <cmath>
#include <cstdlib>
#include <string>

using fptr = double(double);
using algptr = double(const double, const double, const int, fptr);
double trapezoid(const double a, const double b, const int n, fptr myfunc);
double simpson(const double a, const double b, const int n, fptr myfunc);
double richardson(const double a, const double b, const int n, 
                  const int p, fptr fun, algptr alg);
double fun(double x);

int main(int argc, char **argv)
{
  const int N = std::stoi(argv[1]);


  std::printf("exacto: %20.16e\n", std::erf(1.0)); // N
  // test on regular
  std::printf("trapecio: %20.16e\n", trapezoid(0.0, 1.0, N, fun)); // N
  // test on simpson
  std::printf("simpson: %20.16e\n", simpson(0.0, 1.0, N, fun)); // N
  // test on trapecio
  std::printf("richardson trapecio: %20.16e\n", richardson(0.0, 1.0, N, 1, fun, trapezoid)); // N
  std::printf("richardson simpson: %20.16e\n", richardson(0.0, 1.0, N, 3, fun, simpson)); // N

  return 0;
}

double fun(double x)
{
  return 2*std::exp(-x*x)/std::sqrt(M_PI);
}

double trapezoid(const double a, const double b, const int n, fptr myfunc)
{
  const double h = (b-a)/n;
  double sum = 0.5*(myfunc(a) + myfunc(b));
  for(int ii = 1; ii <= n-1; ++ii) { // note limits
    double x = a + ii*h;
    sum += myfunc(x);
  }
  return h*sum;
}

double simpson(const double a, const double b, const int n, fptr myfunc)
{
    int nsteps = n;        
    if (nsteps % 2 != 0) {
        nsteps = nsteps+1;
    }  
    const double h = (b-a)/nsteps;
    double sum = myfunc(a) + myfunc(b);
    double aux = 0.0;
    for(int ii = 1; ii <= nsteps/2; ++ii) { // note limits
        double x = a + (2*ii-1)*h;
        aux += myfunc(x);
    }
    sum += 4*aux;
    aux = 0.0;
    for(int ii = 1; ii <= nsteps/2-1; ++ii) { // note limits
        double x = a + (2*ii)*h;
        aux += myfunc(x);
    }
    sum += 2*aux; 
    return h*sum/3.0;
}

double richardson(const double a, const double b, const int n, 
                  const int p, fptr fun, algptr alg)
{
    double aux = std::pow(2, p);
    double I1 = alg(a, b, n, fun);
    double I2 = alg(a, b, 2*n, fun);
    return (aux*I2 - I1)/(aux-1);
}
