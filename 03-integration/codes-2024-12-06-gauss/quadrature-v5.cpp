#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using fptr = double(double);
using algptr = double(const double, const double, const int, fptr);
double trapezoid(const double a, const double b, const int n, fptr myfunc);
double simpson(const double a, const double b, const int n, fptr myfunc);
double richardson(const double a, const double b, const int n, 
                  const int p, fptr fun, algptr alg);
double gauss2(const double a, const double b, fptr fun);
double gauss5(const double a, const double b, fptr fun);
double fun(double x);


int main(int argc, char **argv)
{
  //const int N = std::stoi(argv[1]);

  std::printf("gauss2: %20.16e\n", gauss2(0.0, 1.0, fun));
  std::printf("gauss5: %20.16e\n", gauss5(0.0, 1.0, fun));
  /*
  for (double x = 0.0; x <= 10.0; x += 0.1) {
    double exact = std::erf(1.0); 
    double trap = trapezoid(0.0, x, N, fun);
    double simp = simpson(0.0, x, N, fun);
    double rtrap = richardson(0.0, x, N, 1, fun, trapezoid);
    double rsimp = richardson(0.0, x, N, 3, fun, simpson);
    double es = std::fabs(1-simp/exact);
    double ers = std::fabs(1-rsimp/exact); 
    std::printf("%20.16e\t%20.16e\t%20.16e\n", x, es, ers);
  }*/

  return 0;
}

double fun(double x)
{
  return std::sin(x*x);
  //return 2*std::exp(-x*x)/std::sqrt(M_PI);
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

double gauss2(const double a, const double b, fptr fun)
{
  const double w0 = 1.0;
  const double w1 = 1.0;
  const double x0 = -1.0/std::sqrt(3);
  const double x1 = -x0;
  const double aux1 = (a+b)/2;
  const double aux2 = (b-a)/2;
  return aux2*(w0*fun(aux2*x0 + aux1) + w1*fun(aux2*x1 + aux1));

}

double gauss5(const double a, const double b, fptr fun)
{
  std::vector<double> w {0.478629, 0.236927, 0.568889, 0.236927, 0.478629};
  std::vector<double> x {-0.538469, -0.90618, 0, +0.90618, +0.538469};
  const double aux1 = (a+b)/2;
  const double aux2 = (b-a)/2;
  double suma = 0.0;
  for (int ii = 0; ii < w.size(); ++ii) {
    suma += w[ii]*fun(aux2*x[ii] + aux1);
  }
  return aux2*suma;

}
