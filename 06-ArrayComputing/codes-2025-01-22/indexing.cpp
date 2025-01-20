#include <string>
#include <iostream>
#include <valarray>
#include <iomanip>

void print(std::string msg, const std::valarray<int>& v)
{
    std::cout << msg << " ";
    for (int n: v) { std::cout << std::setw(3) << n; }
    std::cout << '\n';
}

int main()
{
    std::valarray<int> v1(3);
    v1 = -1; // (3) from a scalar
    print("assigned from scalar: ", v1);

    v1 = {1, 2, 3, 4, 5, 6}; // (8): from initializer list of different size
    print("assigned from initializer_list:", v1);

    std::valarray<int> v2(3);
    v2 = v1[std::slice(0,3,2)]; // (4): from slice array
    print("every 2nd element starting at pos 0:", v2);

    v2 = v1[v1 % 2 == 0]; // (6): from mask array
    print("values that are even:", v2);

    std::valarray<std::size_t> idx = {0,1,2,4}; // index array
    v2.resize(4); // sizes must match when assigning from gen subscript
    v2 = v1[idx]; // (7): from indirect array
    print("values at positions 0, 1, 2, 4:", v2);

    return 0;
}
