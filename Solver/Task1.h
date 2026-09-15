#pragma once
#include "Exercise.h"
#include "Matrix.h"
#include "Generator.h"
#include <iostream>
using namespace std;
// «аменить минимальный элемент каждой строки нулЄм
namespace miit::algebra {
	class Task1 : public Exercise
	{
	public:
		/**
		* @brief конструкор
		* @param m - матрица
		* @param g - генератор
		*/
		Task1(Matrix* m, Generator* g);
		/**
		* @brief выполн€ет услови€ задани€ 1
		*/
		void solve() override;
	};
}

