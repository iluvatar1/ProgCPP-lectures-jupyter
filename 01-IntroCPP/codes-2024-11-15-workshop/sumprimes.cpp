#include <iostream>
#include <cmath>

// declaration
bool isprime(long num);

int main(void)
{
    long suma = 0;
    for (long ii = 500; ii <= 1234; ii = ii + 1){
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

