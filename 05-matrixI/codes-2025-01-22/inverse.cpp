#include <iostream>
#include <vector>
#include <string>
#include <cassert>
/*
 1 2 3
 0 1 4
 5 6 0

 Inverse:
 -24 18 5
 20 -15 -4
 -5 4 1
 */


void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> &indata, int m, int n,
                      std::vector<double> &outdata);
void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C);
bool check_inverses(const std::vector<double> &A, const std::vector<double> &Ainv,
					int n, double eps);

int main(int argc, char **argv)
{
  //const int M = std::stoi(argv[1]);
  //const int N = std::stoi(argv[2]);

  std::vector<double> A(3*3, 0.0);
  std::vector<double> B(3*3, 0.0);

  //fill_matrix(array2d, M, N);
  //print_matrix(array2d, M, N);
  A[0*3 + 0] = 1; A[0*3 + 1] = 2; A[0*3 + 2] = 3;  
  A[1*3 + 0] = 0; A[1*3 + 1] = 1; A[1*3 + 2] = 4;  
  A[2*3 + 0] = 5; A[2*3 + 1] = 6; A[2*3 + 2] = 0;  

  B[0*3 + 0] = -24; B[0*3 + 1] =  18; B[0*3 + 2] =  4.99999;  
  B[1*3 + 0] =  20; B[1*3 + 1] = -15; B[1*3 + 2] = -4;  
  B[2*3 + 0] =  -5; B[2*3 + 1] =   4; B[2*3 + 2] =  1;  

  std::vector<double> C(3*3, 0.0);
  matmul(A, B, 3, 3, 3, C);
  print_matrix(C, 3, 3);

  //std::vector<double> array2d_T(M*N, 0.0);
  //transpose_matrix(array2d, M, N, array2d_T);
  //print_matrix(array2d_T, N, M);

  std::cout << check_inverses(A, B, 3, 1.0e-6) << "\n";

  return 0;
}

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
    // AT[jj, ii] = A[ii, jj]
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      dataout[jj*m + ii] = datain[ii*n + jj]; // Error here
    }
  }
}

void matmul(const std::vector<double> &A, const std::vector<double> &B, int m,
            int n, int p, std::vector<double> &C)
{
	// check dimensions
	assert(A.size() == m * n);
	assert(B.size() == n * p);
	assert(C.size() == m * p);

	// C = A * B
	for (int ii = 0; ii < m; ++ii) {
		for (int jj = 0; jj < p; ++jj) {
			double result = 0.0;
			for (int kk = 0; kk < n; ++kk) {
				result += A[ii*n + kk] * B[kk*p + jj];
			}
			C[ii*p + jj] = result;
		}
	}
}


bool check_inverses(const std::vector<double> &A,
                    const std::vector<double> &B, int n, double eps)
{
	// one way would be to compute the matmul and then explore, but
	// that would waste storage to save the indentity matrix
	// We can just check the inverse property after each multiplication

	// I == A * B ????
	for (int ii = 0; ii < n; ++ii) {
		for (int jj = 0; jj < n; ++jj) {
			double result = 0.0;
			for (int kk = 0; kk < n; ++kk) {
				result += A[ii*n + kk] * B[kk*n + jj];
			}
			if (ii == jj) { // diagonal element
				if (std::abs(result - 1.0) > eps) {
					return false;
				}
			} else { // off diagonal element
				if (std::abs(result) > eps) {
					return false;
				}
			}
		}
	}
	return true;
}
