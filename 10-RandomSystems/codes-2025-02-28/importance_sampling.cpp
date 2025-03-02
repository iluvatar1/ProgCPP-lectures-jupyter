#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <cmath>

void check_args(int argc, char **argv);
void importance_sampling0(const int seed, const int nsamples);
void importance_sampling1(const int seed, const int nsamples);
void importance_sampling2(const int seed, const int nsamples);

int main(int argc, char **argv)
{
    check_args(argc, argv);

    const int SEED = std::stoi(argv[1]);
    const int SAMPLES = std::stoi(argv[2]);

    importance_sampling0(SEED, SAMPLES);
    importance_sampling1(SEED, SAMPLES);
    importance_sampling2(SEED, SAMPLES);

    return 0;
}

void check_args(int argc, char **argv)
{
    if (3 != argc) {
        std::cerr << "Error. Usage: \n" << argv[0] << " SEED SAMPLES\n";
        exit(1);
    }
}

void importance_sampling0(const int seed, int const nsamples)
{
    // TODO
    // define aux random number generators
    std::mt19937 gen(seed); // random bit generator
    std::exponential_distribution<double> w(1.0); // first weight function to test
    auto h  = [](double x){ return x*x; }; // its integrand
    double sum = 0.0, sum_2 = 0.0;
    for (int ii = 0; ii < nsamples; ++ii) {
        double x = w(gen); // generate a random number
        double val = h(x); // evaluate the integrand
        sum += val; // accumulate the sum
        sum_2 += val*val; // accumulate the sum
    }
    double mean = sum / nsamples; // compute the mean
    double var = sum_2 / nsamples - mean * mean; // compute the variance
    double sigma = std::sqrt(var/(nsamples-1)); // compute the standard deviation
    double rel_err = std::fabs(1.0 - mean/2.0);
    std::printf("%20.16e +- %20.16e\t%20.16e\n", mean, sigma, rel_err);

//=== BEGIN MARK SCHEME ===
//=== END MARK SCHEME ===
}

void importance_sampling1(const int seed, int const nsamples)
{
    // TODO
    // define aux random number generators
    std::mt19937 gen(seed); // random bit generator
//=== BEGIN MARK SCHEME ===
    std::gamma_distribution<double> w(2.0, 1.0); // weight function
    auto h  = [](double x){ return x; }; // its integrand
    double sum = 0.0, sum_2 = 0.0;
    for (int ii = 0; ii < nsamples; ++ii) {
        double x = w(gen); // generate a random number
        double val = h(x); // evaluate the integrand
        sum += val; // accumulate the sum
        sum_2 += val*val; // accumulate the sum
    }
    double mean = sum / nsamples; // compute the mean
    double var = sum_2 / nsamples - mean * mean; // compute the variance
    double sigma = std::sqrt(var/(nsamples-1)); // compute the standard deviation
    double rel_err = std::fabs(1.0 - mean/2.0);
    std::printf("%20.16e +- %20.16e\t%20.16e\n", mean, sigma, rel_err);

//=== END MARK SCHEME ===
}


void importance_sampling2(const int seed, int const nsamples)
{
    // TODO
    // define aux random number generators
    std::mt19937 gen(seed); // random bit generator
//=== BEGIN MARK SCHEME ===
    std::gamma_distribution<double> w(3.0, 1.0); // weight function
    auto h  = [](double x){ return 1.0; }; // its integrand
    double sum = 0.0, sum_2 = 0.0;
    for (int ii = 0; ii < nsamples; ++ii) {
        double x = w(gen); // generate a random number
        double val = h(x)*2; // evaluate the integrand, add w normalization
        sum += val; // accumulate the sum
        sum_2 += val*val; // accumulate the sum
    }
    double mean = sum / nsamples; // compute the mean
    double var = sum_2 / nsamples - mean * mean; // compute the variance
    double sigma = std::sqrt(var/(nsamples-1)); // compute the standard deviation
    double rel_err = std::fabs(1.0 - mean/2.0);
    std::printf("%20.16e +- %20.16e\t%20.16e\n", mean, sigma, rel_err);

//=== END MARK SCHEME ===
}