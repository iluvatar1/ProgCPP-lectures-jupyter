#include <iostream>
#include <array>
#include <vector>

int main(void)
{
  std::array<double, 10> data1;
  data1[5] = 9.87;
  data1[0] = -7.8765;
  data1[9] = 1000.343;
  std::cout << data1[11] << "\n";
  for (auto val : data1) {
    std::cout << val << "\n";
  }

  std::vector<double> data2;
  data2.resize(4); // size = 4, capacity 4
  data2[3] = 9.87;
  data2[0] = -7.8765;
  data2[1] = 1000.343;
  std::cout << data2[2] << std::endl;
  for (auto & val : data2) { // reference
    val *= 2; // modify the value
    std::cout << val << "\n";
  }
  data2.resize(5); // size = 5, capacity = 8 (double the initial, to avoid frequent mallocs)
  data2.push_back(0.987); // size = 6, capacity = 8
  data2.push_back(12343.987); // size = 7, capacity = 8
  data2.push_back(-0.000987); // size = 8, capacity = 8
  data2.push_back(3.986544); // size = 9, capacity = 16

 return 0;
}