#include <cmath>
#include <cstdlib>
#include <string>

using fptr = double(double);
double trapezoid(const double a, const double b, const int n, fptr myfunc);
double fun(double x);

int main(int argc, char **argv)
{
  const int N = std::stoi(argv[1]);

  // test on regular
  std::printf("%20.16e\n", trapezoid(0.0, 1.0, 10, fun)); // N

  return 0;
}

double fun(double x)
{
  return x*x;
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
