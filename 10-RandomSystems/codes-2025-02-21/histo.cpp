#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <map>

// to store params of different type, ;)
struct param_t
{
    std::string IFNAME;
    double XMIN;
    double XMAX;
    int NBINS;
    std::string OFNAME;
};

// forward declarations
void check_args(int argc, char **argv, param_t &params);
void compute_histogram(const param_t &params);

// main function
int main(int argc, char **argv)
{
    param_t p;
    check_args(argc, argv, p);

    compute_histogram(p);
    return 0;
}

// function definitions

void check_args(int argc, char **argv, param_t & p)
{
    if (6 != argc) {
        std::cerr << "Error. Usage:\n" << argv[0] << " SAMPLES_FNAME XMIN XMAX NBINS HISTO_FNAME\n";
        exit(1);
    }

    p.IFNAME = std::string(argv[1]);
    p.XMIN = std::stod(argv[2]);
    p.XMAX = std::stod(argv[3]);
    p.NBINS = std::atoi(argv[4]);
    p.OFNAME = std::string(argv[5]);
}

void compute_histogram(const param_t & p)
{
    double DX = (p.XMAX - p.XMIN)/p.NBINS;

    std::ifstream fin(p.IFNAME);
    double x;
    int nsamples = 0;
    std::vector<double> histo(p.NBINS, 0.0);
    while (fin >> x) {
        nsamples++;
        int bin = int((x - p.XMIN)/DX); // compute the bin where the sample lies
        if (0 <= bin && bin < p.NBINS) { // check if the bin is included
            histo[bin]++; // increase the counter in that bin
        }
    }
    fin.close();

    // TODO: write the pdf to the output file
    //=== BEGIN MARK SCHEME ===
    
    std::ofstream fout;
    fout.open(p.OFNAME);
    for (int ii = 0; ii < p.NBINS; ii++) {
        fout << p.XMIN + ii*DX << "\t" << histo[ii]/(DX*nsamples) << "\n";
    }
    fout.close();

    //=== END MARK SCHEME ===
}