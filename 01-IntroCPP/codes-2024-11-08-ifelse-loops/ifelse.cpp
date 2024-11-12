#include <iostream>

void read_check_even_odd(void);

int main(int argc, char **argv)
{
  read_check_even_odd();
  return 0;
}

void read_check_even_odd(void)
{
  int num = 0;

  // solicitar el numero
  std::cout << "Escriba un numero entero, por favor:\n";
  // leer el numero
  std::cin >> num;
  std::cout << std::cin.good() << "\n"; 
  std::cout << num << "\n";
  
  // verificar que el numero es par o no
  // imprimir
  // si el numero es par, imprimir "el numero es par"
  // si no, imprimir "el numero es impar"
  if (num%2 == 0) {
    std::cout << "El numero es par \n";
  }
  if (num%2 != 0) {
    std::cout << "El numero es impar \n";
  }

  //else {
  //cout << "El numero es impar" << endl;
  //}
}