#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <cmath>

void check_args(int argc, char **argv);
void generate_samples_needle(const int seed, const int nsamples);

int main(int argc, char **argv)
{
    check_args(argc, argv);

    const int SEED = std::stoi(argv[1]);
    const int SAMPLES = std::stoi(argv[2]);

    generate_samples_needle(SEED, SAMPLES);

    return 0;
}

void check_args(int argc, char **argv)
{
    if (3 != argc) {
        std::cerr << "Error. Usage: \n" << argv[0] << " SEED SAMPLES\n";
        exit(1);
    }
}

void generate_samples_needle(const int seed, int const nsamples)
{
    // TODO
//=== BEGIN MARK SCHEME ===

    // define aux random number generators
    std::mt19937 gen(seed); // random bit generator
    std::uniform_real_distribution<double> ug(0.0, 0.5); // random number distribution
    std::uniform_real_distribution<double> vg(0.0, M_PI/2); // random number distribution

    // generate samples and choose the right face
    int count = 0;
    for (int ii = 0; ii < nsamples; ++ii) {
        double u = ug(gen); // generate a random number
        double v = vg(gen); // generate a random number

        // check intersection
        if (2*u < std::sin(v)) {
            count++;
        }
    }
    std::cout << "count : " << count << std::endl;

    // write the data
    std::printf("%20.16e\t%20.16e\t%20.16e\n", 1.0*count/nsamples, 2/M_PI, 2.0*nsamples/count);

//=== END MARK SCHEME ===
}