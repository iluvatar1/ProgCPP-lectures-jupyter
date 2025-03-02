#include <iostream>
#include <string>

void printsquare(int n, std::string w);

int main(int argc, char **argv)
{
    int N = std::stoi(argv[1]);
    std::string word = argv[2];

    printsquare(N, word);

    return 0;
}

void printsquare(int n, std::string w)
{
    // primera linea
    for(int ii = 0; ii < n; ii++) {
        std::cout << w;
    }
    std::cout << "\n";

    // lineas intermedias
    // *    *
    for (int nline = 0; nline < n-2; nline++){
        std::cout << w;
        for(int ii = 0; ii < n-2; ii++) {
            std::cout << " ";
        }
        std::cout << w;
        std::cout << "\n";
    }

    // ultima linea
    for(int ii = 0; ii < n; ii++) {
        std::cout << w;
    }
    std::cout << "\n";
}




