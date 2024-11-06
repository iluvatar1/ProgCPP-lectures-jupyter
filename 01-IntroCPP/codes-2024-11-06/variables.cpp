#include <string>
#include <vector>
#include <iostream>

const int a = 98;

int main(void) {
    double x {-9.87e-8};
  
    int b = 2*a +1;
  
    std::cout << x << "\n";
    std::cout << b << "\n";
    

    //a = 3;
    
    std::string name = "William ";
    name = name + "Oquendo"; // name += "Oquendo";
    std::cout << name << "\n";
  
    std::vector<double> data;
    data.resize(10);
    std::cout << data[0] << "\n";

    return 0;
}