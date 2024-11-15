#include <iostream>
#include <cmath>
#include <string>

// declaration
bool isprime(long num);

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "ERROR. Program should be called as:\n";
        std::cerr << argv[0] << " min max\n";
        std::cerr << "min : minimum value\n";
        std::cerr << "max : maximum value\n";
        return 1;
    }

    long vmin = std::stol(argv[1]);
    long vmax = std::stol(argv[2]);
    long suma = 0;
    for (long ii = vmin; ii <= vmax; ii = ii + 1){
        if (isprime(ii) == true) {
            suma = suma + ii;
        }
    }
    std::cout << suma << "\n";

    return 0;
}

bool isprime(long num)
{
    if (num <= 1) {
        return false;
    }
    if (num > 2 and num%2==0) {
      return false;
    }
    // buscar si tiene algun divisor
    //for (long ii = 2; ii <= num - 1; ii = ii + 1) // very slow
    for (long ii = 3; ii <= std::sqrt(num)+1; ii = ii + 2) // very fast
    {
        if (num%ii == 0) {
            return false;
        }
    }
    return true; 
}

