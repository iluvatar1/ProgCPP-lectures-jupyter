#include <iostream>
#include <string>
#include <cmath>

// declaration
double f(double x); // funcion que voy a derivar
double deriv_forward(double x, double h); 
double deriv_central(double x, double h); 
double fprime(double x);

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    // TODO verificar argc
    double x = std::stod(argv[1]);
    double fp = fprime(x);
    for (double h = 1.0; h >= 1.0e-16; h = h/10.0) {
        double dfx = deriv_forward(x, h);
        double deltaf = std::fabs(1.0 - fp/dfx);
        double dcx = deriv_central(x, h);
        double deltac = std::fabs(1.0 - fp/dcx);

        std::cout << x << "  " << h 
                << "  " << deriv_forward(x, h) << "  " << deltaf 
                << "  " << deriv_central(x, h) << "  " << deltac
                << "\n";
    }    

    return 0;
}

// declaration
double f(double x) {
    return std::sin(x*x);
}

double fprime(double x)
{
    return 2*x*std::cos(x*x); 
}


double deriv_forward(double x, double h)
{
    return (f(x+h) - f(x))/h;
}

double deriv_central(double x, double h)
{
    return (f(x+h) - f(x-h))/(2*h);
}
