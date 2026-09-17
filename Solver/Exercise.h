#pragma once
#include "Matrix.h"
#include "Generator.h"
namespace miit::algebra {
	class Exercise
	{
	protected:
		/**
		* @brief матрица
		*/
		Matrix* matrix;
		/**
		* @brief генератор
		*/
		miit::algebra::Generator* generator;
	public:
		/**
		* @brief конструкор
		* @param m - матрица
		* @param g - генератор
		*/
		Exercise(Matrix* m, Generator* g) : matrix(m), generator(g) {};
		/**
		* @brief диструктор
		*/
		virtual ~Exercise() = default;
		/**
		* @brief виртуальный метод
		*/
		virtual void solve() = 0;
	};
}


