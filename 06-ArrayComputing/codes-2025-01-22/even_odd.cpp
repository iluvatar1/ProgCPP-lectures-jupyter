#include <iostream>
#include <valarray>
#include <cmath>

int main()
{
    std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

    for (auto val : v) {
        std::cout << val << "  ";
    }
    std::cout << "\n";
    
    v = v.apply([](int ii){
        if (ii %2 == 0) { return 3*ii; }
        else { return 2*ii; };
    });

    for (auto val : v) {
        std::cout << val << "  ";
    }
    std::cout << "\n";

    return 0;
}
