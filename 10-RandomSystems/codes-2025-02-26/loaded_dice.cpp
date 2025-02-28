#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

void check_args(int argc, char **argv);
void generate_samples_loaded_dice(const int seed, const int nsamples, const std::string & fname);

int main(int argc, char **argv)
{
    check_args(argc, argv);

    const int SEED = std::stoi(argv[1]);
    const int SAMPLES = std::stoi(argv[2]);
    const std::string FNAME = argv[3];
    // MAYBE LOADED PROBS CAN ALSO BE READ

    generate_samples_loaded_dice(SEED, SAMPLES, FNAME);

    return 0;
}

void check_args(int argc, char **argv)
{
    if (4 != argc) {
        std::cerr << "Error. Usage: \n" << argv[0] << " SEED SAMPLES FNAME\n";
        exit(1);
    }
}

void generate_samples_loaded_dice(const int seed, int const nsamples, const std::string & fname)
{
    // TODO
//=== BEGIN MARK SCHEME ===
    // count vector : face_idx 0 is face 1 and so on
    const int NPROBS = 6;
    std::vector<int> counts(NPROBS, 0);

    // define probs
    std::vector<double> probs {0.00, 0.20, 0.14, 0.22, 0.16, 0.17, 0.11};

    // probs partial sums
    std::vector<double> probs_sum(NPROBS+1, 0.0);
    std::partial_sum(probs.begin(), probs.end(), probs_sum.begin());

    // define aux random number generator in [0, 1)
    std::mt19937 gen(seed); // random bit generator
    std::uniform_real_distribution<double> dist(0.0, 1.0); // random number distribution

    // generate samples and choose the right face
    for (int ii = 0; ii < nsamples; ++ii) {
        double r = dist(gen); // generate a random number
        // find the right face
        for (int jj = 0; jj < NPROBS; jj++) {
            if (probs_sum[jj] <= r and r < probs_sum[jj+1]) {
                counts[jj]++;
            }
        }
    }

    // write the data
    std::ofstream fout(fname); // output file
    for (int jj = 0; jj < NPROBS; ++jj) {
        fout << jj+1 << "\t" << 1.0*counts[jj]/nsamples << "\n";
    }
    fout.close(); // close the file

//=== END MARK SCHEME ===
}