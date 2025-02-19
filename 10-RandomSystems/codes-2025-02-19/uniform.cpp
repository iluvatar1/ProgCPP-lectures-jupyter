#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <map>

using param_t = std::map<std::string, double> ;

void check_args(int argc, char **argv);
void generate_samples(int seed, int nsamples, param_t &p);

int main(int argc, char **argv)
{
    check_args(argc, argv);
    param_t params; // Store the read params here

    const int SEED = std::stoi(argv[1]);;
    const int SAMPLES = std::stoi(argv[2]);
    params["A"] = std::stod(argv[3]);;
    params["B"] = std::stod(argv[4]);

    generate_samples(SEED, SAMPLES, params);

    return 0;
}

void check_args(int argc, char **argv)
{
    if (5 != argc) {
        std::cerr << "Error. Usage: \n" << argv[0] << " SEED SAMPLES A B\n";
        exit(1);
    }
}

void generate_samples(int seed, int nsamples, param_t &p)
{
    // TODO
//=== BEGIN MARK SCHEME ===
    
    std::mt19937 gen(seed); // random bit generator
    std::uniform_real_distribution<double> dist(p["A"], p["B"]); // random number distribution
    std::ofstream fout("data.txt"); // output file
    for (int ii = 0; ii < nsamples; ++ii) {
        double r = dist(gen); // generate a random number
        fout << r << "\n"; // write it to the file
    }
    fout.close(); // close the file
    
//=== END MARK SCHEME ===
}

