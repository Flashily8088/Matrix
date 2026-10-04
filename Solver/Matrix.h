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
		size_t rows;
		/**
		* @brief количество столбцов матрицы
		*/
		size_t columns;
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
		Matrix(const size_t n, const size_t m);
		/**
		* @brief диструктор
		*/
		~Matrix();
		/**
		* @brief конструктор копирования
		* @param a - копируемая матрица
		*/
		Matrix(const Matrix& other);
		/**
		* @brief конструктор перемещения
		* @param a - перемещаемая матрица
		*/
		Matrix(Matrix&& other) noexcept;
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
		* @brief оператор перемещающегося пресваивания
		* @param other - перемещаемая матрица
		* @return ссылка на текущую матрицу
		*/
		Matrix& operator =(Matrix&& other);
		/**
		* @brief оператор ==
		* @param m1 - матрица слева
		* @param m2 - матрица справа
		* @return true, если матрицы равны
		*/
		friend bool operator ==(const Matrix& m1, const Matrix& m2);
		/**
		* @brief переопределение оператора []
		* @return строка матрицы
		*/
		int* operator[](const size_t i);
		/**
		* @brief переопределение оператора []
		* @return строка матрицы в виде const
		*/
		const int* operator[](const size_t i) const;
		/**
		* @brief функция получения количеств строк
		* @return количество строк
		*/
		size_t get_rows() const;
		/**
		* @brief функция получения количеств столбцов
		* @return количество столбцов
		*/
		size_t get_columns() const;
		/**
		* @brief заполнение матрицы рандомными числами
		*/
		void fill();
		void fill_random(Generator* g);
		/**
		* @brief удаляет столбец по номеру
		*/
		void delete_comlun(size_t col_index);
	};
}