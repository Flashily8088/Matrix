#include "Matrix.h"
#include "Generator.h"
#include <iostream>
using namespace std;

namespace miit::algebra {
	Matrix::Matrix() : rows(0), columns(0), matrix(nullptr) {};

	Matrix::Matrix(const int n, const int m) : rows(n), columns(m) {
		matrix = new int* [rows];
		for (int i(0); i < rows; i++) {
			matrix[i] = new int[columns];
		}
	}
	Matrix::~Matrix()
	{
		if (matrix != nullptr) {
			for (int i(0); i < rows; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	}
	Matrix::Matrix(const Matrix& a)
	{
		rows = a.rows;
		columns = a.columns;
		for (int i(0); i < rows; i++) {
			for (int j(0); j < columns; j++) {
				matrix[i][j] = a.matrix[i][j];
			}
		}
	}
	ostream& operator <<(ostream& os, const Matrix& a) {
		for (int i(0); i < a.rows; i++) {
			for (int j(0); j < a.columns; j++) {
				os << a.matrix[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	istream& operator>>(istream& is, const Matrix& a)
	{
		for (int i(0); i < a.rows; i++) {
			for (int j(0); j < a.columns; j++) {
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
		if (matrix != nullptr) {
			for (int i(0); i < rows; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		rows = other.rows;
		columns = other.columns;
		matrix = new int* [rows];
		for (int i(0); i < rows; i++) {
			matrix[i] = new int[columns];
			for (int j(0); j < columns; i++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
		return *this;
	}

	int Matrix::get_rows()
	{
		return rows;
	}

	int Matrix::get_columns()
	{
		return columns;
	}


	int Matrix::get_element(int i, int j)
	{
		return matrix[i][j];
	}

	int& Matrix::at(const int i, const int j)
	{
		return matrix[i][j];
	}

	void Matrix::fill_random(Generator* g)
	{
		if (matrix == nullptr || g == nullptr) return;
		for (int i(0); i < rows; i++) {
			for (int j(0); j < columns; j++) {
				matrix[i][j] = g->generate();
			}
		}
	}

	void Matrix::delete_comlun(int col_index)
	{
		if (matrix == nullptr || col_index < 0 || col_index >= columns) return;
		if (columns == 1) {
			for (int i(0); i < rows; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
			matrix = nullptr;
			columns = 0;
			rows = 0;
			return;
		}
		for (int i(0); i < rows; i++) {
			int* new_row = new int[columns - 1];
			int new_j = 0;
			for (int j(0); j < columns; j++) {
				if (j == col_index) {
					continue;
				}
				new_row[new_j] = matrix[i][j];
				new_j++;
			}
			delete[] matrix[i];
			matrix[i] = new_row;
		}
		columns--;
	}

	bool operator==(const Matrix& m1, const Matrix& m2)
	{
		if (m1.rows == m2.rows && m1.columns == m2.columns) {
			for (int i(0); i < m1.rows; i++) {
				for (int j(0); j < m1.columns; j++) {
					if (m1.matrix[i][j] != m2.matrix[i][j])
						return false;
				}
			}
			return true;
		}
		return false;
	}
}
