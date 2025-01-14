#include <algorithm>
#include <vector>
#include <iostream>

int main(void) {
    std::vector<double> data{1.0, 1.5, 2.0, 2.5};
    
    auto divide = [](double & x){x = x/2;};
    std::for_each(std::begin(data), std::end(data), divide);

    auto print = [](double x){
        std::cout << x << "  ";
        };
    std::for_each(std::begin(data), std::end(data), print);
    std::cout << "\n"; 

    auto print_mem_address = [](double & x){
        std::cout << &x << "  ";
        };
    std::for_each(std::begin(data), std::end(data), print_mem_address);
    std::cout << "\n"; 


    return 0;
}