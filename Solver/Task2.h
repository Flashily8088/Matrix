#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include "Generator.h"
#include <iostream>
using namespace std;
// Удалить столбцы, в которых есть положительный нечётный элемент
namespace miit::algebra {
	class Task2 : public Exercise
	{
	public:
		/**
		* @brief конструкор
		* @param m - матрица
		* @param g - генератор
		*/
		Task2(Matrix* m, Generator* g);
		/**
		* @brief выполняет условия задания 2
		*/
		void solve() override;
	};
}
