#pragma once
#ifndef LINALG_H
#define LINALG_H
#include<vector>
#include<string>

template<class num_type>
class matrix {

public:
	int row;
	int col;
	std::vector<std::vector<num_type>> mat;

	// Default constructor
	matrix() : row(0), col(0), mat({ {} }) {};

	// Copy constructor
	/*
	matrix(const matrix& A) {
		mat = {};
		std::vector<num_type> col_vec = {};
		for (int i_row = 0; i_row < A.row; i_row++) {
			for (int i_col = 0; i_col < A.col; i_col++) {
				col_vec.push_back(A[i_row][i_col]);
			}
			mat.push_back(col_vec);
			col_vec.clear();
		}
	};
*/
	// Type conversion constructor
	matrix(const std::vector<std::vector<num_type>> A) : mat(A), row(A.size()), col(A[0].size()) {};

	std::vector<int> operator[](int n) {
		return mat[n];
	}

	matrix operator+(const matrix& A) {
		if (this->row != A.row || this->col != A.col) {
			std::cout << "This dimensions of the two matrices do not match." << std::endl;
		}
		matrix result = *this;
		for (int i_row = 0; i_row < this->row; i_row++) {
			for (int i_col = 0; i_col < this->col; i_col++) {
				result.mat[i_row][i_col] = this->mat[i_row][i_col] + A.mat[i_row][i_col];
			}
		}
		return result;
	}
	
};

#endif // ! LINALG_H
