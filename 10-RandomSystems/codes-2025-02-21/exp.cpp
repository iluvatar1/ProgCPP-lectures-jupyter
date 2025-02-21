#include <iostream>
#include <fstream>
#include <random>
#include <string>

struct param_t {
    int SEED{0};
    int NSAMPLES{0};
    std::string OFNAME;
    double MYLAMBDA{0.0};
};

void check_args(int argc, char **argv);
void generate_samples(param_t &p);

int main(int argc, char **argv)
{
    check_args(argc, argv);
    param_t params; // Store the read params here

    params.SEED = std::stoi(argv[1]);
    params.NSAMPLES = std::stoi(argv[2]);
    params.OFNAME = argv[3];
    params.MYLAMBDA = std::stod(argv[4]);

    generate_samples(params);

    return 0;
}

void check_args(int argc, char **argv)
{
    if (5 != argc) {
        std::cerr << "Error. Usage: \n" << argv[0] << " SEED SAMPLES OUTPUT_FNAME LAMBDA\n";
        exit(1);
    }
}

void generate_samples(param_t &p)
{
    // TODO
//=== BEGIN MARK SCHEME ===
    
    std::mt19937 gen(p.SEED); // random bit generator
    std::uniform_real_distribution<double> dist(0.0, 1.0); // random number distribution
    std::ofstream fout(p.OFNAME); // output file
    for (int ii = 0; ii < p.NSAMPLES; ++ii) {
        double z = dist(gen); // generate a random number
        double x = -std::log(1-z)/p.MYLAMBDA;
        fout << x << "\n"; // write it to the file
    }
    fout.close(); // close the file
    
//=== END MARK SCHEME ===
}

