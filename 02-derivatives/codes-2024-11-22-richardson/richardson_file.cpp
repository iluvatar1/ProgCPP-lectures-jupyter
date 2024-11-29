#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

// declaration
double f(double x); // funcion que voy a derivar
double deriv_forward(double x, double h); 
double deriv_central(double x, double h); 
double richardson_central(double x, double h, int p); 
double fprime(double x);

int main(int argc, char **argv)
{
    std::ofstream fout("datos.txt");
    fout.precision(16);
    fout.setf(std::ios::scientific);

    // TODO verificar argc
    double x = std::stod(argv[1]);
    double fp = fprime(x);
    for (double h = 1.0; h >= 1.0e-16; h = h/10.0) {
        double dfx = deriv_forward(x, h);
        double deltaf = std::fabs(1.0 - fp/dfx);
        double dcx = deriv_central(x, h);
        double deltac = std::fabs(1.0 - fp/dcx);
        double drcx = richardson_central(x, h, 2);
        double deltarc = std::fabs(1.0 - fp/drcx);

        fout << x << "  " << h 
                << "  " << dfx << "  " << deltaf 
                << "  " << dcx << "  " << deltac
                << "  " << drcx << "  " << deltarc
                << "\n";
    }    

    fout.close();

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

double richardson_central(double x, double h, int p)
{
    double aux = std::pow(2.0, p);
    return (aux*deriv_central(x, h/2) - deriv_central(x, h))/(aux-1);

}

double richardson_forward(double x, double h, int p)
{
    double aux = std::pow(2.0, p);
    return (aux*deriv_forward(x, h/2) - deriv_forward(x, h))/(aux-1);
}
