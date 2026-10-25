#include "Matrix.h"
#include "Generator.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace miit::algebra {
	Matrix::Matrix() : rows(0), columns(0), matrix() {};

	Matrix::Matrix(const size_t n, const size_t m) : rows(n), columns(m), matrix(n, vector<int>(m, 0))
	{}
	Matrix::Matrix(const Matrix& other)
	{
		rows = other.rows;
		columns = other.columns;
		matrix = other.matrix;
	}
	Matrix::Matrix(Matrix&& other)noexcept
	{
		rows = other.rows;
		columns = other.columns;
		matrix = move(other.matrix);
		other.rows = 0;
		other.columns = 0;
	}
	ostream& operator <<(ostream& os, const Matrix& a) {
		for (size_t i(0); i < a.rows; i++) {
			for (size_t j(0); j < a.columns; j++) {
				os << setw(6) << a.matrix[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	istream& operator>>(istream& is, Matrix& a)
	{
		for (size_t i(0); i < a.rows; i++) {
			for (size_t j(0); j < a.columns; j++) {
				is >> a.matrix[i][j];
			}
		}
		return is;
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		if (this == &other) {
			return *this;
		}
		rows = other.rows;
		columns = other.columns;
		matrix = other.matrix;
		return *this;
	}

	Matrix& Matrix::operator=( Matrix&& other) noexcept
	{
		if (other == *this) return *this;
		rows = other.rows;
		columns = other.columns;
		matrix = move(other.matrix);
		other.rows = 0;
		other.columns = 0;
		return *this;
	}

	vector<int>& Matrix::operator[](const size_t i)
	{
		if (i <= matrix.size()) return matrix[i];
		else cout << "Unavailable index" << endl;
	}

	const vector<int>& Matrix::operator[](const size_t i) const {
		if (i <= sizeof(matrix)) return matrix[i];
		else cout << "Unavalaible index" << endl;
	}

	size_t Matrix::get_rows() const
	{
		return rows;
	}

	size_t Matrix::get_columns() const
	{
		return columns;
	}

	void Matrix::fill(const Generator* g)
	{
		for (size_t i(0); i < rows; i++) {
			for (size_t j(0); j < columns; j++) {
				matrix[i][j] = g->generate();
			}
		}
	}

	void Matrix::delete_comlumn(const size_t col_index)
	{
		if (matrix.empty() || col_index < 0 || col_index >= columns) return;
		for (size_t i(0); i < rows; i++) {
			matrix[i].erase(matrix[i].begin() + col_index);
		}
		columns--;
	}

	bool operator==(const Matrix& m1, const Matrix& m2)
	{
		if (m1.rows == m2.rows && m1.columns == m2.columns) {
			for (size_t i(0); i < m1.rows; i++) {
				for (size_t j(0); j < m1.columns; j++) {
					if (m1.matrix[i][j] != m2.matrix[i][j])
						return false;
				}
			}
			return true;
		}
		return false;
	}
	bool operator!=(const Matrix& m1, const Matrix& m2)
	{
		return !(m1 == m2);
	}
}
