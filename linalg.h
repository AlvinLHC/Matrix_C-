#pragma once
#ifndef LINALG_H
#define LINALG_H
#include<vector>
#include<string>

template<class num_type>
class matrix {
private:
	int row;
	int col;
	num_type** ary;

	num_type** init(int r, int c) {
		num_type** ary = new num_type * [r];
		for (int i_r = 0; i_r < r; i_r++) {
			ary[i_r] = new num_type * [c];
		}
		return ary;
	}
	
public:

	/* --------------------------------------------------------- 
		CONSTRUCTOR
	   ---------------------------------------------------------
	*/

	matrix(int r = 3, int c = 3) : row(r), col(c) {
		ary = init(row, col);
	}

	/* ---------------------------------------------------------
		OPERATOR OVERLOAD
	   ---------------------------------------------------------
	*/
	matrix operator+(const matrix& A) {
		if (this->row != A.row || this->col != A.col) {
			std::cout << "This dimensions of the two matrices do not match." << std::endl;
		}
		matrix result = *this;
		for (int i_row = 0; i_row < this->row; i_row++) {
			for (int i_col = 0; i_col < this->col; i_col++) {
				result.mat[i_row][i_col] += A.mat[i_row][i_col];
			}
		}
		return result;
	}
	
	/* ---------------------------------------------------------
		USEFUL METHODS
	   ---------------------------------------------------------
	*/
	int ROW() { return row; }
	int COL() { return col; }

	// Print out the matrix
	void print() {
		for (int i_row = 0; i_row < row; i_row++) {
			for (int i_col = 0; i_col < col; i_col++) {
				if (i_row == 0 && i_col == 0) {
					std::cout << "[" << ary[i_row][i_col] << ",";
				}
				else if (i_col == 0) {
					std::cout << " " << ary[i_row][i_col] << ",";
				}
				else if (i_col < col - 1) {
					std::cout << ary[i_row][i_col] << ",";
				}
				else if (i_col == col - 1 && i_row < row - 1) {
					std::cout << ary[i_row][i_col] << ";" << std::endl;
				}
				else {
					std::cout << ary[i_row][i_col] << "]" << std::endl;
				}
			}
		}
	}
};

#endif // ! LINALG_H
