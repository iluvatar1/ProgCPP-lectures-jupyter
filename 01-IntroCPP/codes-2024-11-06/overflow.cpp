#include <iostream>
int main(void) {
  // con enteros
  int b = -3000000000;
  std::cout << "b = " << b << "\n";
  int a = -2000000000;
  std::cout << "a = " << a << "\n";
  // con flotantes
  double x = 3000000000;
  std::cout << "x = " << x << "\n";
  x = 3.24e307;
  std::cout << "x = " << x << "\n";
  x = 3.24e310;
  std::cout << "x = " << x << "\n";
  x = 3.24e-310;
  std::cout << "x = " << x << "\n";
  x = 3.24e-326;
  std::cout << "x = " << x << "\n";
  return 0;
}