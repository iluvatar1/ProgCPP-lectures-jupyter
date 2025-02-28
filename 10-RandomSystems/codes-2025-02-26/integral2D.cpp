#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <string>
#include <vector>


double f(double x, double y); // function to integrate
bool in_region(double x, double y); // check if point is in region
double integral(int seed, int nsamples, std::string fname);

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <seed> <samples> <output file>\n";
        return 1;
    }

    const int SEED = std::atoi(argv[1]);;
    const int SAMPLES = std::atoi(argv[2]);
    std::string fname = argv[3];

    integral(SEED, SAMPLES, fname);

    return 0;
}

double f(double x, double y) {
    return std::sin(std::sqrt(std::log(x+y+1)));
}

bool in_region(double x, double y) {
    // TODO
//=== BEGIN MARK SCHEME ===
    return (((x-0.5)*(x-0.5) + (y-0.5)*(y-0.5)) <= 0.25);
//=== END MARK SCHEME ===
}

double integral(int seed, int nsamples, std::string fname) {
    // TODO
//=== BEGIN MARK SCHEME ===
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> xu(0, 1);
    std::uniform_real_distribution<double> yu(0, 1);
    std::ofstream fout(fname);
    int samples = 0;
    int counter = 0;
    double integral = 0;
    while (samples < nsamples) {
        double x = xu(gen);
        double y = yu(gen);
        if (in_region(x,y)) {
            fout << x << "\t" << y << "\n";
            integral += f(x, y);
            samples++;
        }
        counter++;
    }
    fout.close();
    std::cout << "Actual tries: " << counter << "\n";
    //double result = integral*M_PI/(4*samples);
    double result = (1.0*samples/counter)*integral/samples; 
    std::cout << "Integral: " << result << "\n";
    return result;
//=== END MARK SCHEME ===
}

