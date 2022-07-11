#include<iostream>
#include<vector>
#include"linalg.h"

void print_vector(const std::vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		std::cout << A[i] << std::endl;
	}
}
int main() {
	std::vector<std::vector<int>> VEC = { {1, 2}, { 3,4 }};
	linalg::vector<int> v = { 1,2,3,4 };
	linalg::vector<linalg::vector<int>> mat = { {1,2},{2,3} };
	std::cout << mat[1][1] << std::endl;
	//mat.print();
	/*
	linalg::matrix<int> A;
	A = VEC;
	linalg::matrix<int> B = A;
	linalg::matrix<int> C = A *B;
	C.print();

	std::vector<int> v1 = { 1,2,3,4 };
	linalg::vector<int> vec = v1;
	vec[2] = 16;
	vec.print();
	*/
}