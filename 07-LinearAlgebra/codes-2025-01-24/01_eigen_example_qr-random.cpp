# include <iostream>
# include <eigen3/Eigen/Dense>
# include <string>

int main(int argc , char **argv)
{
   int N = std::stoi(argv[1]); 
   //Eigen::internal::setRandomSeed(0);
   //std::srand48(0);
   Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N); // random values \in [-1, 1]
   Eigen::VectorXd b = Eigen::VectorXd::Random(N);
   //std::cout.precision(16);
   //std::cout.setf(std::ios::scientific);
   
   //A << 1,2,3,  4,5,6,  7,8,10;
   //b << 3, 3, 4;
   //std::cout << "Here is the matrix A:\n" << A << std::endl;
   //std::cout << "Here is the vector b:\n" << b << std::endl;
   //Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
   Eigen::VectorXd x = A.fullPivLu().solve(b);
   //std::cout << "The solution is:\n" << x << std::endl;
   std::cout << (A*x - b).norm() << "\n";
   return 0;
}