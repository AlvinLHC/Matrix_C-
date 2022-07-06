#pragma once
#ifndef LINALG_H
#define LINALG_H
#include<vector>
#include<string>

namespace linalg {
	template<class num_type>
	class vector {
	private:
		std::vector<int> vec;
		int dim;

	public:
		// Constructors
		vector<num_type>() {}; // default constructor
		vector<num_type>(const std::vector<num_type>& v) : vec(v), dim(v.size()) {}; // type-conversion
		vector<num_type>(const vector<num_type>& v) : vec(v.vec), dim(v.size()) {};

		// operator overloads
		vector<num_type> operator+ (const vector<num_type>& v) {
			if (dim != v.size()) {
				std::cout << "Lengths of the two vectors do no match." << std::endl;
			}
			vector<num_type> result = (*this);
			for (int i = 0; i < dim; i++) {
				result.vec[i] += v[i];
			}
			return result;
		}

		vector<num_type> operator- (const vector<num_type>& v) {
			if (dim != v.size()) {
				std::cout << "Lengths of the two vectors do no match." << std::endl;
			}
			vector<num_type> result = (*this);
			for (int i = 0; i < dim; i++) {
				result.vec[i] -= v[i];
			}
			return result;
		}

		vector<num_type> operator* (const vector<num_type>& v) {
			if (dim != v.size()) {
				std::cout << "Lengths of the two vectors do no match." << std::endl;
			}
			vector<num_type> result = (*this);
			for (int i = 0; i < dim; i++) {
				result.vec[i] *= v[i];
			}
			return result;
		}

		num_type& operator[](int n) {
			return (*this).vec[n];
		}

		// Other functions
		void push_back(num_type val) {
			vec.push_back(val);
		}
		int size() const { return dim; }
		void print() const {
			for (int i = 0; i < dim; i++) {
				if (i == 0) {
					std::cout << "[" << vec[i] << ",";
				}
				else if (i < dim - 1) {
					std::cout << vec[i] << ",";
				}
				else {
					std::cout << vec[i] << "]" << std::endl;
				}
			}
		}
	};

	/*===================================================================================
		MATRIX
	  ===================================================================================
	*/
	template<class num_type>
	class matrix {
	private:
		int row;
		int col;
		vector<vector<num_type>> ary;

		vector<vector<num_type>> init(int r, int c) {
			return {};
		}
	public:

		/* ---------------------------------------------------------
			CONSTRUCTOR
		   ---------------------------------------------------------
		*/

		// Default constructor
		matrix(int r = 3, int c = 3) : row(r), col(c) {
			ary = {};
		}

		// Copy constructor
		template<typename = num_type>
		matrix(const matrix<num_type>& mat) {
			row = mat.row;
			col = mat.col;
		}
		// Type-Conversion constructor

		matrix(const std::vector<std::vector<num_type>>& V) {
			row = V.size();
			col = V.size();
			ary = init(row, col);
			for (int i_row = 0; i_row < row; i_row++) {
				for (int i_col = 0; i_col < col; i_col++) {
					ary[i_row][i_col] = V[i_row][i_col];
				}
			}
		}

		matrix(const vector<vector<num_type>>& V) {
			row = V.size();
			col = V.size();
			ary = init(row, col);
			for (int i_row = 0; i_row < row; i_row++) {
				for (int i_col = 0; i_col < col; i_col++) {
					ary[i_row][i_col] = V[i_row][i_col];
				}
			}
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
					result.ary[i_row][i_col] += A.ary[i_row][i_col];
				}
			}
			return result;
		}

		matrix operator-(const matrix& A) {
			if (this->row != A.row || this->col != A.col) {
				std::cout << "This dimensions of the two matrices do not match." << std::endl;
			}
			matrix result = *this;
			for (int i_row = 0; i_row < this->row; i_row++) {
				for (int i_col = 0; i_col < this->col; i_col++) {
					result.ary[i_row][i_col] -= A.ary[i_row][i_col];
				}
			}
			return result;
		}

		matrix operator *(const matrix& A) {
			if (this->col != A.row) {
				std::cout << "The row dimension of the first matrix is different from the column dimension of the second matrix." << std::endl;
			}

			matrix<num_type> result(this->row, A.col);
			for (int i_row = 0; i_row < this->row; i_row++) {
				for (int i_col = 0; i_col < A.col; i_col++) {
					result.ary[i_row][i_col] = 0;
					for (int j = 0; j < this->col; j++) {
						result.ary[i_row][i_col] += (*this).ary[i_row][j] * A.ary[j][i_col];
					}
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
}
#endif // ! LINALG_H
