#include <iostream>
#include <valarray>
#include <cmath>

int main()
{
    // generar un valarray entre 0 y 2pi, 1000 puntos
    int N = 10;
    double dx = (2*M_PI-0.0)/N;
    std::valarray<double> x(N);
    for (int ii = 0; ii < N; ++ii) {
        x[ii] = 0.0 + ii*dx;
    }
;
    // calcular el sin de ese valrray
    std::valarray<double> y;
    y = std::sin(x);

    // for (auto val : y) {
    //     std::cout << val << "  ";
    // }
    // std::cout << "\n";

    // imprimir los datos de y tales que |sinx| <= 0.5
    std::valarray<double> z;
    z = y[y <= 0.5];
    
    for (auto val : z) {
        std::cout << val << "  ";
    }
    std::cout << "\n";

    return 0;
}
