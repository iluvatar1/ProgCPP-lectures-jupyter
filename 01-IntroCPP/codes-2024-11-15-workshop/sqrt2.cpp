#include <iostream>
#include <string>

void compute_root(int N);

int main(int argc, char **argv) {
    int niter = std::stoi(argv[1]);

    compute_root(niter);

    return 0;
}

void compute_root(int N)
{
    double x = 1.0;
    int iter = 1;
    while(iter <= N) {
        x = (x + 2.0/x)/2.0;
        iter++;
    }   
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << x << "\n";
}
