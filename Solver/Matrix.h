#pragma once
#include <iostream>
#include "Generator.h"
using namespace std;
namespace miit::algebra {
	class Matrix
	{
	private:
		/**
		* @brief количество строк матрицы
		*/
		int rows;
		/**
		* @brief количество столбцов матрицы
		*/
		int columns;
		/**
		* @brief двумерный массив - тело матрицы
		*/
		int** matrix;
	public:
		/**
		* @brief конструктор по умолчанию
		*/
		Matrix();
		/**
		* @brief конструктор
		* @param n - количество строк
		* @param m - количество столбцов
		*/
		Matrix(const int n, const int m);
		/**
		* @brief диструктор
		*/
		~Matrix();
		/**
		* @brief конструктор копирования
		* @param a - матрица
		*/
		Matrix(const Matrix& a);
		/**
		* @brief оператор вывода
		* @param os - поток вывода
		* @param a - матрица
		* @return поток вывода
		*/
		friend ostream& operator <<(ostream& os, const Matrix& a);
		/**
		* @brief оператор вывода
		* @param is - поток ввода
		* @param a - матрица
		* @return поток ввода
		*/
		friend istream& operator >>(istream& is, const Matrix& a);
		/**
		* @brief оператор =
		* @param other - матрица
		* @return матрицу
		*/
		Matrix& operator =(const Matrix& other);
		/**
		* @brief оператор ==
		* @param m1 - матрица слева
		* @param m2 - матрица справа
		* @return true, если матрицы равны
		*/
		friend bool operator ==(const Matrix& m1, const Matrix& m2);
		/**
		* @brief функция получения количеств строк
		* @return количество строк
		*/
		int get_rows() const;
		/**
		* @brief функция получения количеств столбцов
		* @return количество столбцов
		*/
		int get_columns() const;
		/**
		* @brief функция получения элемента  матрицы
		* @return элемент матрицы
		*/
		int get_element(const int i, const int j) const;
		/**
		* @brief функция получения ареса элемента матрицы
		* @return адрес элемента матрицы
		*/
		int& at(const int i, const int j) const;
		/**
		* @brief заполнение матрицы рандомными числами
		*/
		void fill_random(Generator* g);
		/**
		* @brief удаляет столбец по номеру
		*/
		void delete_comlun(int col_index);
	};
}