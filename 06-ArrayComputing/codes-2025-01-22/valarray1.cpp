#include <iostream>
#include <valarray>
#include <cmath>

int main()
{
    std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

    double suma = v.sum();

    std::cout << suma << "\n";

    return 0;
}
