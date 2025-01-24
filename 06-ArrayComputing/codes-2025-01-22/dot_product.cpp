#include <iostream>
#include <valarray>
#include <cmath>

int main()
{
    std::valarray<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    std::valarray<int> v2 = {-1,2,3,4,5,6,7,80,-9,10};

    std::cout << (v1*v2).sum() << "\n";

    return 0;
}
