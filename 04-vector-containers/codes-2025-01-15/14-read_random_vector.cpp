#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
//#include <cstdlib>


void check_args(int argc, char **argv);
void read_data(std::vector<double> & data, std::string fname);
void histogram(const std::vector<double> & vec, double xmin, double xmax, int nbins);

int main(int argc, char **argv) {
    check_args(argc, argv);
    const std::string FNAME = argv[1];

    // set the vector
    std::vector<double> data;

    // read data
    read_data(data, FNAME);
    
    // histogram
    histogram(data, 0.0, 1.0, 10);

    return 0;
}

void check_args(int argc, char **argv)
{
    // read variables
    if (argc != 2) {
      std::cerr << "Usage: " << argv[0] << " fname" << std::endl;
      std::cerr << "fname: File name with the data" << std::endl;
      std::exit(1);
    }
}

void read_data(std::vector<double> & data, std::string fname)
{
  std::ifstream fin(fname);
  double x;
  while (fin.good()) {
    fin >> x;
    data.push_back(x);
  }
  fin.close();
}


void histogram(const std::vector<double> & vec, double xmin, double xmax, int nbins)
{
    std::vector<double> histo(nbins, 0.0);
    double dx = (xmax-xmin)/nbins;
    for (auto & x : vec) {
        // calcular el bin en el que cae
        int bin = int((x - xmin)/dx); // TODO chequeo del bin
        if (bin < 0 or bin >= nbins) {
            continue;
        } 
        // aumentar el bin
        histo[bin]++;
    }

    // print the histogram
    std::ofstream fout("histogram-14.txt");
    fout.precision(16);
    fout.setf(std::ios::scientific);
    for (int ii = 0; ii < nbins; ++ii) {
        double x = xmin + ii*dx;
        fout << x << "\t" << histo[ii] << "\n";
    }
    fout.close();
}
