#pragma once
#include "Generator.h"
#include <random>
using namespace std;
namespace miit::algebra
{
	/**
	* @brief
	*/
	class RandomGenerator : public Generator
	{
	private:
		mutable uniform_int_distribution<int> distribution;
		mutable mt19937 generator;
	public:
		/**
		* @brief конструктор
		* @param min - минимальное значаение диапозона
		* @param max - максимальное значение диапозона
		*/
		RandomGenerator(const int min, const int max);
		/**
		* @brief функция генерации случайного числа из диапозона
		*/
		int generate() const override;
	};
}

