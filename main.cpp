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
	matrix<int> A;
	A = VEC;
	matrix<int> B = A;

	std::vector<int> rowA = A[0];
	print_vector(rowA);
}