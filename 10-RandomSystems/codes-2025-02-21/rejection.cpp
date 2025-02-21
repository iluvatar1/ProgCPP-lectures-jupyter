#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

double f(double x) {
	return 3.0*(1-x*x)/4.0;
}


void rejection(int seed, int nsamples, std::string & fname);


int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <seed> <samples> <filename>\n";
		return 1;
	}

	const int SEED = std::stoi(argv[1]);;
	const int SAMPLES = std::stoi(argv[2]);
	std::string FNAME = argv[3];

	rejection(SEED, SAMPLES, FNAME);

	return 0;
}

void rejection(int seed, int nsamples, std::string & fname)
{
	// TODO
//=== BEGIN MARK SCHEME ===
	std::mt19937 gen(seed);
	std::uniform_real_distribution<double> xu(-1, 1);
	std::uniform_real_distribution<double> yu(0, 3.0/4.0);
	std::ofstream fout(fname);
    int total = 0;
	for (int ii = 0; ii < nsamples; total++) {
		double x = xu(gen);
		double y = yu(gen);
		if (y < f(x)) {
			fout << x << "\n";
            ii++;
		}
	}
    std::cout << "TOTAL TRIED: " << total << "\n";
	fout.close();
//=== END MARK SCHEME ===

}
