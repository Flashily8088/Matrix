#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include "Generator.h"
#include <iostream>
using namespace std;
// Заменить минимальный элемент каждой строки нулём
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

