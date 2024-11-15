#include <iostream>
#include <cmath>

// declaration
bool isprime(long num);

int main(void)
{
    // test cases
    std::cout << isprime(2) << "\n";
    std::cout << isprime(4) << "\n";
    std::cout << isprime(9) << "\n";
    std::cout << isprime(27) << "\n";
    std::cout << isprime(97) << "\n";
    std::cout << isprime(19999999967) << "\n";
    std::cout << isprime(200000000041) << "\n";

    /*
    for (int ii = 2; ii <= 150; ii = ii +1){
        if (isprime(ii) == true) {
            std::cout << ii << "  ";
        }
    }
    std::cout << "\n";
    */

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

