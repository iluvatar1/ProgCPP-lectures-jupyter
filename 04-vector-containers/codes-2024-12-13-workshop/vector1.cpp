#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>


void check_args(int argc, char **argv);
void fill_randomly(std::vector<double> & vec);
void print_vector(const std::vector<double> & vec);
void histogram(const std::vector<double> & vec, double xmin, double xmax, int nbins);

int main(int argc, char **argv) {
    check_args(argc, argv);
    const int N = std::stoi(argv[1]);

    // set the vector
    std::vector<double> data;
    data.resize(N);

    // fill the vector
    //print_vector(data);
    fill_randomly(data);
    //print_vector(data);

    // histogram
    histogram(data, 0.0, 1.0, 10);

    return 0;
}

void check_args(int argc, char **argv)
{
    // read variables
    if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " N" << std::endl;
    std::cerr << "N: size of the vector" << std::endl;
    std::exit(1);
    }
}

void fill_randomly(std::vector<double> & vec)
{
    // setup the random number generation
    std::mt19937 gen(0); // gen, es un generador de bits aleatorios
    // y 0 es la semilla , para inicializar el estado
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    std::for_each(vec.begin(), vec.end(), [&dis, &gen](double &x){
        x = dis(gen);
    });
}

void print_vector(const std::vector<double> & vec)
{   
    auto print = [](const double & x){std::printf("%20.16e  ", x);};
    for_each(vec.begin(), vec.end(), print);
    std::printf("\n");
}

void histogram(const std::vector<double> & vec, double xmin, double xmax, int nbins)
{
    std::vector<double> histo(nbins, 0.0);
    double dx = (xmax-xmin)/nbins;
    for (auto & x : vec) {
        // calcular el bin en el que cae
        int bin = int((x - xmin)/dx); // TODO chequeo del bin 
        // aumentar el bin
        histo[bin]++;
    }
    print_vector(histo);
}
